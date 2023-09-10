#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    if(argc!=2){
        printf("Please enter 1 filename as parameter\n");
        return 0;
    }
    struct stat sb;
    if (lstat(argv[1], &sb) == -1) {
               perror("Unable to retrieve data with lstat.\n");
    }
    printf("File type: ");


           if S_ISBLK(sb.st_mode) printf("block device\n");
           else if S_ISCHR(sb.st_mode) printf("character device\n");
           else if S_ISDIR(sb.st_mode)  printf("directory\n");
           else if S_ISFIFO(sb.st_mode)  printf("FIFO/pipe\n");
           else if S_ISLNK(sb.st_mode)  printf("symlink\n");
           else if S_ISREG(sb.st_mode)  printf("regular file\n");
           else if S_ISSOCK(sb.st_mode) printf("socket\n");
            else printf("unknown Type\n");
    
    return 0;
}
