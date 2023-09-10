#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    int i, fd;
    struct {
        int rollno;
        int marks;
    } db[3];

    for (i=0;i<3;i++){

        db[i].rollno=i+1;
        db[i].marks=10;
    }
    fd = open ("data.txt", O_RDWR|O_CREAT, 0666);
    write(fd, &db, sizeof(db));
    close(fd);
    return 0;
}
