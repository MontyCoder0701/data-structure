#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    char Data;
    struct _node *Next;
} nodeType;

int main()
{
    nodeType *head, *temp;

    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->Data = 'A';
    temp->Next = NULL;
    head = temp;
    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->Data = 'B';
    temp->Next = head;
    head = temp;
    temp = (nodeType *)malloc(sizeof(nodeType));
    temp->Data = 'C';
    temp->Next = head;
    head = temp;
}
