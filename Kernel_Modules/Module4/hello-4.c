#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */


#define DRIVER_AUTHOR "Dinesh Kadam"

#define DRIVER_DESC   "Marvellous Infosystems Demo module"

static int __init init_hello_4(void)
{
	printk(KERN_INFO "Marvellous : loading module\n");
	return 0;
}

static void __exit cleanup_hello_4(void)
{
	printk(KERN_INFO "Marvellous : Removing module\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

MODULE_LICENSE("GPL");

MODULE_AUTHOR(DRIVER_AUTHOR);

MODULE_DESCRIPTION(DRIVER_DESC);
