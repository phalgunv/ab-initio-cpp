#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#define MAX 100
using namespace std;

enum DIRECTION {IN, OUT};
int a[] = {1,2,3,4,5,6,7,8,9,10,11};
int k = 0, r;
int child_fd[2];
int parent_fd[2];

int findsum(int l, int r, int j, int i)
{
    int sum[MAX] = {0};
    int c = 0;
    for(; c < l; i++)
    {
        sum[j] = sum[j] + a[i];
        c++;
    }

    if((r != 0) && (i <= l))
    {
        for(int k = 0; k < r; k++)
        {
            sum[k] = sum[k] + a[i];
            i++;
        }
    }
    cout << "the ------sum------- of process "<< j <<  " is " << sum[j] << endl;
    return i;
}

/*void doparent(int p)
{

            if(p > 0){
            cout << "is this executing " << endl;
            close(fd[P2_READ]);
            close(fd[P2_WRITE]);
            read(fd[P1_READ], &k, sizeof(k));
            cout << "value received from child " << k << endl;
            write(fd[P1_WRITE], &k, sizeof(k));
            cout << "value copied to child " << k << endl;
            close(fd[P1_READ]);
            close(fd[P1_WRITE]);}
}*/
void forkChild(int n)
{
    int pid[n];
    int l = 11/n; 
    int buff;	
    int rem = 11 % n;
    int sum[MAX] = {0};
    pipe(child_fd);
    pipe(parent_fd);

    for(int j = 0; j < n; j++)
    {
        int status;
        pid[j] = fork();
        if(pid[j] == 0)
        {
            cout << "********Child " << j << " with pid " << getpid() << " created *********"<< endl;
            if(j == 0)
            {  
                r = findsum(l, rem, j, k);
                write(child_fd[OUT], &r, sizeof(r));
                return;
            }
            else
            {
		read(parent_fd[IN], &k, 4);
                r = findsum(l, rem, j, k);
		cout << "return value is " << r << endl;
                write(child_fd[OUT], &r, sizeof(r));
                return;
            }
        }
        else
        {
            read(child_fd[IN], &buff, 4);
            write(parent_fd[OUT], &buff, 4);
            cout << "parents block:::" << pid[j] << endl;
            waitpid(pid[j], &status, WUNTRACED);

        }
    }
}
int main()
{
    forkChild(4);
    return 0;
}
