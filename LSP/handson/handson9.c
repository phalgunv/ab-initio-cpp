/*Observation:
 * file temp1 got created;
 * file temp2 didnot get created.
 * filename | file present | result
 * --------------------------------
 *  temp1    | No           | fd1 = 3
 *  temp2    | No           | fd2 = -1
 *  temp1    | Yes          | fd1 = 3
 *  temp2    | Yes          | fd2 = 4
 *  */
#include<fcntl.h>
#include<stdio.h>

int main()
{
        int fd1 = open("temp1", O_RDWR|O_CREAT, 0744);  // ? A
        int fd2 = open("temp2", O_RDWR, 0744);                  // ? B
        printf("fd1 = %d\n", fd1);
        printf("fd2 = %d\n", fd2);
}
