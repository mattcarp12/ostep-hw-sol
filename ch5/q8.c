#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int fd[2];
    char buffer[1024];
    int status;

    if(pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid_t p1 = fork();
    if (p1 < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (p1 == 0) {
        dup2(fd[1], STDOUT_FILENO);
        write(STDOUT_FILENO, "hello from child\n", 100);
    } else {
        pid_t p2 = fork();
        if (p2 < 0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (p2 == 0) {
            dup2(fd[0], STDIN_FILENO);
            read(STDIN_FILENO, buffer, 1024);
            fprintf(stdout, "%s\n", buffer);
            fprintf(stdout, "hello from second forked process [PID]%d\n", getpid());
        } else {
            wait(NULL);
            wait(NULL);
            printf("Hello from parent, [PID] %d\n", getpid());
        }
    }
}

/*
    Moral of the story:
    Use dup2 system call to duplicate a file descriptor,
    closing one then making a duplicate of it to another.
    In this program, we are using dup2 to close STDIN and
    STDOUT and replace those with two ends of a pipe.

*/