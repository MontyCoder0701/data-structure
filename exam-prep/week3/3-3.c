#include <stdio.h>

void swap(int *x, int *y)
{
    int *temp; // temp is a pointer to an integer. It is not initialized, so it is pointing to an unknown location in memory.
    temp = x;  // temp is now pointing to the same location as x.
    x = y;     // x is now pointing to the same location as y.
    y = temp;  // y is now pointing to the same location as temp.
}

int main()
{
    int a = 10, b = 20;
    swap(&a, &b);            // a and b are passed by reference, so the values of the variables pointed to by a and b are changed.
    printf("%d   %d", a, b); // The problem is that the swapping is being done on the pointers themselves, not the values they point to.
}
