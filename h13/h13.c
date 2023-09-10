#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO , &readfds);
    struct timeval timeout;
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;
    int n = select(STDIN_FILENO+1 , &readfds , NULL , NULL ,&timeout);
    if(n == -1){
        perror("error while select call");
    }
    else if(n > 0) {
       if( FD_ISSET(STDIN_FILENO , &readfds))
           printf("STDIN_FILENO is ready to print");
    }
    else
        printf("Time limit exceeded");
    
    return 0;
    
}
