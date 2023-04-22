#include <stdio.h>

int main()
{
    short a[3] = {10, 20, 30};

    printf("%d", a[0]);
    printf("%d", a[1]);
    printf("%d", *a);       // *a == a[0]
    printf("%d", *(a + 1)); // *(a + 1) == a[1]
}
