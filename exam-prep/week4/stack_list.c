#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

// Difference between array and list
// 1. Array is fixed size, but list is dynamic size
// 2. Array is contiguous, but list is not contiguous
// 3. Array is easy to access, but list is not easy to access

// A stack list is implemented using a linked list data structure.

int main(void)
{
    init();

    // 스택에 원소 넣기
    push('A');
    push('B');
    push('C');
    push('D');
    printStack();

    // 스택 원소 꺼내기
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printStack();

    // 스택에 원소 넣기
    push('O');
    push('P');
    printStack();

    // 스택 원소 꺼내기
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
    printf("스택에서 %c를 꺼냈습니다.\n", pop());
}