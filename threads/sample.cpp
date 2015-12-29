#include<iostream>
#include<unistd.h>
using namespace std;

void f1();
void f2();

int main()
{
f1();
f2();
cout << "Hello world" ;
return 0;
}

void f1()
{
	cout << "Hello..." << endl;
	sleep(2);
}

void f2()
{
	cout << "world" << endl;
}
