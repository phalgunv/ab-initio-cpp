#include<iostream>
#include<cstring>
#include<unistd.h>
#include<cstdlib>
#include<fcntl.h>
#include<sys/types.h>
using namespace std;

void filecopy(int in, int out, int size)
{
	char buf[500];
	int n;
	n = read(in, buf, 500);
	write(out, buf, n);
	 
}



int main(int argc, char **argv)
{
	int fd;
	fd = open(argv[1],O_RDONLY);
	 if((fd > 2) && (!(strcmp(argv[0],"./mycat"))))
	{
		filecopy(fd, 1, 500);
	}
	else if(!strcmp(argv[0],"./mycat"))
	{
		filecopy(0, 1, 500);exit(0);
	}
	
}
