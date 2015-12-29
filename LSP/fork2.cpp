#include <iostream>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>   // Declaration for exit()
#include<sys/wait.h>
using namespace std;

int globalVariable = 2;

main()
{
   string sIdentifier;
   int    iStackVariable = 20;

   pid_t pID = fork();
   if (pID == 0)                // child
   {
      // Code only executed by child process

      sIdentifier = "***************Child Process:***************** ";
      globalVariable++;
      iStackVariable++;
    }
    else if (pID < 0)            // failed to fork
    {
        cerr << "Failed to fork" << endl;
        exit(1);
        // Throw exception
    }
    else                                   // parent
    {
      // Code only executed by parent process

      sIdentifier = "***********Parent Process:************";
	wait(NULL);
    }

    // Code executed by both parent and child.
  
    cout << sIdentifier << endl;
    cout << " Global variable: " << globalVariable << endl;
    cout << " Stack variable: "  << iStackVariable << endl;
}
                
