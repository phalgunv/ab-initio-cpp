/*
 * Observation:
 * The input which we enter is being over written in the specified filename because once we duplicate the fd of file to 1, 1 will no longer refer to standard output. Hence the input is being written to the file with descriptor 1 ie the specified file.
 * */
#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<string>
#include<cstring>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define SIZE 1024
using namespace std;

int main()
{
        string str;
        cout << "Enter  file name" << endl;
        getline(cin, str);
        char * cstr = new char(str.length()+1);
        strcpy(cstr, str.c_str());
        if(access(cstr, F_OK))
                cout << cstr << "file doesnot exists" << endl;
        else
        {
                char buff[SIZE];
                int infd = open(cstr, O_WRONLY);
                int newinfd = dup2(infd, 1);
                int n = read(0, buff, SIZE);
                write(1, buff, n);
        }
        return 0;
}
