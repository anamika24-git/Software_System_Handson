#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<stdlib.h>
int main(){
    int fd = open("h4.txt",O_RDWR);
    printf("File Descriptor: %d\n",fd);

    int fd2 = open("h4.txt",O_EXCL|O_CREAT|O_RDWR);
    if(fd2 == -1){
        perror("file alrady exist, error by O_EXCL flag");
        exit(1);
    }
        printf("File Descriptor 2: %d\n",fd2);

    close(fd);
    close(fd2);
    return 0;
}
