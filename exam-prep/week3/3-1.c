#include <stdio.h>
void add(int *a) // void means the function does not return anything.
{
    *a = *a + 10;
}

int main(void) // void in the parameter means the function does not take any arguments
{
    int a = 0;
    add(&a); // & and * cancels out each other. &a is the address of a, and *a is the value of a.
    printf("%d", a);
}
