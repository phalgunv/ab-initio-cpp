#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cout << "\n the entered string is : " << str << endl;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    int freq[26]={0};
    for (int i = 0; i < str.length(); i++)
    {
        int j = str[i] - 'A';
        freq[j]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(freq[i] > 1)
        {
            cout << "\n" << char(i+65) << " occured " << freq[i] << "times \n" ;
        }
    }
    return 0;
}
