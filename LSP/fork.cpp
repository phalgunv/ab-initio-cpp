#include<iostream>
#include<unistd.h>
#include<cstdlib>
using namespace std;

void  do_parent()
{
	cout << "in parent:  pid = " << getpid() << endl;
	sleep(10);
	cout << "parent terminated\n";
}

void do_child()
{

	cout << "in child :  pid =" << getpid() << endl;
	sleep(3);
	cout << "child terminated\n";
	exit(0);
}
int main()
{
	int pid;
	pid = fork();
	switch (pid) {
		case -1:
			cout << "failed to fork a process\n";
			break;
		case 0:
			do_child();
			break;
		default:
			do_parent();
			break;
	}
	return 0;
}


