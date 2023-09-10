#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd = creat("file1.txt", O_RDWR);
	fd = creat("file2.txt", O_RDWR);
	fd = creat("file3.txt", O_RDWR);
	fd = creat("file4.txt", O_RDWR);
	fd = creat("file5.txt", O_RDWR);
	for(;;){}

	return 0;
}
