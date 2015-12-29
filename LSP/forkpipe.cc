#include<iostream>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
#include<cstdlib>

using namespace std;

int main()
{
	int a, b, c, status;
	int p[2];
	pipe(p);
	int pid = fork();
	switch(pid)
	{
		case -1:
		cout << "fork error";
		exit(1);
		case 0:
		{cout << "Enter 2  numbers" << endl;
		cin >> a >> b;	
		c = a + b;cout << "In child c is " << c << endl;
		close(p[0]);
		write(p[1],&c, 4);close(p[1]);
		exit(0);}
		default:
		wait(&status);
		close(p[1]);
		read(p[0], &c, 4);
		cout << c  << endl;close(p[0]);
	}
return 0;
}
		
