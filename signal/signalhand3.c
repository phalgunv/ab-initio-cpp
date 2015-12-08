#include <signal.h>
#include <stdio.h>

/* or you might use a semaphore to notify a waiting thread */
static volatile sig_atomic_t sig_caught = 0;

void handle_sighup(int signum) 
{
    /* in case we registered this handler for multiple signals */ 
    if (signum == SIGHUP) {
        sig_caught = 1;
    }
}

int main(int argc, char* argv[]) 
{
    /* you may also prefer sigaction() instead of signal() */
    signal(SIGHUP, handle_sighup);

    while(1) {
        if (sig_caught) {
            sig_caught = 0;
            printf("caught a SIGHUP.  I should re-read settings.\n");
        }
    }

    return 0;
}
