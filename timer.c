#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Andrii Tymkiv");
MODULE_DESCRIPTION("Say hello and goodbye");
MODULE_VERSION("0.22");

static int __init hello_init(void){

}

static void __exit hello_exit(void){

}

module_init(hello_init);
module_exit(hello_exit);
