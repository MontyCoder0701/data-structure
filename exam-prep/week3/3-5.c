#include <stdio.h>

int total_value(int arr[], int n) // n is the number of elements in the array.
{
    int i, total = 0;

    for (i = 0; i < n; i++)
        total = total + arr[i];

    return total;
}

int main()
{
    int a[5] = {2, 3, 4, 3, 5};

    int total = total_value(a, 5);

    printf("%d", total);
}
