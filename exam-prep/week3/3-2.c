#include <stdio.h>
#include <stdlib.h> // malloc means memory allocation, and is needed for dynamic memory allocation. It is defined in stdlib.h. The malloc.h is deprecated and should not be used.

void change_value(int *p, int *q)
{
    *p = 5;
    *q = 10;
}

int main()
{
    int *a, *b;              // a and b are pointers to integers. We can use them to store the addresses of integers.
    a = malloc(sizeof(int)); // malloc returns a pointer to the allocated memory. sizeof(int) is the size of the memory to be allocated in bytes.
    b = malloc(sizeof(int));
    *a = 10;
    *b = 20;
    change_value(a, b); // a and b are passed by reference, so the values of the variables pointed to by a and b are changed.
    printf("%d   %d", *a, *b);
}
