#include <stdio.h>
#include <string.h>

// 구조체 타입의 선언. The difference between typedef struct and struct is that the former creates an alias for a struct type, which can be used instead of the struct keyword to declare variables of the structure type, while the latter is used to declare the structure type itself.
typedef struct
{
    char name[10];
    int age;
    float salary;
} personType; // personType is an alias for struct

int main()
{
    personType mywife;       // declare a variable of type personType
    personType *p = &mywife; // declare a pointer variable of type personType. *p is the pointer, & is the address-of operator, and mywife is the variable.

    strcpy(mywife.name, "angela");
    p->age = 30; // p->age is the same as (*p).age.

    mywife.salary = 35000;

    printf("%d", p->age);      // 포인터를 사용해서 값 읽어오기. %d is a format specifier for int.
    printf("%f\n", p->salary); // 포인터를 사용해서 값 읽어오기. %f is a format specifier for float.
}
