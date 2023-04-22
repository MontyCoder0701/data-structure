#include <stdio.h>

int sum(int *a, int size)
{
    int i, sum = 0;

    for (i = 0; i < size; i++)
    {
        sum = sum + *a; // *(score) == score[0]
        a = a + 1;      // +1 increments the address. (score+1 == &score[1])
    }

    return sum;
}

int main()
{
    int total, score[3] = {98, 92, 88}; // int score[3] means that score is an array of 3 integers.

    total = sum(score, 3);
    printf("합계는 : %d\n", total);
}
