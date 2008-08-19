/*
 * TFTP library 
 * copyright (c) 2004 Vanden Berghen Frank  
 *
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1 as published by the Free Software Foundation
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 */
 
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <syslog.h>
#include <stdio.h>   
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
//#include <stropts.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h> 
#include <sutil.h>
#include <signal.h>
#include <bsp.h>

#include <nvram.h>
#include <shvar.h>
#include "tftp.h"

#define HWID_LEN                             24
#define sys_reboot() kill(1, SIGTERM)
#ifdef AR9100
#define ART_FILE              "var/firm/art.out"
#define ART_OFFSET	       0x728e0
static char ART_CONFIRM[]={0x41,0x43,0x49,0x20,0x24,0x49,0x64,0x3A,0x20,0x2f,0x2f,0x64,0x65};
#endif

#define lswap(x) ((((x) & 0xff000000) >> 24) | \
                  (((x) & 0x00ff0000) >>  8) | \
                  (((x) & 0x0000ff00) <<  8) | \
                  (((x) & 0x000000ff) << 24))

static unsigned long conver_to_interger(char *src);
static char* remove_tftp_mac_sep(char *p_ori_mac_addr);
static char *add_one_to_macaddr(char mac_addr[]);

int upgrade_firmware(char *p_file_buff, int image_len);


extern int create_socket(int type, int *p_port);
extern int TimeOut, NumberTimeOut;

char* check_mac_scope(char *file_buf)
{
	char *tokenPtr ;
	char *mapping_string ="ffffff";
	char temp[4];
	char macString[20];
	int counter = 5 ;
	memset(temp,0,sizeof(temp));
	memset(macString,0,sizeof(macString));
	tokenPtr = strtok(file_buf,":");
	while(tokenPtr != NULL){
		/*if search the token has the "ffffff" string then cat the substring  ex: file_buf is 00:11:22:33:44:80 ,the '80' of file_buf exceed 128 in the decimal presentation , then it will show  ffffff80 in the hexdecimal presentation */
        	if(strstr(tokenPtr,mapping_string) != NULL){
                	strncpy(temp,strstr(tokenPtr,(tokenPtr+6)),2);
			strcat(macString,temp);
			if(counter > 0)
                        strcat(macString,":");
        	}else{
			strcat(macString,tokenPtr);
			if(counter > 0)
			   strcat(macString,":");		    	
		}
		tokenPtr = strtok(NULL,":");
		counter--;
	}
	return macString;
}
	
/* rc function */
void rc_stop(void) 
{
    _system("rc stop");
    sleep(2);	
    _system("killall rc");
}

/* return 0 if no error.*/
char TFTPswrite(char *p_data,long p_data_amount,char first,void *f)
{
    int result;
    result = fwrite(p_data, p_data_amount,1,(FILE *)f);
    if(result < 0)
        return result;
    else
        return 0;
}

/* return 0 if no error.*/
char TFTPsread(char *p_data,long *p_data_amount,char first,void *f)
{
    *p_data_amount=fread(p_data,1,SEGSIZE,(FILE *)f);
	if(*p_data_amount < 0)
        return *p_data_amount; 
 	else
        return 0;    
}

void nak(int peer,struct sockaddr_in *p_to_addr,int error,char *p_error_msg)
{
	char buf[PKTSIZE];
	int length, status;
	size_t tolen=sizeof(struct sockaddr_in);
	struct tftphdr *p_tftp_pkt=(struct tftphdr *)&buf;

	printf("error mesg: %s \n", p_error_msg);
	p_tftp_pkt->th_opcode = htons((u_short)ERROR);
	p_tftp_pkt->th_code = htons((u_short)error);
	strcpy(p_tftp_pkt->th_msg, p_error_msg);
	length = strlen(p_tftp_pkt->th_msg);
	p_tftp_pkt->th_msg[length] = '\0';
	length += 5;

	status = sendto(peer, buf, length, 0,(struct sockaddr*)p_to_addr, tolen);
	if ( status!= length) 
	{
		printf("send nak failed: %d\n", errno);
	}

}
void tftp_free(void * ptr)
{
    if(ptr)
        free(ptr);
}
int tftp_receive_ext(struct sockaddr_in *p_to_addr,char *p_name,char *p_mode,int InClient,                
                     char (*TFTPwrite)(char *,long ,char,void *),
                     void *argu,int vPKTSIZE)
{
    char *p_data_pkt,*p_ack_pkt,*p_data_buf,*p_copy_buf;
    struct tftphdr *p_tftpdata_pkt,*p_tftpack_pkt;
	unsigned long wan_mac;
	unsigned char *p_wan_mac = &wan_mac;
	char preamble_mac[6] = { 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe};
	char null_mac[6] = {0, 0, 0, 0, 0, 0};
	char macString[20];
	char config_buf[30];
    int result =0 , bytes;
    int size, ntimeout, peer, port_no;
    struct timeval tv;
    u_short nextBlockNumber;
    fd_set lecture;
    struct sockaddr_in from,to=*p_to_addr;
    size_t fromlen=sizeof(from),tolen=fromlen;
    char *file_buffer,*copy_buffer;
    int  image_length = 0;
	 int rc_restart_reqired = 0; //1=reboot 2=rc_restart
	memset(macString,0,sizeof(macString));
    p_data_pkt=(char*)malloc(vPKTSIZE);
    p_ack_pkt=(char*)malloc(vPKTSIZE);
   
    file_buffer=(char*)malloc(FW_BUF_SIZE);
  
    if(p_data_pkt == NULL || p_ack_pkt == NULL || file_buffer == NULL)
    {
        DEBUG_MSG("TFTP: out of memory.\n");
        tftp_free(p_data_pkt); 
        tftp_free(p_ack_pkt); 
       
        tftp_free(file_buffer); 
        return 255;
    }
    printf("TFTP receving..... \n");
    memset(file_buffer, 0, FW_BUF_SIZE);
    memset(p_data_pkt, 0, vPKTSIZE);
    memset(p_ack_pkt, 0, vPKTSIZE);
    copy_buffer = file_buffer;

    p_tftpdata_pkt=(struct tftphdr *)p_data_pkt;				
    p_tftpack_pkt=(struct tftphdr *)p_ack_pkt;			
    p_data_buf=(char*)p_tftpdata_pkt+4;   
    p_copy_buf=(char*)&p_tftpack_pkt->th_stuff[0];	

    port_no = 0;
    if ((peer=create_socket(SOCK_DGRAM, &port_no))<0)
    {
        DEBUG_MSG("create socket failure %d:\n", errno);
        tftp_free(p_data_pkt); 
        tftp_free(p_ack_pkt);
       
        tftp_free(file_buffer); 
        return 255;
    }
          
    if (InClient)
    {
        p_tftpack_pkt->th_opcode=htons((u_short)RRQ);
        strcpy(p_copy_buf, p_name);
        p_copy_buf += strlen(p_name);
        *p_copy_buf++ = '\0';
        strcpy(p_copy_buf, p_mode);
        p_copy_buf += strlen(p_mode);
        *p_copy_buf++ = '\0';
        size=(unsigned long)p_copy_buf-(unsigned long)p_ack_pkt;
    } 
    else 
    {
        p_tftpack_pkt->th_opcode=htons((u_short)ACK);
        p_tftpack_pkt->th_block=0;
        size=4;						
    }
    nextBlockNumber=1;
    
    do 					
    {    
        /*next ACK's timeout */
        ntimeout=0;
        do
        {
            if (ntimeout==NumberTimeOut) 
            { 
                DEBUG_MSG("TFTP timeout");
                close(peer); 
                tftp_free(p_data_pkt); 
                tftp_free(p_ack_pkt);
                tftp_free(file_buffer); 
                return 255;
            }

            if (sendto(peer,p_tftpack_pkt,size,0,(struct sockaddr *)&to,tolen)!=size)
            {
                DEBUG_MSG("tftp: write error : %d", errno);
                close(peer);  
                tftp_free(p_data_pkt); 
                tftp_free(p_ack_pkt);
                tftp_free(file_buffer); 
                return 255;
            }

        do
        {
            bytes = -1;
            FD_ZERO(&lecture);
            FD_SET(peer,&lecture); 
            tv.tv_sec=TimeOut; 
            tv.tv_usec=0;

            if ((result=select(peer+1, &lecture, NULL, NULL, &tv))==-1)  
            {
                DEBUG_MSG("tftp: select error : %d", errno);
                close(peer); 
                tftp_free(p_data_pkt); 
                tftp_free(p_ack_pkt);
                tftp_free(file_buffer); 
                return 255;
            };
            if (result > 0)
            {
                memset(p_tftpdata_pkt, 0, vPKTSIZE);
                bytes = recvfrom(peer, p_tftpdata_pkt, vPKTSIZE, 0,(struct sockaddr *)&from, &fromlen);
            }
        } while ((bytes < 0)&&(result > 0));    //recv nothing but select>0, keep recv

         if (result > 0)
         {
            to.sin_port=from.sin_port; 
            p_tftpdata_pkt->th_opcode = ntohs((u_short)p_tftpdata_pkt->th_opcode);            
            p_tftpdata_pkt->th_block = ntohs((u_short)p_tftpdata_pkt->th_block);
            if (p_tftpdata_pkt->th_opcode != DATA) 
            {
                DEBUG_MSG("tftp: op code is not correct \n");
                close(peer); 
                tftp_free(p_data_pkt); 
                tftp_free(p_ack_pkt);
                tftp_free(file_buffer); 
                return 255;
            }
        
            if (p_tftpdata_pkt->th_block != nextBlockNumber)
            {
               /* Re-synchronize with the other side */
               ioctl(peer, FIONREAD, &bytes); 
               while (bytes)
               {
                  recv(peer, p_tftpdata_pkt, vPKTSIZE, 0);
                  ioctl(peer, FIONREAD, &bytes);
               };
               p_tftpdata_pkt->th_block=nextBlockNumber+1;                  
            }
         }
         ntimeout++;
      } while (p_tftpdata_pkt->th_block!=nextBlockNumber);
       
        p_tftpack_pkt->th_block=htons(nextBlockNumber);
        nextBlockNumber++;

        /*only use in client */
        if (nextBlockNumber==2)
        {
            p_tftpack_pkt->th_opcode=htons((u_short)ACK); 
            size=4;
        }       
        if (bytes-4 > 0)
        {
            memcpy(copy_buffer, p_data_buf, bytes-4);
            memset(p_data_buf, 0, bytes-4);
            copy_buffer = copy_buffer + bytes-4;
            image_length = image_length + bytes-4;
            result =0 ;
        }
 
    } while (bytes == vPKTSIZE);
    printf("TFTP receive successfully \n");
    /* send the "final" ack */
    sendto(peer, p_tftpack_pkt, 4, 0,(struct sockaddr *)&to,tolen);
    

    /* upgrade firmware */
	printf("Image length = %02d \n",image_length);
    
	if(image_length > IMG_LOWER_BOUND && image_length < IMG_UPPER_BOUND) {
		upgrade_firmware(file_buffer, image_length);

	/* check smac command */
	}else if(image_length == FW_CAL_BUF_SIZE)
	{
		printf("F2_to_F1 upgrade\n");
		upgrade_calibration(file_buffer, image_length);
	} else {
        if (memcmp(preamble_mac, file_buffer, 6) == 0)
        {
            if (memcmp(file_buffer+6, null_mac, 6) && (*(file_buffer+6) & 0x1) == 0)
            {
                char *wan_mac_buf;  
                int i;

                sprintf(config_buf, "%02x:%02x:%02x:%02x:%02x:%02x", 
                *(file_buffer + 6), *(file_buffer + 7), *(file_buffer + 8), 
                *(file_buffer + 9), *(file_buffer + 10), *(file_buffer + 11));
				strcpy(macString,check_mac_scope(config_buf));
				memset(config_buf,0,sizeof(config_buf));
				strcpy(config_buf,macString);
                printf("lan_mac = %s\n", config_buf);
                nvram_set("lan_mac", config_buf);
                remove_tftp_mac_sep(config_buf);
                wan_mac_buf = add_one_to_macaddr(config_buf);

                memset(config_buf, 0, 30);
                for(i=0 ; i<6 ; i++)
                {
                    if( i == 5)
                    {
                        sprintf(config_buf+i*3, "%c%c", wan_mac_buf[i*2], wan_mac_buf[i*2+1]);
                        break;
                    }
                    sprintf(config_buf+i*3, "%c%c:", wan_mac_buf[i*2], wan_mac_buf[i*2+1]);
                }

                printf("wan_mac = %s\n", config_buf);
                nvram_set("wan_mac", config_buf);
                if(wan_mac_buf)
                        free(wan_mac_buf);
		printf("*****************************************************setmac1 \n");
                rc_restart_reqired = 2;

            }
            else
            {
                printf("mac addr can not be null & should  start with 00\n");
            }
                    
            if (*(file_buffer+12) != 0)
            {
                	sprintf(config_buf, "0x%02x", *(file_buffer + 12));
                	printf("wlan0_domain = %s\n", config_buf);
                	nvram_set("wlan0_domain", config_buf);
                	printf("*****************************************************setmac2 \n");
                	rc_restart_reqired = 2;
            }

        	nvram_commit();
        }
#ifdef AR9100        
        else /*if(memcmp(file_buffer+ART_OFFSET, ART_CONFIRM, sizeof(ART_CONFIRM)) == 0)*/{
        	printf("run_art_client\n");
        	_system("rc stop");
        	run_art_client(file_buffer, image_length);
	}
#endif
    }

    if(rc_restart_reqired == 1) {
        sys_reboot();
	
    }
	    if(rc_restart_reqired == 2) {
	    printf("*****************************************************rc restart \n");
        _system("rc restart");
    }
	
    close(peer); 
    tftp_free(p_data_pkt); 
    tftp_free(p_ack_pkt);
    return 0;
}
int tftp_receive(struct sockaddr_in *p_to_addr,char *p_name,char *p_mode,int InClient,                
                 char (*TFTPwrite)(char *,long ,char,void *),
                 void *argu)
{
    return tftp_receive_ext(p_to_addr, p_name, p_mode, InClient, TFTPwrite,argu, PKTSIZE);
}
static calCheckId[]={0x35,0x33,0x31,0x31,0x13,0x3e,0x00,0x05,0x41,0x74,0x68,0x65,0x72,0x6f,0x73,0x20};
int upgrade_calibration(char *p_file_buff, int image_len)
{
    int ret,count;
    char mtd_index[15] = {0};
    int  mtd_block;
    char imageHWID[HWID_LEN] = {0};
    char *p_hwid ;
    FILE *fp;

    DEBUG_MSG("Run time Image size is %02d\n", image_len);
    

    /* Hardware ID Check */
    if(memcmp(p_file_buff, &calCheckId[0], sizeof(calCheckId)) != 0)
        printf("calCheckId is correct. \n");
    else
    {
        printf("calCheckId is not correct. \n");

        tftp_free(p_file_buff);
        return -1;
    }
    /* Write to Flash System */
    printf("Write to Flash System\n");
   
    if(ret) {
    	_system("mount -t tmpfs tmpfs /var/firm");
	fp = fopen(FW_UPGRADE_FILE,"w+");
	count = fwrite(p_file_buff,1,image_len,fp);
	printf("write tmp file finish image_length = 0x%x\n",image_len);
	fclose(fp);
    }
   
	/* Kill GPIO and System log procedure */
	_system("killall gpio");
	_system("rmmod gpio");
	_system("killall syslogd");
	_system("killall klogd");
	_system("killall lld2d");
	_system("killall dcc");

    sleep(1);
    _system("/var/sbin/fwupgrade cal &");

    tftp_free(p_file_buff);
 
    return ret;
}


/* upgrade firmware */
int upgrade_firmware(char *p_file_buff, int image_len)
{
    int ret,count;
    char mtd_index[15] = {0};
    int  mtd_block;
    char imageHWID[HWID_LEN] = {0};
    char *p_hwid ;
    FILE *fp;

    DEBUG_MSG("sys_upgrade \n");
    DEBUG_MSG("Run time Image size is %02d\n", image_len);
    

    /* Hardware ID Check */
    p_hwid = p_file_buff + image_len - HWID_LEN;
    DEBUG_MSG("file_buffer now address 0x%x, image_length is %d\n, Hardware ID address 0x%x \n",
                        p_file_buff, image_len, p_hwid);
    printf("Find Match String\n");
    memcpy(imageHWID, p_hwid,HWID_LEN);
    imageHWID[HWID_LEN] = '\0';
    DEBUG_MSG("Image Hardware ID is %s\n",imageHWID);
    DEBUG_MSG("System Hardware ID   %s\n",HWID);
    if( strncmp(p_hwid, HWID, HWID_LEN) == 0)
        printf("HWID is correct. \n");
    else
    {
        printf("HWID is not correct. \n");

        tftp_free(p_file_buff);
        return -1;
    }
    /* Write to Flash System */
    printf("Write to Flash System\n");
   
    if(ret) {
	_system("mount -t tmpfs tmpfs /var/firm");
	fp = fopen(FW_UPGRADE_FILE,"w+");
	count = fwrite(p_file_buff,1,image_len,fp);
	printf("write tmp file finish image_length = 0x%x\n",image_len);
	fclose(fp);
    }
 
	/* Kill GPIO and System log procedure */
	//kill(read_pid(RC_PID), SIGINT); 
	_system("killall gpio");
	_system("rmmod gpio");
	_system("killall syslogd");
	_system("killall klogd");
	_system("killall lld2d");
	_system("killall dcc");

    sleep(1);
    _system("/var/sbin/fwupgrade fw &");

    tftp_free(p_file_buff);

    return ret;
}

int tftp_send_ext(struct sockaddr_in *p_to_addr,char *p_name,char *p_mode,int InClient,
                  char (*TFTPread)(char *,long *,char,void *),                
                  void *argu, int vPKTSIZE)
{
    char *p_data_pkt,*p_ack_pkt,*p_data_buf,*p_copy_buf;
    struct tftphdr *p_tftpdata_pkt,*p_tftpack_pkt;
    int result =0, bytes;
    int size,Oldsize=vPKTSIZE;
    int ntimeout,peer, port_no;
    ushort nextBlockNumber;
    struct timeval tv;
    fd_set lecture;
    struct sockaddr_in from,to=*p_to_addr;
    size_t fromlen=sizeof(from),tolen=fromlen;

    p_data_pkt=(char*)malloc(vPKTSIZE);
    if (p_data_pkt==NULL)
    {
        DEBUG_MSG("TFTP: out of memory.\n");
        return 255;
    }
    p_ack_pkt=(char*)malloc(vPKTSIZE);
    if (p_ack_pkt==NULL)
    {
        DEBUG_MSG("TFTP: out of memory.\n");
        tftp_free(p_data_pkt); return 255;
    }
    p_tftpdata_pkt=(struct tftphdr *)p_data_pkt;
    p_tftpack_pkt=(struct tftphdr *)p_ack_pkt;
    p_data_buf=(char*)&p_tftpdata_pkt->th_data[0];
    p_copy_buf=(char*)&p_tftpdata_pkt->th_stuff[0];

    port_no = 0;
    if ((peer = create_socket(SOCK_DGRAM, &port_no))<0)
    {
        DEBUG_MSG("create socket failure %d:\n", errno);
        tftp_free(p_data_pkt); tftp_free(p_ack_pkt);
        return 255;
    }
    
    if (InClient)
    {
        p_tftpdata_pkt->th_opcode=htons((u_short)WRQ);
        strcpy(p_copy_buf, p_name);
        p_copy_buf += strlen(p_name);
        *p_copy_buf++ = '\0';
        strcpy(p_copy_buf, p_mode);
        p_copy_buf += strlen(p_mode);
        *p_copy_buf++ = '\0';
        size=(unsigned long)p_copy_buf-(unsigned long)p_data_pkt;
        nextBlockNumber=0;
    } 
    else
    {
        p_tftpdata_pkt->th_opcode=htons((u_short)DATA);
        p_tftpdata_pkt->th_block=htons((ushort)1);
        /*The actual size read from file will be returned in "size" */
        if ((*TFTPread)(p_data_buf,(long*)(&size),1,argu)!=0) 
        {   

            DEBUG_MSG("TFTPread error : %d", errno);
            nak(peer, &to, errno,strerror(errno));
            close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt);
            return 255;
        } 
        size+=4;
        nextBlockNumber=1;
    }
    
    do 
    {  
        /*next ACK's timeout */
        ntimeout=0; 
        do
        {
            if (ntimeout==NumberTimeOut) { close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt); return 255;}

            if (sendto(peer,p_tftpdata_pkt,size,0,(struct sockaddr *)&to,tolen)!=size)
            {
                DEBUG_MSG("sendto failure %d", errno);
                close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt);
                return 255;
            }

        do
        {
            bytes = -1;
            FD_ZERO(&lecture);
            FD_SET(peer,&lecture); 
            tv.tv_sec=TimeOut; tv.tv_usec=0;

            if ((result=select(peer+1, &lecture, NULL, NULL, &tv))==-1)
            {
                DEBUG_MSG("tftp: select error : %d", errno);
                close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt);
                return 255;
            }
            if (result >0) bytes = recvfrom(peer, p_tftpack_pkt, vPKTSIZE, 0,(struct sockaddr *)&from, &fromlen);                
        } while ((bytes < 0)&&(result > 0)); //recv nothing but select>0, keep recv

         if (result > 0)
         {
            to.sin_port=from.sin_port;
            p_tftpack_pkt->th_opcode = ntohs((u_short)p_tftpack_pkt->th_opcode);
            p_tftpack_pkt->th_block = ntohs((u_short)p_tftpack_pkt->th_block);
            if (p_tftpack_pkt->th_opcode != ACK) 
            { 
                   DEBUG_MSG("opcode not correct");
                	close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt); 
                	return 255;
            }
            
            if (p_tftpack_pkt->th_block != nextBlockNumber)
            {
               /* Re-synchronize with the other side */
               ioctl(peer, FIONREAD, &bytes); 
               while (bytes)
               {
                  recv(peer, p_tftpack_pkt, vPKTSIZE, 0);
                  ioctl(peer, FIONREAD, &bytes);
               };
               p_tftpack_pkt->th_block=nextBlockNumber+1;  
            }
         }
         ntimeout++;
      } while (p_tftpack_pkt->th_block!=nextBlockNumber);

        if ((size<vPKTSIZE)&&(nextBlockNumber!=0)) break; 

        nextBlockNumber++;
        p_tftpdata_pkt->th_block=htons(nextBlockNumber);		
        
        /*only use in client*/
        if (nextBlockNumber==1)
        {
            p_tftpdata_pkt->th_opcode=htons((u_short)DATA);
            result=(*TFTPread)(p_data_buf,(long*)(&size),1,argu);
        } 
        else 
        {
            Oldsize=size;
            if (Oldsize==vPKTSIZE) result =(*TFTPread)(p_data_buf,(long*)(&size),0,argu);
            else result=0;
        }

        if (result < 0)
        {
            DEBUG_MSG("TFTPread error : %d", errno);
            nak(peer, &from, errno,strerror(errno));
            close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt);
            return result;
        }
        size+=4;
    } while (Oldsize==vPKTSIZE);
    printf("TFTP send successfully \n");
    close(peer); tftp_free(p_data_pkt); tftp_free(p_ack_pkt);
    return 0;
}
int tftp_send(struct sockaddr_in *p_to_addr,char *p_name,char *p_mode,int InClient,
              char (*TFTPread)(char *,long *,char,void *),                
              void *argu)
{
    return tftp_send_ext(p_to_addr, p_name, p_mode, InClient, TFTPread, argu, PKTSIZE);
}

/*  
 *  converts a string containing a hex number(exceeds unsigned long integer range)
 *  into a decimal interger.
 */
static char *add_one_to_macaddr(char mac_addr[])
{
	unsigned long mac_number[3] ={0};
	char *mac_final;
	int i;
	char temp[5];

	mac_final = (char*)malloc(18);
	if(mac_final == NULL)
		return NULL;

	memset(mac_final, 0, 18);
	for(i= 0 ; i<3 ; i++)
	{
		memset(temp, 0, 5);
		memcpy(temp, mac_addr+i*4 , 4);
		mac_number[i] = conver_to_interger(temp);
	}

	mac_number[2] = mac_number[2] + 1 ;
	if((mac_number[2] + 1 ) > 65535)
	{
		mac_number[2] = 0;
		mac_number[1] = mac_number[1] + 1 ;
		if((mac_number[1] + 1 ) > 65535)
		{
			mac_number[1] = 0;
			mac_number[0] = mac_number[0] + 1 ;
			if((mac_number[0] + 1 ) > 65535)
			{
				mac_number[2] = 0;
				mac_number[1] = 0;
				mac_number[0] = 0;
			}
		}
	}

	for(i= 0 ; i<3 ; i++)
		sprintf(mac_final, "%s%04x", mac_final, mac_number[i]);

	return mac_final;
}

/*  
 *  converts a string containing hex number into a decimal interger.
 */
static unsigned long conver_to_interger(char *src)	
{
	unsigned long val =0;
	int base =16;
	unsigned char c;

	c = *src;
	for (;;) 
	{
		if (isdigit(c)) 
		{
			val = (val * base) + (c - '0');
			c = *++src;
		} 
		else if (isxdigit(toupper(c))) 
		{
			val = (val << 4) | (toupper(c) + 10 - 'A');
			c = *++src;
		} 
		else
			break;
	}

	return (val);
}

/* remove mac separator Ex: 11:22:33:44:55:66 => 112233445566 */
static char* remove_tftp_mac_sep(char *p_ori_mac_addr)
{
	int i;
	
	for(i =0 ; i< 5; i++ )
	{
		memmove(p_ori_mac_addr+2+(i*2), p_ori_mac_addr+3+(i*3), 2);
	}
	memset(p_ori_mac_addr+12, 0, strlen(p_ori_mac_addr)-12);
	return p_ori_mac_addr;

}
#ifdef AR9100
int run_art_client(unsigned char *ptr, unsigned int len)
{
    FILE *fp;
    int count;
    int ret;
    if(ret) {
	_system("mount -t tmpfs tmpfs /var/firm");
	fp = fopen(ART_FILE,"w+");
	count = fwrite(ptr,1,len,fp);
	printf("write tmp file finish image_length = 0x%x\n",len);
	fclose(fp);
    }
//    kill(read_pid(RC_PID), SIGINT);
    chmod(ART_FILE, S_IXUSR);
    _system("ifconfig br0 192.168.0.2");
    _system("rmmod /lib/modules/2.6.15/net/ath_pktlog");
    _system("rmmod /lib/modules/2.6.15/net/ath_ahb");
    _system("insmod /lib/modules/art_ap.ko");
    _system(ART_FILE);	
}
#endif