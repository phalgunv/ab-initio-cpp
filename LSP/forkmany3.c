#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void forkChildren (int nChildren) {
    int i; int par = getpid();
	printf("%d \n ",  par);// << endl;
    pid_t pid;
    for (i = 1; i <= nChildren; i++) {
        pid = fork();
        if (pid == -1) {
            /* error handling here, if needed */
            return;
        }
        if (pid == 0) {
            printf("I am a child: %d PID: %d with parent id %d \n",i, getpid(), getppid());
           // sleep (5);
            return;
        }
    }
}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        forkChildren (2);
    } else {
        forkChildren (atoi (argv[1]));
    }
    return 0;
}
