#include <stdio.h>
void add(int *a) // void means the function does not return anything
{
    *a = *a + 10;
}

int main(void) // void in the parameter means the function does not take any arguments
{
    int a = 0;
    add(&a);
    printf("%d", a);
}
