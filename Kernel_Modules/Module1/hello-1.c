// This header file is required by all kernel modules
#include <linux/module.h> //2modules init anni cleanyp

// This header file is required for KERN_INFO
#include <linux/kernel.h> //macros aani kernel che swatah che functions

// This function gets called automattically when module gets loaded by insmod

// This function returns 0 if it successfully executed otherwise it returns non zero value

int init_module(void)  //insmod kelyanantr kernal log filemadhey jate /var/log/syslog
{
	printk(KERN_INFO "Marvellous Infosystems : Initialisation\n"); // kernel chya log file madhey lihito printk mule => dmesg kelyavar disat

	return 0;
}

// This function gets called automatically when module gets removed from memory by rmmod
void cleanup_module(void)  //rmrmod kelyanantr kernel log file madhey jate /var/log/syslog
{ 
	printk(KERN_INFO "Marvellous Infosystems : Module removed\n");
}

// All the information which is printed by printk function is available in /var/log/syslog file.
//insmod insert module  (insmod hello-1.ko)
//lsmod sagle list ofkernel modules
//dmesg for kernel log
//rmmod to delete the module (rmmod hello-1)
//uname -r kernel cha number
//modinfo hello-1.ko
//16 sPETREMBER!!!

MODULE_LICENSE("GPL");

