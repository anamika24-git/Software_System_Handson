#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
    #include <sys/uio.h>
    #include <unistd.h>
int main(){
    char buf[10];
    int fd = open("h10.txt" ,O_RDONLY);
    ssize_t numRead , outWrite;
    //int fd1 = creat("STDOUT_FILENO" , 0744);
     numRead = read(fd,buf,10);
     outWrite = write(STDOUT_FILENO, buf,10);
    off_t offset = lseek(fd, 10, SEEK_CUR);
    printf("\n The current cursor pointing to %lld: " , offset);
    numRead = read(fd,buf,10);
    outWrite = write(STDOUT_FILENO, buf,10);
	return 0;
    
}

//od t -x A -n "filename"
