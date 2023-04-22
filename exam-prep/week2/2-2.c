#include <stdio.h>

int main()
{
    int a[5] = {2000, 2001, 2002, 2003, 2004}; // int a[5] means that a is an array of 5 integers.

    printf("a[0]       : %d\n", a[0]); // 0 is the address of the first element in an array.
    printf("*a         : %d\n", *a);   // Dereferences pointer to access value == a[0]
    printf("*(a+1)     : %d\n", *(a + 1));
    printf("*(&a[0])   : %d\n", *(&a[0]));     // The address of the first element, then dereferences it to access value. (& and * cancel out each other)
    printf("*(&a[0]+1) : %d\n", *(&a[0] + 1)); // +1 means next address.
    printf("a          : %p\n", a);            // %p is a placeholder for a pointer.
    printf("&a[0]      : %p\n", &a[0]);
    printf("&a[0]+1    : %p\n", &a[0] + 1);
}

// Variable is a name that represents a value.
// Array is a variable that stores multiple values of the same type.
// Pointer is a variable that stores the address of another variable.
// Dereferencing a pointer means accessing the value at the address it is pointing to. (Not declaration)
// Address is a number that represents the location of a variable in memory.