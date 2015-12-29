#include<iostream>
#include<cstdlib>
#define SET(p,n)    (p|=(1<<n))
#define CLEAR(p,n)  (p&=~(1<<n))
#define TOGGLE(p,n) (p^=(1<<n))
#define TEST(p,n)   (p&=(1<<n))
#define ABS(p) ((p&(1<<31))?(~p+1):p)
using namespace std;

int main()
{
	while(1)
	{
		int choice, num, n;
		cout << "Select any one.. \n 1.Set a bit \n 2.Clear a bit \n 3.Toggle a bit \n 4.Test a bit is set or not \n 5. To find absolute of a number \n  6. to exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:	
				cout << "Enter number to perform operation \n";
				cin >> num;
				cout << "Enter the position of the bit \n";
				cin >> n;
				cout << "Value of the entered number is " << num << endl;
				SET(num,n);
				cout << "Value after setting " << n << " bit is " << num << endl;
				break;
			case 2:		
				cout << "Enter number to perform operation \n";
				cin >> num;
				cout << "Enter the position of the bit \n";
				cin >> n;
				cout << "Value of the entered number is " << num << endl;
				CLEAR(num,n);
				cout << "Value after clearing " << n << " bit is " << num << endl;
				break;
			case 3:		
				cout << "Enter number to perform operation \n";
				cin >> num;
				cout << "Enter the position of the bit \n";
				cin >> n;
				cout << "Value of the entered number is " << num << endl;
				TOGGLE(num,n);
				cout << "Value after Toggling " << n << " bit is " << num << endl;
				break;
			case 4:	
				cout << "Enter number to perform operation \n";
				cin >> num;
				cout << "Enter the position of the bit \n";
				cin >> n;
				cout << "Value of the entered number is " << num << endl;
				TEST(num,n);
				cout << "Value at " << n << " bit is " << num << endl;
				if(num)
					cout << n << "th bit is set " << endl;
				else
					cout << n << "th bit is not set" << endl;
				break;
			case 5:
				cout << "Enter a number \n";
				cin >> num;
				//ABS(num);
				cout << "Absolute value of " << num << " is " << ABS(num) << endl;

			case 6:	exit(0);
		}
	}
}
