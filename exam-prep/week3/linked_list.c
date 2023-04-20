#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{

    nodeType *head, *temp; // head는 첫번째 노드를 가리키는 포인터, temp는 새로 생성된 노드를 가리키는 포인터

    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->item = 'A';
    temp->next = NULL; // 생성된 노드의 next는 NULL을 가리킴
    head = temp;       // 생성된 노드를 첫번재 노드로 지정

    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->item = 'B';
    temp->next = NULL;
    insertNext(head, temp); // 생성된 노드를 삽입. (A, B 순서로 삽입됨)

    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->item = 'C';
    temp->next = NULL;
    insertNext(head, temp); // 생성된 노드를 삽입. (B, C 순서로 삽입됨)

    printList(head);

    removeNext(head); // 첫번째 노드의 다음 노드를 삭제
    printList(head);
}
