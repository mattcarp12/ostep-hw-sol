#include <stdlib.h>

int main() {
    int *data = (int *)malloc(100 * sizeof(int));
    free(data);
    data[42] = 100;

    return 0;
}

/*
    Moral of story:
        Even after a block of memory is freed,
        it can still be written to, but valgrind
        will report this as an invalid write.
*/