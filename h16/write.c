#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/file.h>
int main(int argc , const char *argv[]){
    if(argc != 2){
        printf("Please check your argument, must be 2");
        exit(1);
    }
    int fd = open(argv[1] , O_WRONLY);
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("Before entering into critical section \n") ;
    if(fcntl(fd, F_SETLKW, &lock) == -1){
        perror("error while file locking \n");
    }
    printf("Inside Critical Section \n");
    printf("Writing to the file...\n");
    printf("Xxxxxxxxxxxxxxxxxxxxxxxxxxxxx...\n");
    printf("Enter to unlock \n");
    getchar();
    printf("Unlocked \n");
    lock.l_type = F_UNLCK;
    if(fcntl(fd, F_SETLK, &lock) == -1 ) {
        perror("error while file unlocking");
    }
    printf("finished");
    return 0;
}
