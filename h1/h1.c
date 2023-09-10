#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (symlink(argv[1], argv[2]) == -1) {
        perror("failed to create symlink");
        exit(1);
    }

    if (link(argv[1], argv[3]) == -1) {
        perror("failed to create hardlink");
        exit(1);
    }

    if (mkfifo(argv[4], 0666) == -1) {
        perror("failed to create mkfifo");
        exit(1);
    }

    return 0;
}







