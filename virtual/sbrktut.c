#include<stdio.h>
#include<sys/types.h>

int main()
{
	//1.Uncomment below 2 line and execute the program
	void * p = sbrk(0);
	printf("%x\n",p);
	//Working of brk()
	//2.Now uncomment only below 4 lines and execute the program. The limit of heap is set to different value.	
	//int *size = 8;
	//brk(size);
	//void * p1 = sbrk(0);
	//printf("%x",p1);
	//3.Working of sbrk()
	//Uncomment below lines and execute the program.
	int size1 = 8;
	void *sz = sbrk(size1);
	  printf("%x \n",sz);
	if(sbrk(size1))
	{
	  void *p1 = sbrk(0);
	  printf("%x \n",p1);}
	//Freeing the space alloted by sbrk()
	brk(p);
	void *sz1 = sbrk(0);
	printf("%x \n",sz1);
	
}
