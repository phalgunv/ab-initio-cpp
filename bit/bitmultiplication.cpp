#include<iostream>
using namespace std;

int main()
{
	unsigned int a, b;
 	int mul = 0;
	int set[32];
	cout << "Enter two numbers\n";
	cin >> a >> b;
	for(int i = 0; i < 32; i++)
	{
		set[i] = ((b&(1<<i)) ? 1 : 0);
	}
	for(int i = 0; i < 32; i++)
	{
		if(set[i])
		mul = mul+(a<<i);
	}
	cout << mul << endl;
}
