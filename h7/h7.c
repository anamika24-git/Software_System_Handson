#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc , char *argv[]){
if(argc!=3)
printf("CLI must be in format -> %s ,sourceFile ,destinationFile" ,argv[0]);
ssize_t numRead , numWrite;
int inputfd = open(argv[1] , O_RDONLY); // source file fd
int outputfd = open(argv[2] , O_WRONLY | O_CREAT , 0744); //destination file fd
char buffer;
int count = 1;

while( (numRead = read(inputfd , &buffer , count)) > 0)
{
numWrite = write(outputfd , &buffer , count);
if(numWrite == -1 || numWrite != numRead)
perror("error while writing file");

}
if(numRead == -1)
perror("error while reading file");
close(inputfd);
close(outputfd);
return 0;
}

