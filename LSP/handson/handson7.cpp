/*
 * Observation:
 * Inspite of whatever  the input is, we are getting the specified file contents as output because once we duplicate the fd of file to 0, 0 will no longer refer to standard input. Henceread system call is taking contents from the file with fd 0 ie our specified file and writing it to standard output.
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
                int infd = open(cstr, O_RDONLY);
                int newinfd = dup2(infd, 0);
                int n = read(0, buff, SIZE);
                write(1, buff, n);
        }
        return 0;
}
