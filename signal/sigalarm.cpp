#include<iostream>
#include<csignal>
#include<stdlib.h>
using namespace std;


void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";

	cout << "Program going to sleep for 5 sec ... zzzzzz \n";
	sleep(5);

}

int main ()
{
    signal(SIGALRM, signalHandler);  
	
	//int i = 0;
	//while(++i)
	//{
       		//cout << "Going to sleep...." << i <<endl;
		//if(i==3)
		//raise(SIGALRM);
		alarm(5);
   // }
    return 0;
}
