#include<stdio.h>
#include <fcntl.h>
int main(){
    int fd = creat("h3.txt" , O_RDWR);
    if(fd == -1) perror("error while creating file descriptor");
    else printf("file descriptor value: %d" , fd);
    return 0;
}
