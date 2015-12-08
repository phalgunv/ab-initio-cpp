#include<iostream>
using namespace std;

class A
{
	public:
	virtual void print()
	{
		cout << "Inside print of class A " << endl;
	}
	virtual void sum()
	{cout << "Sum function in class A" << endl;}
};

class B :virtual public A
{
	public:
	void print()
	{
		cout << "Inside print of class b " << endl;
	}
};
class c : virtual public A
{
	public:
	void print()
	{
		cout << "Inside print of class c " << endl;
	}
};

class d: public B, public c
{
	public:
	void print()
	{cout << "Inside print of class d" << endl;}
	void sum()
	{
	cout << "sum in class D" << endl;
	}
};
int main()
{
	A (* ptr);
	ptr = new B();
	ptr->print();
	ptr = new d();
	ptr->sum();
}
