using namespace std;

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char *argv[])
{
     int pid;
     int count = 3;
     int i;
     
     count--;
     pid=fork();
     if (pid > 0) { /* parent continues here */
	  count--;
	  pid = fork();
	  if (pid == 0) { /* second child */
	      count--;
	      if (count == 0)
		  system("/bin/ps -el"); // Last leaf
		  //execlp("/bin/ps","ps","-el", NULL); // Last leaf
	      // -f to get ppid for process tree
	      // -a would show ps command as well
	      // -e goes all the way back
	  }
	  else if (pid > 0) { // Parent ends
	       wait(NULL);
	       cout << endl;
	  }
	  else // Bad fork
	       exit(-1);
     }
     else if (pid == 0) { 
     	 for (i = 0; i < 30000000; i++); // Leaf - delay
}
     else /*  nly if there was a problem with fork */
          exit(-1);
}

