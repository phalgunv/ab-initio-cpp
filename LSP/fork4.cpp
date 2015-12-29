#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include<cstdlib>
using namespace std;
void Count(int start, char ch);



int main(int argc, char *arg[])
{
int pid;
int start = 5;
pid=fork();
if (pid > 0) { // parent continues here
Count(start, 'P');
wait(NULL); // To get printing done before shell prompt shows
}
else if (pid == 0)// child got here!
{

//system("ps -el");
Count(start, 'C');
}
else // only if there was a problem with fork
exit(-1);
cout << endl;
}
void Count(int start, char ch)
{
int i, j;
for (i = start; i < 10; i++) {
//for (j = 0; j < 1000000; j++) ;
sleep(3);
cout << endl << ch << ": " << i;
//cout << endl << "Now im done " << endl;
}
}
