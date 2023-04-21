#include <stdio.h>
void add(int *a) // void means the function does not return anything
{
    *a = *a + 10; // *a is the value of the integer pointed to by a
}

int main(void) // void in the parameter means the function does not take any arguments
{
    int a = 0;
    add(&a); // &a is the address of a. This is calling by reference so it changes the original value.
    printf("%d", a);
}
