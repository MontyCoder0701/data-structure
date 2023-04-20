#include <stdio.h>
#include <string.h> // string.h is needed for strcpy function

struct Person
{                  // 구조체 person의 선언
    char name[10]; // When a character array is declared, a fixed amount of memory is allocated for it based on the size of the array.
    int age;
    float salary;
};

int main()
{
    struct Person person1;         // 구조체 변수 person1의 선언
    strcpy(person1.name, "james"); // strcpy means string copy. character arrays are not first-class objects, meaning that they cannot be assigned values using the assignment operator.
    person1.age = 10;              // person.age에 값 저장
    person1.salary = 35000;        // person.salary에 값 저장

    printf("%s %d %f\n", person1.name, person1.age, person1.salary);
}
