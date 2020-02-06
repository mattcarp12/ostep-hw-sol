#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int x = 100;
    printf("hello world (pid: %d)\n", (int)getpid());
    printf("Parent process (before fork): x = %d\n", x);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d)\n", (int)getpid());
        printf("Child process: x = %d\n", x);
        printf("**Changing value of x**\n");
        x = 200;
        printf("Child process: x = %d\n", x);
    } else {
        int rc_wait = wait(NULL);
        printf("hello, I am parent (pid: %d)\n", (int)getpid());
        printf("Parent process (after fork): x = %d\n", x);
        printf("**Changing value of x**\n");
        x = 300;
        printf("Parent process (after fork, after change): x = %d\n", x);
    }
    return 0;
}