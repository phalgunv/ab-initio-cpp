#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

void forkChild(int n)
{
int pid[n];
for(int i = 0; i < n; i++)
{
	int status;
	pid[i] = fork();
	if(pid[i] == 0)
	{
	cout << "Child " << i << "with pid " << getpid() << endl;
	return;
	}
	else
	{
	waitpid(pid[i], &status, WUNTRACED);
	cout << pid[i] << endl;
	}
}
}
int main()
{
forkChild(5);
return 0;
}
