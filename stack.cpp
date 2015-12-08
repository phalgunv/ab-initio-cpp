#include<iostream>
using namespace std;

void f(int d, int e, int f)
{
	cout << "Inside Function f" << endl;
	int x,y,z;
	cout << "Address of d:" << (void *)&d << endl;
	cout << "Address of e:" << (void *)&e << endl;
	cout << "Address of f:" << (void *)&f << endl;
	cout << "Address of x:" << (void *)&x << endl;
	cout << "Address of y:" << (void *)&y << endl;
	cout << "Address of z:" << (void *)&z << endl;
}

int main()
{
	int a,b,c;
	f(a,b,c);
	int m1,m2;
	cout << "Addr of main variable m1:" << (void *)&m1 << endl;
	cout << "Addr of main variable m2:" << (void *)&m2 << endl;
}
