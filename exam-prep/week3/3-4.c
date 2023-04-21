#include <stdio.h>

int main()
{
    short a[3] = {10, 20, 30};

    printf("%d", a[0]);
    printf("%d", a[1]);
    printf("%d", *a); // a is a pointer to the first element of the array.
    printf("%d", *(a + 1));
}
