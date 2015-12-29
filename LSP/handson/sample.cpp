#include<iostream>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<cstdlib>
using namespace std;

int main()
{
	mkdir("bava", 0777);
	chdir("bava");
	system("touch bujji");
}	
