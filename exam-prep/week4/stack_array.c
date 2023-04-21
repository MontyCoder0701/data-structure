#include <stdio.h>
#include "stack_array.h"

// Stack implemented with array

int main()
{
    stackType st1; // 스택 생성
    init(&st1);    // 스택 초기화

    // 스택에 원소 넣기
    push(&st1, 1);
    push(&st1, 2);
    push(&st1, 3);
    push(&st1, 4);
    push(&st1, 5);
    push(&st1, 6);
    push(&st1, 7);
    push(&st1, 8);
    push(&st1, 9);
    push(&st1, 10);
    push(&st1, 11);   // 스택이 꽉 차서 넣을 수 없음
    printStack(&st1); // 스택 내용 전체 출력

    // 스택 원소 꺼내기
    printf("스택에서 %d을 꺼냈습니다.\n", pop(&st1));
    printf("스택에서 %d을 꺼냈습니다.\n", pop(&st1));
    printf("스택에서 %d을 꺼냈습니다.\n", pop(&st1));
    printf("스택에서 %d을 꺼냈습니다.\n", pop(&st1));
    printStack(&st1); // 스택 내용 전체 출력
}
