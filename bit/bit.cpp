#include<iostream>
#include<string>
using namespace std;

int main()
{
string str1 = "abc";
string str2 = "abd";
int l = str1.length();
int c = 0;
for(int i = 0; i < l; i++)
{
if((str1[i]^str2[i])==0)
{c++;
int a =  str1[i]^str2[i] ;
cout << a << endl;
}
else 
cout << "Strings are not equal" << endl;
}
cout << c << " value of c.." << endl;

if (c == l)
cout << "both the strings are equal\n";
}

