#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid: %d)\n", (int)getpid());
    int file = open("test.txt", O_RDWR | O_CREAT);
    int rc = fork();
    char buf[512];
    if (rc < 0) {
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d)\n", (int)getpid());
        while(read(file, buf, 512)) {
            printf("%d\n", lseek(file, 0, SEEK_CUR));
            printf("%s", buf);
        }
        write(file, "hello from child!\n", 19);
        close(file);
    } else {
        int rc_wait = wait(NULL);
        printf("hello, I am parent (pid: %d)\n", (int)getpid());
        printf("%d\n", lseek(file, 0, SEEK_CUR));
        while(read(file, buf, 512)) {
            printf("%d\n", lseek(file, 0, SEEK_CUR));
            printf("%s\n", buf);
        }
        close(file);
    }
    printf("\n");
    return 0;
}

/*
    Moral of the story:
    The child process receives a copy of the file descriptor.
    However, the file position is shared between the two.
*/