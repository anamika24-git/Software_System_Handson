#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void append_file(int fd , const char *message) {
    if(write(fd , message , strlen(message)) == -1){
        perror("Error on writing file");
        exit(1);
    }
}
int main(){
    
    int old_fd = open("source_h11.txt" ,O_WRONLY |O_TRUNC , 0644);
    printf("old_dup %d\n" , old_fd);
    int newfd_dup = dup(old_fd);
    printf("newfd_dup %d\n" , newfd_dup);
    append_file(old_fd , "..old file descriptor for dup");
    append_file(newfd_dup , "..New file descriptor using dup");
    int newfd_dup2 = dup2(old_fd , 6);
    printf("newfd_dup2 %d\n" , newfd_dup2);
    append_file(old_fd , "..old file descriptor for dup2");
    append_file(newfd_dup2 , "..New file descriptor using dup2");
    int newfd_fcntl  = fcntl(old_fd , F_DUPFD , 0);
    printf("newfd_fcntl %d\n" , newfd_fcntl);
    append_file(old_fd , "..old file descriptor for fcntl");
    append_file(newfd_fcntl , "..New file descriptor using fcntl");
    
    
    //if(numread == -1) perror("Error while reading file");
    close(old_fd);
    close(newfd_dup);
    close(newfd_dup2);
   close(newfd_fcntl);
    
}
