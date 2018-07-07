#include <linux/module.h>
#include <linux/version.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/ioport.h> 
#include <asm/uaccess.h> 
#include <linux/fs.h> 
#include <asm/io.h> 
#include <asm/types.h>
#include <asm/setup.h>
#include <asm/memory.h>
#include <asm/mach-types.h>
#include <asm/hardware.h>
#include <asm/irq.h>

#include <asm/mach/arch.h>
#include <asm/mach/map.h>
#include <asm/mach/irq.h>

#include <asm/arch/irq.h>
#include <asm/hardware/sa1111.h>
#include <linux/delay.h>

/*
 * Prototypes
 */
int key_init (void );
extern int key_ioctl (struct inode *inode, struct file *pfile,
								unsigned int command, unsigned long argument);
int key_open(struct inode *, struct file *);
int key_release(struct inode *, struct file *);
ssize_t key_read (struct file *, char *, size_t, loff_t *); 
int init_module(void);
void cleanup_module(void);
/* void cleanup_module1 (void); */
void key_handler(int irq, void *dev_id, struct pt_regs *regs);

/*
 * The name for our device, as it will appear in /proc/devices
 */
#define DEVICE_NAME "KEY"
#define	KEY_MAJOR	233	/* free for demo/sample use	*/
#define KEY_BASE	0x14000000
#define KEY_BYTES       1
static DECLARE_WAIT_QUEUE_HEAD(wq);
static struct file_operations key_fops =
{
	open:		key_open,
	read:		key_read,	
	release:	key_release,
};



static int Major;
//static int Device_Open = 0;
unsigned int *keyport;
unsigned char key_value;	
int key_init(void)
{
int return_val;	

    printk("keypad_init\n");
    /*
     * Register the character device
     */
    Major = register_chrdev (KEY_MAJOR, DEVICE_NAME, &key_fops);
    /* Negative values signify an error */
	if (Major < 0) {
		printk ("KEY init_module: failed with %d\n", Major);
		return Major;
	}  
    printk ("KEY driver registred: major = %d\n", Major);
    
    GPDR0 &= ~(1 << 0);   
    set_GPIO_IRQ_edge( 0, /*GPIO_BOTH_EDGES */GPIO_RISING_EDGE);
  
    return_val = request_irq(IRQ_GPIO(0), key_handler, SA_INTERRUPT, "KEY PAD INT",0x00 );
  
  if( return_val < 0 )
  {
    printk(KERN_ERR "pxa255_pro_key_init() : Can't reqeust irq %#010x\n", IRQ_GPIO(0) );
    return -1;
  }
    return 0;
}

void key_handler(int irq, void *dev_id, struct pt_regs *regs) 
{ 
	keyport = (unsigned int*)ioremap_nocache(KEY_BASE, 0x10);	
        key_value = *(keyport+0)&0xf;
				//key_value -=160;
				//printk("KEY INPUT : [%d] \n",key_value);

	iounmap(keyport);
	wake_up_interruptible(&wq);
} 
/*
 * called whenever a process attempts to open the device
 */
int key_open (struct inode *inode, struct file *file)
{
	printk ("open..ok \n");
	return 0;
}

/*
 * Called when a process closes the device.
 * Doesn't have a return value in version 2.0.x because it can't fail,
 * but in version 2.2.x it is allowed to fail
 */
int key_release (struct inode *inode, struct file *file)
{
	printk ("device_release(%p,%p)\n", inode, file);
	return 0;

}

ssize_t key_read (struct file *inode, char *gdata, size_t length, loff_t *off_what) 
{	
	
	unsigned char c;
	interruptible_sleep_on(&wq);
	c=key_value;
	copy_to_user(gdata,&c,KEY_BYTES);
	printk ("write .....ok \n");  
	
	return (length);
}



#ifdef MODULE
/*
 * Initialize the module
 */
int init_module (void)
{
	return key_init();
}

/*
 * Cleanup - unregister the appropriate file from /proc
 */
void cleanup_module (void)
{
	int ret;

	/*
	 * Unregister the device
	 */
	 
/*	ret = module_unregister_chrdev (Major, DEVICE_NAME); */
  disable_irq(IRQ_GPIO(0));
	free_irq(IRQ_GPIO(0),0x00);
	ret = unregister_chrdev (KEY_MAJOR, DEVICE_NAME); 

	/*
	 * If there's an error, report it
	 */
	if (ret < 0) {
		printk ("unregister_chrdev: error %d\n", ret);
	}
	else {
		printk ("module clean up ok!! \n");
	}
}
#endif	/* MODULE */

#if 0
void cleanup_module1 (void)
{
	int ret;

	/*
	 * Unregister the device
	 */
	 
/*	ret = module_unregister_chrdev (Major, DEVICE_NAME); */
	ret = unregister_chrdev (Major, DEVICE_NAME); 

	/*
	 * If there's an error, report it
	 */
	if (ret < 0) {
		printk ("unregister_chrdev: error %d\n", ret);
	}
	else {
		printk ("module clean up ok!! \n");
	}	
}
#endif

//module_init(key_init);
//module_exit(cleanup_module1);

MODULE_LICENSE("GPL");
//MODULE_AUTHOR(DRIVER_AUTHOR);
//MODULE_DESCRIPTION(DRIVER_DESC);
