#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/ktime.h>
#include <linux/hrtimer.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bohdan Chupys");
MODULE_DESCRIPTION("Timer");
MODULE_VERSION("0.22");

unsigned long timer_interval_ns = 500000000;
static struct hrtimer timer;

enum hrtimer_restart timer_fn(struct hrtimer *timer_for_restart)
{
  printk("Timer tick\n");
  return HRTIMER_RESTART;
}

static int __init timer_init(void){

  ktime_t ktime;

  ktime = ktime_set(0, timer_interval_ns);

  hrtimer_init(&timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
  timer.function = &timer_fn;

  hrtimer_start(&timer, ktime, HRTIMER_MODE_REL);

  printk(KERN_ERR "Ready to start hrtimer");
  printk("Timer start\n");

  return 0;
}

static void __exit timer_exit(void){
  int cancelled = hrtimer_cancel(&timer);

  if(cancelled)
    printk(KERN_ERR "Timer still running\n");
  else
    printk(KERN_ERR "Timer cancelled\n");
}

module_init(timer_init);
module_exit(timer_exit);
