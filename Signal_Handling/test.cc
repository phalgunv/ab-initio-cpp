#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "signalHandler.h"
using namespace std;

int main()
{
  int iret;

  try
  {
    SignalHandler signalHandler;

    // Register signal handler to handle kill signal
    signalHandler.setupSignalHandlers();

    // Infinite loop until signal ctrl-c (KILL) received
    while(1)
    {
        cout<<"Waiting for CTRL+C...\n";
        sleep(1);
    }
    cout<<"\n CTRL+C handled, gracefully exiting :)";
    iret = EXIT_SUCCESS;
  }
  catch (SignalException& e)
  {
    std::cerr << "SignalException: " << e.what() << std::endl;
    iret = EXIT_FAILURE;
  }
  return(iret);
}
