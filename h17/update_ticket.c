#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
    struct flock lock;
    int buf;
    ssize_t numRead, numWrite;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    int fd = open("ticket_store.txt" , O_RDWR);
    if(fd == -1) perror("opening file\n");
    printf("Locking file\n");
    if(fcntl(fd, F_SETLKW , &lock) == -1) perror("locking write_lock\n");
    printf(" Inside Critical section\n");
    printf("Reading file data...\n");
    if((numRead = read(fd ,&buf , sizeof(int))) == -1) perror("read file\n");
    printf("ticket number: %d\n" , buf);
    printf("Incrementing & writing ticket number\n");
    buf++;
    if((numWrite = write(fd ,&buf , sizeof(int))) == -1) perror("write file\n");
    printf("Ticket number updated\n");
    
    printf("Reading the updated file\n");
    printf("-----------------------------\n");
    if(read(fd,&buf,sizeof(int))== -1) perror("reading updated ticket file\n");
    printf("Read after writing: %d\n",buf);
    printf("Press return to unlock\n");
    getchar();
    lock.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&lock);
    close(fd);
    printf("finish-----------");
    return 0;
    
    
    
}
