#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/timer.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bohdan Chupys");
MODULE_DESCRIPTION("Timer");
MODULE_VERSION("0.22");

static struct timer_list timer;
static long period = 1000;

void timer_fn(unsigned long data)
{
  printk("Timer tick\n");
}

static int __init hello_init(void){

  int ret;

  printk("[%s]: Timer module load\n", __func__);
  setup_timer( &timer, timer_fn, 0 );

  ret = mod_timer(&timer, jiffies + msecs_to_jiffies(period));
  if(ret) printk("Error in mod_timer\n");

  return 0;
}

static void __exit hello_exit(void){
  int ret;

  ret = del_timer(&timer);

  if(ret) printk("Timer still in use...\n");

  printk("Timer module uuninstalling");
}

module_init(hello_init);
module_exit(hello_exit);
