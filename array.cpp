#include<iostream>
#include<string>
using namespace std;


void print(char * b)
{
	cout << "Addr of 3rd ele " << (void *)&b[2] << endl;
	cout << "Addr of 3rd ele " << (void *)&b[0] << endl;
	b = b++;
	//(*b)++;
	cout << b << endl;
}

void print1(char a1[])
{
	//char i[] = "def";
	//i++;
	//cout << i << endl;
	cout << "print1" << endl;
	cout << "addr of 3rd ele " << &(a1+2) << endl;
	cout << "addr of 3rd ele " << (void *)&a1[2] << endl;
	cout << a1 <<endl;
	a1++;
	cout << a1 <<endl;
	(*a1)++;
	cout << a1 << endl;
}

int main()
{
	char *a = "1234567890";
	//(*a)++;
	char a1[]="0123456789";
	//a1++;

	print(a);
	print1(a1);
	cout << a1 << endl;
	int x = 5;
	const int *y = &x;
	//(*y)++;
	cout << *y << endl;
}

