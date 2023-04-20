#include <stdio.h>

int main()
{
    int a[5] = {2000, 2001, 2002, 2003, 2004}; // int a[5] means that a is an array of 5 integers.

    printf("a[0]       : %d\n", a[0]);
    printf("*a         : %d\n", *a); // *a means that a is a pointer to an integer.
    printf("*(a+1)     : %d\n", *(a + 1));
    printf("*(&a[0])   : %d\n", *(&a[0]));     // *(&a[0]) means that a is a pointer to an integer. & means address of.
    printf("*(&a[0]+1) : %d\n", *(&a[0] + 1)); // *(&a[0]+1) means that a is a pointer to an integer. & means address of. +1 means next address.
    printf("a          : %p\n", a);            // %p is a placeholder for a pointer.
    printf("&a[0]      : %p\n", &a[0]);        // &a[0] means that a is a pointer to an integer. & means address of.
    printf("&a[0]+1    : %p\n", &a[0] + 1);
}
