#include<iostream>
using namespace std;

int main()
{
        char a[]="abc";
        cout << a << endl;
	(*a)++;
	(*a)++;
	(*a)++;
	(*a)++;
        cout << a << endl;
}


