#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
#define MAX 100
using namespace std;
int a[] = {1,2,3,4,5,6,7,8,9,10,11};
        int k = 0, r;
int fd1[2];
int fd2[2];
int findsum(int l, int r, int j, int i)
{
        int sum[MAX] = {0};
        int c = 0;
        for(; c < l; i++)
        {
                cout << "value of i is " << i << endl;
                cout << "in for loop j :::: value of a[i] " << a[i] << endl;
                sum[j] = sum[j] + a[i];
                c++;
               // cout << "sum[j] inside for loop " << sum[j] << endl;
               // cout << "count is " << c << endl;
        }
if((r != 0)&& (i <= l)){
                for(int k = 0; k < r; k++)
                {
                        sum[k] = sum[k] + a[i];
                        i++;
                       // cout << "sum[j] inside for loop " << sum[j] << endl;
                }
        }
       // cout << "Value of i is " << i << endl;
        cout << "the sum of process "<< j <<  "is " << sum[j] << endl;
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
        int pid[n];//int k = 0, r;
        int l = 11/n; int buff;	
        int rem = 11 % n;
        int sum[MAX] = {0};pipe(fd1);pipe(fd2);
        for(int j = 0; j < n; j++)
        {
                int status;
                //int     fd[2];
                pid[j] = fork();
                if(pid[j] == 0)
                {
                        cout << "Child " << j << "with pid " << getpid() << endl;
                        if(j == 0)
                        {       r = findsum(l, rem, j, k);
                                write(fd1[1], &r, sizeof(r));
                                return;
     			}
                        else
                        {
				//if(j == 1)
				read(fd2[0], &k, 4);
                                r = findsum(l, rem, j, k);
				cout << "return value is " << r << endl;
                                write(fd1[1], &r, sizeof(r));
				//read(fd2[0], &k, 4);
				//cout << "value from parent is " << k << endl;
                                return;
                         }
		}
                else
                {
                        read(fd1[0], &buff, 4);
                        cout << "value received from child " << buff << endl;
                        write(fd2[1], &buff, 4);
                        //cout << "value copied to child " << k << endl;
//                      wait(&status);
                        cout << "parents block:::" << pid[j] << endl;

                         waitpid(pid[j], &status, WUNTRACED);

                }
        }
}
int main()
{
        forkChild(5);
        return 0;
}
