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
    personType *p = &mywife; // declare a pointer variable that is dereferenced to access the value, which has the same value of the address of mywife.

    strcpy(mywife.name, "angela");
    p->age = 30; // p->age is the same as (*p).age.

    mywife.salary = 35000;

    printf("%d", p->age);      // 포인터를 사용해서 값 읽어오기. %d is a format specifier for int.
    printf("%f\n", p->salary); // 포인터를 사용해서 값 읽어오기. %f is a format specifier for float.
}

// The main difference between call by value and call by reference is that in call by value, a copy of the value of the argument is passed to the function, while in call by reference, the memory address of the argument is passed to the function.
// call by value
void increment(int x)
{
    x++;
}

int call_by_value()
{
    int num = 10;
    increment(num);
    printf("%d", num); // output: 10. In call by value, a copy of the value of the argument is passed to the function. Any changes made to the parameter within the function do not affect the original value of the argument passed from outside the function.
    return 0;
}

int call_by_reference()
{
    int num = 10;
    increment(&num);
    printf("%d", num); // output: 11. On the other hand, in call by reference, the memory address of the argument is passed to the function, and any changes made to the parameter within the function affect the original value of the argument passed from outside the function.
    return 0;
}
