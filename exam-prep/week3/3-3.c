#include <stdio.h>

void swap(int *x, int *y) // dereferenced to access the value
{
    int *temp; // intialize pointer
    temp = x;  // temp is now pointing to the same location as x.
    x = y;     // x is now pointing to the same location as y.
    y = temp;  // y is now pointing to the same location as temp.
}

int main()
{
    int a = 10, b = 20;
    swap(&a, &b);            // & and * cancels out each other.
    printf("%d   %d", a, b); // The problem is that the swapping is being done on the pointers themselves, not the values they point to.
}
