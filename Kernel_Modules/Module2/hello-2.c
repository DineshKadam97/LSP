// This header file is required by all kernel modules
#include <linux/module.h>

// This header file is required for KERN_INFO
#include <linux/kernel.h>

// This header file is required macroes
#include <linux/init.h>

// This function gets called automattically when module gets loaded by insmod

// This function returns 0 if it successfully executed otherwise it returns non zero value

static int __init hello_2_init(void)
{
	printk(KERN_INFO "Marvellous : Inserting module 2\n");
	return 0;
}

// This function gets called automatically when module gets removed from memory by rmmod
static void __exit hello_2_exit(void)
{
	printk(KERN_INFO "Marvellous : Removing module 2\n");
}

// Register our init function
module_init(hello_2_init);

// Register our cleanup function
module_exit(hello_2_exit);

MODULE_LICENSE("GPL")
