#include<stdio.h>
#include<sys/stat.h>
#include<time.h>
int main(){
struct stat filestat;
//struct stat *filestat_ptr = &filestat;
const char *filename = "h9.txt";
int n = stat(filename , &filestat);
if(n == 0) {
    printf("FILE NAME : %s \n" , filename);
	printf("inode no. %lu \n" ,(unsigned long)filestat.st_ino );
	printf("number_hardlinks  %lu \n" ,(unsigned long) filestat.st_nlink );
	printf("uid %lu \n" ,(unsigned long)filestat.st_uid);
	printf("gid %lu \n" ,(unsigned long)filestat.st_gid);
	printf("size %lu \n" ,(unsigned long)filestat.st_size);
	printf("block_size %lu \n" ,(unsigned long)filestat.st_blksize);
	printf("number_of_blocks %lu \n" ,(unsigned long)filestat.st_blocks);
    printf("time_of_last_access %lu \n" ,(unsigned long)filestat.st_atime);
    printf("time_of_last_modification %lu \n" ,(unsigned long)filestat.st_mtime);
    printf("time_of_last_change %lu \n" ,(unsigned long)filestat.st_ctime);
}
else
	perror("stat call fail");
}
