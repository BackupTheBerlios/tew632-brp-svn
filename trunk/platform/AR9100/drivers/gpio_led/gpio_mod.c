#include <linux/config.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/miscdevice.h>
#include <linux/watchdog.h>
#include <linux/slab.h>
#include <linux/ioport.h>
#include <linux/fcntl.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <asm/system.h>
#include <asm/delay.h>
#include <linux/notifier.h>
#include <linux/reboot.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/smp_lock.h>
#include <linux/wait.h>
#include <linux/fs.h>
#include "gpio.h"

//#define GPIO_DEBUG 1
#ifdef GPIO_DEBUG
#define DEBUG_MSG(fmt, arg...)       printk(fmt, ##arg)
#else
#define DEBUG_MSG(fmt, arg...)
#endif


//static devfs_handle_t devfs_handle;

MODULE_DESCRIPTION("AR7100 GPIO driver");
MODULE_LICENSE("GPL");

static unsigned int gpio_ioctl (struct inode *inode, struct file *file, unsigned int gpio_pin, unsigned long gpio_action);
static int gpio_open (struct inode *inode, struct file *file);
static int gpio_release (struct inode *inode, struct file *file);

static struct file_operations gpio_fops = {
	owner:		THIS_MODULE,
	ioctl:		gpio_ioctl,
	open:		gpio_open,
	release:	gpio_release,
};

static int gpio_major = 201; 

static void gppRegSet (MV_U32 group, MV_U32 regOffs,MV_U32 mask,MV_U32 value)
{
	MV_U32 gppData;

	gppData = MV_REG_READ(regOffs);

	gppData &= ~mask;

	gppData |= (value & mask);

	MV_REG_WRITE(regOffs, gppData);
}

static int mvGppValueSet (MV_U32 group, MV_U32 mask, MV_U32 value)
{
        MV_U32 outEnable;
        MV_U32 i;

        if (group >= MV_GPP_MAX_GROUP)
        {
                printk("mvGppValueSet: Error invalid group number \n");
                return 0;
        }

        /* verify that the gpp pin is configured as output              */
        /* Note that in the register out enabled -> bit = '0'.  */
        outEnable = ~MV_REG_READ(GPP_DATA_OUT_EN_REG(group));

        for (i = 0 ; i < 32 ;i++)
        {
                if (((mask & (1 << i)) & (outEnable & (1 << i))) != (mask & (1 << i)))
                {
                        printk("mvGppValueSet: Err. An attempt to set output "\
                                           "value to GPP %d in input mode.\n", i);
                        return 0;
                }
        }

        gppRegSet(group, GPP_DATA_OUT_REG(group), mask, value);

        return 1;

}


MV_U32 mvGppValueGet(MV_U32 group, MV_U32 mask)
{
	MV_U32 gppData;

	gppData = MV_REG_READ(GPP_DATA_IN_REG(group));

	gppData &= mask;

	return gppData;

}

static unsigned int gpio_ioctl(struct inode *inode, struct file *file, unsigned int pin, unsigned long gpio_action)
{	
	MV_U32 gpio_data = 0;
	DEBUG_MSG("gpio ioctl receive pin=0x%x,gpio_action=0x%x \n", pin, gpio_action);
	if(gpio_action == 1) {
		*(volatile int *)(0xb8040008) &=~(pin);      	
 	} else if(gpio_action == 0) {
	  	*(volatile int *)(0xb8040008) |=(pin);    	
	} else 	/* Only Get MV_GPP13(Push Button)*/
		gpio_data = ( *((volatile unsigned long *)0xb8040004) & 0x200000);        	// -> Read Data
	DEBUG_MSG("GPIO Data = 0x%02x\n",gpio_data);
	return gpio_data;
	
}

static int gpio_open (struct inode *inode, struct file *file)
{
	DEBUG_MSG( "<1>gpio.o: opened.\n");
	return 0;
}

static int gpio_release (struct inode *inode, struct file *file)
{
	DEBUG_MSG( "<1>gpio.o: closed.\n");
	return 0;
}

static int __init gpio_init(void)
{
	int result;
	printk("Entry gpio_ioctl init_module !!\n");

	// hook device into kernel
	result = register_chrdev( gpio_major, "gpio_ioctl", &gpio_fops);
	
	if (result) {
		printk( "<1>gpio_ioctl : cannot get major %d\n", gpio_major);
		return result;
	}

	//devfs_handle = devfs_register(NULL, "gpio_ioctl", DEVFS_FL_AUTO_DEVNUM
	//			      gpio_major, 0,
	//			      S_IFCHR | S_IRUSR | S_IWUSR,
	//			      &gpio_fops, NULL);
				      
	//printk( "init gpio_ioctl Successful,  major = %d\n", gpio_major);
	
	return	0;
}



static void __exit gpio_exit(void)
{
	//if ( devfs_unregister_chrdev( gpio_major, "gpio_ioctl") !=0 ){
          // printk( "<1>gpio_ioctl : unable to release major %d\n", gpio_major);
	//}
	//devfs_unregister(devfs_handle);
}

module_init(gpio_init);
module_exit(gpio_exit);
