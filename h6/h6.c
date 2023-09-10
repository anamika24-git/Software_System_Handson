#include<stdio.h>
#include <sys/types.h>
 #include <sys/uio.h>
 #include <unistd.h>
#define count 1024
int main(){
// stdin desc 0 and stdout desc 1
char buf[count];
ssize_t inputRead, outputWrite;
while((inputRead = read(STDIN_FILENO,buf,count))>0) {

        outputWrite = write(STDOUT_FILENO,buf,count);
	if(outputwrite != inputRead) 
		perror("error while writing file");
}

if(inputRead == -1){
 perror("error while reading  file");
}
return 0;

}
