#include<iostream>
#include<cstdlib>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<cstring>

using namespace std;

int readline(int fd, char* buff, int len)
{
        if(fd)
        {
                int n = read(fd, buff, len);
                write(1, buff, n);
        }
        else
                write(1, buff, len);
        return 0;
}

int main()
{
        string str;
        cout << "Enter a filename or some text" << endl;
        getline(cin, str);
        char * c = new char(str.length()+1);
        strcpy(c,str.c_str());
        struct stat fileStat;
        int file = stat(c, &fileStat);
        if(file == 0)
        {
                int fd = open(c, O_RDONLY);
                int len = fileStat.st_size;
                char buff[len];
                cout << "You have entered a file name " << c << endl;
                cout << "The contents of the file are:" << endl;
                int ret = readline(fd, buff, len);
                if(ret == 0)
                        exit(0);
                else
                        exit(-1);
        }
        else
        {
                cout << "You have entered: " << endl;
                int ret = readline(0, c, strlen(c));
                if(ret == 0)
                        exit(0);
                else
                        exit(-1);
        }
}
