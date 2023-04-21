#include <stdio.h>
#include <stdlib.h>
#include "queue_list.h"

// Queue made with linked list

int main(void)
{
    init();

    // 큐에 원소 넣기
    insert('A');
    insert('B');
    insert('C');
    insert('D');
    printQueue();

    // 큐 원소 꺼내기
    printf("큐에서 %c를 꺼냈습니다.\n", delete ());
    printf("큐에서 %c를 꺼냈습니다.\n", delete ());
    printQueue();

    // 큐에 원소 넣기
    insert('O');
    insert('P');
    printQueue();
}
