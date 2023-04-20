#include <stdio.h>
#include "queue_array.h"

// Queue made using array

int main()
{
    // q1 이름을 가진 큐 생성
    queueType q1;
    init(&q1); // 초기화

    // 큐에 원소 넣기
    insert(&q1, 10);
    insert(&q1, 20);
    insert(&q1, 30);
    insert(&q1, 40);
    insert(&q1, 50);
    insert(&q1, 60);
    insert(&q1, 70);
    // 큐 내용 전체 출력
    queuePrint(&q1);

    // 큐 원소 꺼내기
    printf("큐에서 %d을 꺼냈습니다.\n", delete (&q1));
    printf("큐에서 %d을 꺼냈습니다.\n", delete (&q1));
    printf("큐에서 %d을 꺼냈습니다.\n", delete (&q1));

    // 큐에 원소 넣기
    insert(&q1, 80);
    insert(&q1, 90);

    // 큐 내용 전체 출력
    queuePrint(&q1);
}
