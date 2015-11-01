#include<iostream>
using namespace std;

/*int addBinary(int a1[], int a2[], int result[]){
    int i, c = 0;
    for(i = 0; i < 8 ; i++){
        result[i] = ((a1[i] ^ a2[i]) ^ c); //a xor b xor c
        c = ((a1[i] & a2[i]) | (a1[i] &c)) | (a2[i] & c); //ab+bc+ca
    }*/
    //result[i] = c;
    //return c;
 
int main()
{
	int n;
	cout<<"\nenter size of array"<<endl;
	cin>>n;
	int a[n],b[n];
	cout<<"\nenter first binary number\n ";
	int i,j;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nfirst array is"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
	cout<<"\nenter second binary number\n ";
	for(i=0;i<n;i++)
	{
		cin>>b[i];
	}
	cout<<"\nsecond array is"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	int sum[n+1];
	int c=0;
	for(i = n-1; i >= 0 ; i--)
	{
        sum[i] = ((a[i] ^ b[i]) ^ c); //a xor b xor c
        c = ((a[i] & b[i]) | (a[i] &c)) | (b[i] & c); //ab+bc+ca
    }
    //sum[n]=c;
    
    for(i=0;i<n;i++)
    {
    	cout<<"\n"<<a[i]<<"+"<<b[i]<<"="<<endl;
    }
    cout<<" \nthe sum is"<<endl;
    cout<<c<<" ";
    for(i=0;i<n;i++)
    {
    	cout<<sum[i]<<" ";
    }
    return 0;
    
	
}
