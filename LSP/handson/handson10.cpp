#include<iostream>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

void gotorec(int fd, int recno, int reclen)
{
        int pos = lseek(fd, (recno*reclen), SEEK_SET);
        cout << "fd position is " << pos << endl;
}


int main()
{
        int fd;
        char buf[20];
        fd = open("sample.dat", O_RDONLY);
        gotorec(fd, 3, 10);     // read 3rd record
        read(fd, buf, 10);
        write(1, buf, 10);
        gotorec(fd, 5, 10);
        read(fd, buf, 10);
        write(1, buf, 10);
}

//sample.dat
//
//1234567890
//abcdefghij
//ABCDEFGHIJ
//ONETWOthre
//diszrcrd05
