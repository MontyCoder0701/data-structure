#include <stdio.h>

void proc(int x, int y, int *z)
{
    y = y + 10;
    *z = *z + y;
    printf("x=%d y=%d *z=%d\n", x, y, *z);
}

int main()
{
    int a = 4, b = 5;
    proc(a, b, &a);
    printf("a=%d b=%d\n", a, b);
}