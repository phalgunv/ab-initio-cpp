#include<iostream>
#include<bitset>
using namespace std;

int main()
{
cout << "Enter a number" << endl;
int n;
cin >> n;
int p,q;
cout << "Enter values of p and q" << endl;
cin >> p >> q;
int i, j;
int t = n;
cout << "values between p and q are set ??" << bitset<32>(t) << endl;
for(i = 0; i < 32; i++)
t&=(~(1<<i));//clearing all the bits

cout << "values between p and q are set ??" << bitset<32>(t) << endl;
for( i = p; i <= q; i++)
{
t|=(1<<i);//set the bits b/w p and q
}
cout << bitset<32>(n) << endl;
cout << bitset<32>(t) << endl;

}
