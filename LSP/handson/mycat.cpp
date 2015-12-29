#include<iostream>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<cstdlib>
#include<cstring>
#include<fcntl.h>
#define bufsize 1024
using namespace std;

int filecopy(int infd, int outfd, int size)
{
        char *buf = new char[size];
        int n = read(infd, buf, size);
        int val = write(outfd, buf, n);
        delete [] buf;
        return 0;
}

int main(int argc, char ** argv)
{
        int ret, infd;
        int compare = strcmp(argv[0],"./mycat");
        if(argc == 1 && !(compare))
        {
                while(1)
                {
                ret = filecopy(0, 1, bufsize);
                if(ret == 0)
                        return 0;
                else
                        return -1;
                }
        }
        else if(argc == 2 && !(compare))
        {
                struct stat fileStat;
                int exists = stat(argv[1], &fileStat);
                if(!(exists))
                {
                        infd = open(argv[1], O_RDONLY);
                        int len = fileStat.st_size;
                        int ret = filecopy(infd, 1, len);
                        if(ret == 0)
                                exit(0);
                        else if(ret < 0)
                                exit(1);
                        else
                                exit(EXIT_FAILURE);
                }
                else
                        cout << argv[1] << "does not exist" << endl;
        }
        else
                cout << "use the following syntax: for one argument --> ./mycat \nfor two arguments --> ./mycat filename" << endl;
        return 0;
}
