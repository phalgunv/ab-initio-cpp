#include<iostream>
using namespace std;

#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int a, b;
	pid = fork();
	if(pid == -1)
	cerr << "Fork error" << endl;
	else if(pid == 0)
	{
		cout << "In child" << endl;
		cout << "Enter two numbers" << endl;
		cin >> a >> b;
		cout << a+b << endl;
	}
	else
	{	cout << "In Parent" << endl;
		cout << a << "+" << b << endl;
		cout << a+b << endl;
	}

return 0;

}
