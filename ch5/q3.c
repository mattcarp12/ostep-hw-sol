#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("hello world (pid: %d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d)\n", (int)getpid());
    } else {
        sleep(1);
        printf("hello, I am parent (pid: %d)\n", (int)getpid());
    }
    printf("\n");
    return 0;
}

/*
    Moral of the story:
    If the parent thread sleeps, or does IO,
    the child process will run. 
*/