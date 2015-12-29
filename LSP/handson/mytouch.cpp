//set path using the following command:export PATH=$PATH:.
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<cstdlib>
#include<fcntl.h>
#include<utime.h>
#include<unistd.h>
using namespace std;

int main(int argc, char ** argv)
{
        if(!(strcmp(argv[0],"mytouch")))
        {
                int i;
                for(i = 1; i < argc; i++)
                {
                        if(!(access(argv[i],F_OK)))
                        {
                                utime(argv[i], NULL);
                        }
                        else
                        {
                                cout << "creating file " << argv[i] << endl;
                                int fd = creat(argv[i], 0664);
                                if(fd < 0)
                                        cout << "create error" << endl;
                        }
                }
        }
     else
                cout << "Please use the format \"mytouch file1 file2 file3 ....\"" << endl;
        return 0;
}
