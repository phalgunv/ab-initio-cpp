/* Author: Phalgun Vaddepalli
   email: phalgun251@gmail.com
   Purspose: Sample program to study that a set can be used to sort a given input */
#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<int> S;
    set<int>::iterator it;
    int i;

    while(cin >> i)
        S.insert(i);

    cout<<"The sorted output:"<<endl;
    
    for(it = S.begin(); it != S.end(); it++)
    {
        cout<<*it << ' ';
    }
    
    cout << "highest" <<*S.rbegin();
    cout << endl;
    return 0;
}
