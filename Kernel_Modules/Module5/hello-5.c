// This header file is required by all kernel modules
#include <linux/module.h>

// This header file is required for KERN_INFO
#include <linux/kernel.h>

// This header file is required macroes
#include <linux/init.h>

// This header file is used to get information about the parameters
#include <linux/moduleparam.h>

#include <linux/stat.h>

// Macro for name of author
#define DRIVER_AUTHOR "Dinesh Kadam"

// Macro for module description
#define DRIVER_DESC   "Marvellous Infosystems Demo module with arguments"

int myint = 21;

/*
	This macro is used to to register information about the input argument
	First parameter is name of variable
	Second parameter is its type
	Third parameter is its permission
*/
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "Integer variable"); //optional

static int __init hello_5_init(void)
{
	printk(KERN_INFO "Marvellous Value is:  %d\n", myint);
	return 0;
}

static void __exit hello_5_exit(void)
{
	printk(KERN_INFO "Maevellous : Removing module\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);

// Register name of licance
MODULE_LICENSE("GPL");

// Register name of author
MODULE_AUTHOR(DRIVER_AUTHOR);

// Provide module description
MODULE_DESCRIPTION(DRIVER_DESC);

// we can insert our module as insmod myint=11
