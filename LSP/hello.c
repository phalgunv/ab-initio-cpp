#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>


int my_init(void) {
  printk ("<1> Module insertion is successful.....\n");
  return 0;
}

void my_exit(void) {
  printk ("<1> Module removal is successful .....\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR ("R KUMAR ");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION (" simple Hello World kernel program....");

