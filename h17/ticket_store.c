#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    const char *file_path = "ticket_store.txt";
    int ticket_number = 100;  // Initial ticket number

    int fd = open(file_path, O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    struct flock lock;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_type = F_WRLCK; // Set a write lock

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Error setting write lock");
        close(fd);
        return 1;
    }

    // Store the ticket number in the file
    write(fd, &ticket_number, sizeof(int));

    printf("Ticket number %d stored.\n", ticket_number);

    lock.l_type = F_UNLCK; // Release the lock
    fcntl(fd, F_SETLKW, &lock); // Unlock the file
    close(fd);

    return 0;
}
