#include <stdio.h>

int func_add(int *a, int *b)
{
    int result;
    a = a + 1; // a+1 increments the address. (a+1 == &a[1])
    b = b + 1; // b+1 increments the address. (b+1 == &b[1])
    result = *a + *b;
    return result;
}

int main()
{
    int a[4] = {10, 20, 30, 40};
    int b[4] = {100, 200, 300, 400};
    int result;
    result = func_add(a, b);
    printf("%d", result);
}
