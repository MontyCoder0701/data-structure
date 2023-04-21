#include <stdio.h>

int func_add(int *a, int *b)
{
    int result;
    a = a + 1;
    b = b + 1;
    result = *a + *b; // result is the sum of the second elements of the arrays pointed to by a and b (since +1)
    return result;
}

int main()
{
    int a[4] = {10, 20, 30, 40};
    int b[4] = {100, 200, 300, 400};
    int result;
    result = func_add(a, b); // a and b are passed by reference (*a, *b), so the values of the variables pointed to by a and b are changed.
    printf("%d", result);
}
