// Please set the path using the following  ----> export PATH=$PATH:.
#include<errno.h>
#include<cstring>
#include<unistd.h>
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<cstdlib>
using namespace std;

int main(int argc, char ** argv)
{
  struct stat fileStat;
  if(!(strcmp(argv[0],"copy")))
  {
    if(argc == 3)
    {
	cout << "argc == 3" << endl;
      int sexists = (stat(argv[1],&fileStat));
      if(access(argv[2],F_OK) && !sexists)
      {
        int l1 = fileStat.st_size;
        char buff[l1];
        int fds = open(argv[1], O_RDONLY);
        int fdd = creat(argv[2], 666);
        int len = read(fds, buff, l1);
        write(fdd, buff, len);

      }
      else
      {
        if( access(argv[2], F_OK) == 0)
          cout << argv[2] << " file already exists. To overwrite use -f " << endl;
        else if(sexists)
          cout << argv[1] << " file doesnot exist" << endl;
        exit(0);
      }
    }
    if(argc == 4)
    {
	cout << "argc == 4" << endl;
      int exists = stat(argv[2],&fileStat);
      if( !(strcmp(argv[1],"-f")) && !(access(argv[3], F_OK)) && !exists)
      {
        int l2 = fileStat.st_size;
        char buff[l2];
        int fds = open(argv[2], O_RDONLY);
        int fdd = open(argv[3], O_TRUNC | O_RDWR);
        int len = read(fds, buff, l2);
        write(fdd, buff, len);
      }
      else
      {
        if(argc != 4)
          cout << "Please enter only 4 arguments" << endl;
        else if(strcmp(argv[1], "-f"))
          cout << "please use -f only" << endl;
        else if(exists)
          cout <<  argv[2] << " file doesnot exist" << endl;
        else
          cout << argv[3] << " file doesnot exist. Use copy source destinationformat " << endl;
        exit(0);
      }
    }
	if(argc > 4)
		{
			cout << "argc > 4. no of args is "  << argc << argv[argc-1] << " is last argument "<< endl;
			mkdir(argv[argc-1], 0777);
			//char* path = getcwd(path, 4);
			//cout << "path using getcwd " << path << endl;
			for(int i = 1; i < argc-1; i++)
			{
				cout << "In for" << endl;
				int val = stat(argv[i], &fileStat);
				int val1 = access(argv[i], F_OK);
				cout << "access value for " << argv[i] << " is " << val1 << endl;
				cout << "i is" << i << endl;
				if(val1)
				{
					cout << "errno is " << strerror(errno) << endl;
					cout << argv[i] << " file does not exists" << endl;
					exit(0);
				}
       				 else
				{
					int l3 = fileStat.st_size;
					char buff[l3];
        				int fds = open(argv[i], O_RDONLY);
					//cout << "before chdir" << endl;
					//system("pwd");
        				chdir(argv[argc-1]);//cout << "agter chdir to last argument" << endl;
					//system("pwd");
					int fdd = creat(argv[i], 777);
        				int len = read(fds, buff, l3);
        				write(fdd, buff, len);
					//chdir(path);
					//system("pwd");
				        chdir("..");
				}
 			}
		}
}
  else
    cout << "Please use 'copy soucefile destinationfile' format" << endl;
	system("pwd");
}
