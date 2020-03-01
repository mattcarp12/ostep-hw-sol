#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *mystring = "I am a statically allocated string";

int main(int argc, char *argv[]) {

    int mem_alloc_mb = atoi(argv[1]);
    printf("[%d] You specified to allocate %d mb of memory.\n", getpid(), mem_alloc_mb);
    int n = 1e6 * mem_alloc_mb / sizeof(int);
    int *int_array = malloc(n * sizeof(int));

    if (int_array == NULL) {
        perror("MALLOC FAILED");
        return -1;
    }

    while (1) {
        for(int i = 0; i < n; i++) {
            int_array[i] = i;
        }
        usleep(1e3);
    }

    return 0;
}