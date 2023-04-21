#include <stdio.h>
struct student
{
    char s_num[5];   // 번호
    char s_name[10]; // 이름
    int year;        // 입학년도
};

int main()
{
    struct student a = {"S001", "Peter", 2021};
    struct student b = {"S002", "Jane", 2022};
    if (a.year >= b.year) // . is used to access the members of a struct.
        printf("%s\n", a.s_name);
    else
        printf("%s\n", b.s_name);
}
