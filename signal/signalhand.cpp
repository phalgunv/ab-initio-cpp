#include<iostream>
#include<csignal>
#include<stdlib.h>
using namespace std;


void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";

	cout << "Program going to sleep for 5 sec ... zzzzzz" << endl;
	sleep(5);

}

int main ()
{
    signal(SIGINT, signalHandler);  
	int i = 0;
	while(++i)
	{
       		cout << "Going to sleep...." << i <<endl;
		if(i==3)
		raise(SIGINT);
		sleep(1);
    }
    return 0;
}
