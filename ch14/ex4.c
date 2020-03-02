#include <stdlib.h>

int main() {
    int *myint_p = (int *)malloc(10 * sizeof(int));

    return 0;
}

/*
    Moral of story:
        If a program does not explicitly free alloc'd blocks,
        they will automatically be reclaimed by the OS 
        after the program finishes running.
*/