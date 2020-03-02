#include <stdlib.h>

int main() {
    int *data = (int *)malloc(100 * sizeof(int));
    data[100] = 0;

    return 0;
}


/*
    Moral of story:
        Can access memory locations beyond what was allocaed,
        and compiler will allow and won't throw a runtime error.
        However this is bad practice and may corrupt other parts
        of the program.
*/