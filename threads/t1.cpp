#include<iostream>
extern "C"
{
#include<unistd.h>
#include<pthread.h>
}
using namespace std;

void * f1(void * argument);
void * f2(void * argument);

int main()
{
pthread_t t1,t2;

pthread_create(&t1, NULL, f1, NULL);
pthread_create(&t2, NULL, f2, NULL);
//sleep(1);
pthread_exit(NULL);
cout << "Hello world" ;
cout<<endl<<"heyhey";
return 0;
}

void * f1(void * argument)
{
while(1){
	cout << "Hello..." << endl;
//sleep(2);
}
}

void * f2(void * argument)
{
while(1){
	cout << "world" << endl;
//sleep(2);
}
}	

