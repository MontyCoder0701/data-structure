#include <stdio.h>

int smaller(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int a = 100, b = 200;
    printf("%d", smaller(a, b));
}