extern int _system(const char *fmt, ...);
extern int read_pid(char *file);
extern int init_file(char *file);
extern void save2file(const char *file, const char *fmt, ...);
extern char *replace(char *input, const char target, const char rechar );
char *time_format_for_log(void);
int wan_connected_cofirm(char *if_name);
int check_ip_match(const char *target, const char *model);
char *parse_special_char(char *p_string);
int getStrtok(char *input, char *token, char *fmt, ...);
/* ken added for get image checksum */
#ifdef	CONFIG_SHOW_CHECKSUM
void flash_get_checksum(void);
#endif
void string_insert(char *st, char insert[], int start);

#ifdef RADVD
void write_radvd_conf(void);
char *get_link_local_ip_l(char *interface_name);
#endif

char *get_ipv6_prefix (char *ipv6_addr, int length);

#ifdef DHCPv6
void write_dhcpd6_conf (void);
#endif

#ifdef MPPPOE
typedef enum ByteType
{
        TXBYTES =1,
        RXBYTES,
}eByteType;

char* display_lan_bytes(eByteType byte_type,char *filepath);
char* display_wan_bytes(eByteType byte_type,char *filepath);
char* display_wlan_bytes(eByteType byte_type,char *filepath);
char* display_bytes(eByteType byte_type,char *interface,char *filepath);
#endif

void modify_ppp_options(void);
char* return_ap_rt_info(void);
struct mp_info check_mpppoe_info(int pppoe_unit);

struct mp_info {
	int pid;
	char pppoe_iface[5];
};

struct IpRange{
	char addr[38];
}; 

struct OtherMachineInfo{
	char filter[14];
	char log[4];
	char schedule[64];
	int index;
}; 

#define foreach(word, wordlist, next, match) \
      for (next = &wordlist[strspn(wordlist, match)], \
                    strncpy(word, next, sizeof(word)), \
                    word[strcspn(word, match)] = '\0', \
                    word[sizeof(word) - 1] = '\0', \
                    next = strstr(next, match); \
                    strlen(word); \
                    next = next ? &next[strspn(next, match)] : "", \
                    strncpy(word, next, sizeof(word)), \
                    word[strcspn(word, match)] = '\0', \
                    word[sizeof(word) - 1] = '\0', \
                    next = strstr(next, match))

#define sin_addr(s) (((struct sockaddr_in *)(s))->sin_addr)
#define run_rc_action(action) write_rc_action(action);kill(read_pid(RC_PID), SIGHUP)

#define cprintf(fmt, args...) do { \
	FILE *cfp = fopen("/dev/console", "w"); \
	if (cfp) { \
		fprintf(cfp, fmt, ## args); \
		fclose(cfp); \
	} \
} while (0)


/************************** Channel Parameter **************************/
#define MAX_GROUP           4
#define WIRELESS_BAND_24G   0
#define WIRELESS_BAND_50G   1
/* region domain */
#define DEBUG_REG_DMN   0x0000
#define NULL1           0xffff
/* for 2.4G */
#define APLD            0x0001
#define ETSIA           0x0002
#define ETSIB           0x0003
#define ETSIC           0x0004
#define FCCA            0x0005
#define MKKA            0x0006
#define MKKC            0x0007
#define WORLD           0x0008
/* for 5G */
#define APL1            0x1001
#define APL2            0x1002
#define APL3            0x1003
#define APL4            0x1004
#define APL5            0x1005
#define APL6            0x1006
#define ETSI1           0x1007
#define ETSI2           0x1008
#define ETSI3           0x1009
#define ETSI4           0x100A
#define ETSI5           0x100B
#define ETSI6           0x100C
#define FCC1            0x100D
#define FCC2            0x100E
#define FCC3            0x100F
#define MKK1            0x1010
#define MKK2            0x1011

struct channel_list_s {
	unsigned short low_channel;   // Low Channel center in MHz
	unsigned short high_channel;  // High Channel center in MHz
};

struct freq_table_s {
	int regdomain_mode;
	int no_group;
	struct channel_list_s group[MAX_GROUP];
};

static struct freq_table_s wireless2_table[] = {
	{DEBUG_REG_DMN, 4,  {
								  {2312, 2372},      /* Channel -19 to -7 */
								  {2412, 2472},
								  {2484, 2484},
								  {2512, 2732}}},

	{APLD, 2,  {
					  {2312, 2372},        /* Negative Channels */
					  {2412, 2472},        /* Channel 1 - 13 */
					  {   0,    0},
					  {   0,    0}}},

	{ETSIA, 1,  {
						{2457, 2472},        /* Channel 10 - 13 */
						{   0,    0},
						{   0,    0},
						{   0,    0}}},

	{ETSIB, 1,  {
						{2432, 2472},        /* Channel 5 - 13 */
						{   0,    0},
						{   0,    0},
						{   0,    0}}},

	{ETSIC, 1, {
					  {2412, 2472},        /* Channel 1 - 13 */
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},

	{FCCA, 1, {
					 {2412, 2462},        /* Channel 1 - 11 */
					 {   0,    0},
					 {   0,    0},
					 {   0,    0}}},

	{MKKA, 2, {
					 {2412, 2472},        /* Channel 1 - 13 */
					 {2484, 2484},        /* Channel 14 */
					 {   0,    0},
					 {   0,    0}}},

	{MKKC, 1, {
					 {2412, 2472},        /* Channel 1 - 13 */
					 {   0,    0},
					 {   0,    0},
					 {   0,    0}}},

	{WORLD, 1, {
					  {2412, 2472},        /* Channel 1 - 13 */
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},    

	{NULL1, 1, {
					  {2412, 2472},        /* Channel 1 - 13 */
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},  
};

static struct freq_table_s wireless5_table[] = {
	{DEBUG_REG_DMN, 2, {
								 {5120, 5700},
								 {5745, 5825},
								 {   0,    0},
								 {   0,    0}}},

	{APL1, 1, {
					 {5745, 5825},
					 {   0,    0},
					 {   0,    0},
					 {   0,    0}}},

	{APL2, 1, {
					 {5745, 5805},
					 {   0,    0},
					 {   0,    0},
					 {   0,    0}}},

	{APL3, 2, {
					 {5280, 5320},
					 {5745, 5805},
					 {   0,    0},
					 {   0,    0}}},

	{APL4, 2, {
					 {5180, 5240},
					 {5745, 5825},
					 {   0,    0},
					 {   0,    0}}},

	{APL5, 2, {
					 {5745, 5825},
					 {   0,    0},
					 {   0,    0},
					 {   0,    0}}},

	{APL6, 2, {
					 {5180, 5320},
					 {5745, 5825},
					 {   0,    0},
					 {   0,    0}}},

	/*
	 * The ETSI1 domain requires TPC
	 * As the TPC specification are unfinished, 3dBi are
	 * removed from each of the ETSI1 power selections
	 */
	{ETSI1, 2, {
					  {5180, 5320},  // Should be 23 with TPC
					  {5500, 5700},  // Should be 30 with TPC
					  {   0,    0},
					  {   0,    0}}},

	{ETSI2, 1, {
					  {5180, 5240},
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},

	{ETSI3, 1, {
					  {5180, 5320},
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},

	{ETSI4, 1, {
					  {5180, 5320},
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},

	{ETSI5, 1, {
					  {5180, 5240},
					  {   0,    0},
					  {   0,    0},
					  {   0,    0}}},

	{ETSI6, 2, {
					  {5180, 5280},
					  {5500, 5700},
					  {   0,    0},
					  {   0,    0}}},

	/*
	 * Values artificially decreased to meet FCC testing
	 * procedures
	 */
	{FCC1, 3, {
					 {5180, 5240},
					 {5260, 5320},
					 {5745, 5825},
					 {   0,    0}}},

	{FCC2, 2, {
					 {5180, 5320},
					 {5745, 5825},
					 {   0,    0},
					 {   0,    0}}},

	{FCC3, 4, {
					 {5180, 5240},
					 {5260, 5320},
					 {5500, 5700},
					 {5745, 5825}}},

	{MKK1, 1, {
					 //{5170, 5230},// preJP
					 {5180, 5320},  // newJP
					 {   0,    0},
					 {   0,    0},
					 {   0,    0}}},

	{MKK2, 3, {
					 {4920, 4980},
					 {5040, 5080},
					 {5170, 5230},
					 {   0,    0}}},    

	{NULL1, 3, {          /* FCC1 */
					  {5180, 5240},
					  {5260, 5320},
					  {5745, 5825},
					  {   0,    0}}}, 

};

struct domain_name_s {
	int  number;
	char name[20];
	int  wireless2_freq_table;
	int  wireless5_freq_table;
};

struct region_s{
	char *name;
	int number;
};

static struct domain_name_s  domain_name[] = {
	{0x00,     "NO_ENUMRD",     NULL1,  NULL1  },
	{0x03,     "NULL1_WORLD",   WORLD,  NULL1},         /* For 11b-only countries (no 11a allowed) */
	{0x07,     "NULL1_ETSIB",   ETSIB,  NULL1},         /* Israel */
	{0x08,     "NULL1_ETSIC",   ETSIC,  NULL1},
	{0x10,     "FCC1_FCCA",     FCCA,   FCC1},          // USA
	{0x11,     "FCC1_WORLD",    WORLD,  FCC1},          // Hong Kong                                                          
	{0x20,     "FCC2_FCCA",     FCCA,   FCC2},          // Canada                                                             
	{0x21,     "FCC2_WORLD",    WORLD,  FCC2},          // Australia                                                          
	{0x22,     "FCC2_ETSIC",    ETSIC,  FCC2},                                                                          
	{0x31,     "FRANCE_RES",    WORLD,  ETSI3},         // Legacy France for OEM                                              
	{0x3A,     "FCC3_FCCA",      FCCA,   FCC3},          // USA & Canada w/5470 band, 11h, DFS enabled                         
	{0x37,     "ETSI1_WORLD",   WORLD,  ETSI1},                                                                         
	{0x32,     "ETSI3_ETSIA",   WORLD,  ETSI3},         // France (optional)                                                  
	{0x35,     "ETSI2_WORLD",   WORLD,  ETSI2},         // Hungary & others                                                   
	{0x36,     "ETSI3_WORLD",   WORLD,  ETSI3},         // France & others                                                    
	{0x30,     "ETSI4_WORLD",   WORLD,  ETSI4},                                                                         
	{0x38,     "ETSI4_ETSIC",   ETSIC,  ETSI4},                                                                         
	{0x39,     "ETSI5_WORLD",   WORLD,  ETSI5},                                                                         
	{0x34,     "ETSI6_WORLD",   WORLD,  ETSI6},         // Bulgaria                                                           
	{0x33,     "ETSI_RESERVED", NULL1,  NULL1},         // Reserved (Do not used)                                             
	{0x40,     "MKK1_MKKA",     MKKA,   MKK1},          // Japan (JP1)                                                        
	{0x41,     "MKK1_MKKB",     MKKA,   MKK1},          // Japan (JP0)                                                        
	{0x42,     "APL4_WORLD",    WORLD,  APL4},          // Jordon                                                             
	{0x43,     "MKK2_MKKA",     MKKA,   MKK2},          // Japan with 4.9G channels                                           
	{0x44,     "APL_RESERVED",  NULL1,  NULL1},         // Reserved (Do not used)                                             
	{0x45,     "APL2_WORLD",    WORLD,  APL2},          // Korea                                                              
	{0x46,     "APL2_APLC",     NULL1,  APL2},                                                                           
	{0x47,     "APL3_WORLD",    WORLD,  APL3},                                                                          
	{0x48,     "MKK1_FCCA",     FCCA,   MKK1},          // Japan (JP1-1)                                                      
	{0x49,     "APL2_APLD",     APLD,   APL2},          // Korea with 2.3G channels                                           
	{0x4A,     "MKK1_MKKA1",    MKKA,   MKK1},          // Japan (JE1)                                                        
	{0x4B,     "MKK1_MKKA2",    MKKA,   MKK1},          // Japan (JE2)                                                        
	{0x4C,     "MKK1_MKKC",     MKKC,   MKK1},          // Japan (MKK1_MKKA,except Ch14)                                      
	{0x52,     "APL1_WORLD",    WORLD,  APL1},          // Latin America                                                      
	{0x53,     "APL1_FCCA",     FCCA,   APL1},                                                                           
	{0x54,     "APL1_APLA",     NULL1,  APL1},                                                                           
	{0x55,     "APL1_ETSIC",    ETSIC,  APL1},                                                                          
	{0x56,     "APL2_ETSIC",    ETSIC,  APL2},          // Venezuala                                                          
	{0x58,     "APL5_WORLD",    WORLD,  APL5},          // Chile                                                              
	{0x5B,     "APL6_WORLD",    WORLD,  APL6},          // Singapore                                                          
	{0xffff,   "unknow",        NULL1,  NULL1}
};

static struct region_s region[] = {
	{"Africa",				0x37},
	{"Asia",					0x52},
	{"Australia",			0x21},
	{"Canada",				0x20},
	{"Europe",				0xffff},   //can't find
	{"France",				0x36},
	{"Israel",				0x07},
	{"Japan",					0x40},
	{"Maxico",				0x10},
	{"South America",	0xffff},   //can't find
	{"United States",	0x10}
};


