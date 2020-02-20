#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int stat;
    pid_t cpid;
    printf("hello world (pid: %d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "fork failed \n");
        exit(1);
    } else if (rc == 0) {
        printf("hello, I am child (pid: %d)\n", (int)getpid());
        cpid = wait(&stat);
    } else {
        printf("hello, I am parent (pid: %d)\n", (int)getpid());
        printf("I waited for my child: %d\n", (int)(cpid));
        printf("My child's exit status was %d\n", stat);
    }
    printf("\n");
    return 0;
}