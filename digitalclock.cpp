#include<iostream>
using namespace std;

class digital
{
	int s,m,h;
	public:
	digital():s(0),m(0),h(0)
	{
	}
	}
	void H()
	{
		h %= 24;
		h++;
	}

	void M()
	{
		if ( m == 59)
		H();
		m %= 60;
		m++;
	}

	void S()
	{
		while(1)
		{
		s %= 60;
		cout << h << ":" << m << ":" << s << endl;
		if(s == 59)
		M();
		s++;
		}
	}
};
int main()
{
	digital d;
	d.S();
}
