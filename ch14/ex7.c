#include <stdlib.h>

int main() {
    int *data = (int *)malloc(100 * sizeof(int));
    free(data + 42);

    return 0;
}

/*
    Moral of story:
        The above program produces a runtime error, but not compile time.
        The free needs to occur at the point the block was allocated, not
        inside the block. To achieve the same functionality may need
        to use realloc instead.
*/