#include <stdio.h>

int sum(int *a, int size) // a[] is used to access array elements, while *a is used to access the value pointed to by a pointer variable.
{
    int i, sum = 0;

    for (i = 0; i < size; i++)
    {
        sum = sum + *a;
        a = a + 1; // a++ is also possible. a+1 means next address.
    }

    return sum;
}

int main()
{
    int total, score[3] = {98, 92, 88};

    total = sum(score, 3);
    printf("합계는 : %d\n", total);
}
