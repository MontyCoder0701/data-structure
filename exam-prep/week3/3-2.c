#include <stdio.h>
#include <stdlib.h> // malloc means memory allocation, and is needed for dynamic memory allocation. It is defined in stdlib.h. The malloc.h is deprecated and should not be used.

void change_value(int *p, int *q)
{
    *p = 5;
    *q = 10;
}

int main()
{
    int *a, *b;              // initialize pointers
    a = malloc(sizeof(int)); // allocate memory for a.
    b = malloc(sizeof(int));
    *a = 10;
    *b = 20;
    change_value(a, b);
    printf("%d   %d", *a, *b); // dereferenced to access the value
}
