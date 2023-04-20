#define MaxStackSize 100 // 스택의 최대 크기

typedef struct node
{
    char data;
    struct node *next; // 다음 노드를 가리키는 포인터 (linked list)
} nodeType;            // 노드타입 정의

// Top을 가리키는 포인터 선언
nodeType *Stack_top;

void init()
{
    Stack_top = NULL;
}

int isEmpty()
{
    if (Stack_top == NULL)
        return 1;
    else
        return 0;
}

int getSize()
{
    nodeType *p; // 노드를 가리키는 포인터
    int count = 0;

    for (p = Stack_top; p != NULL; p = p->next) // Top부터 끝까지
        count = count + 1;

    return count;
}

int isFull()
{
    return (getSize() == MaxStackSize);
}

void push(char item)
{
    // 삽입할 노드의 생성
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->data = item;

    // Top의 위치에 노드 삽입
    p->next = Stack_top;
    Stack_top = p; // Top을 삽입한 노드로 변경
}

char pop()
{
    nodeType *p;
    char item;

    if (isEmpty())
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    else
    {
        p = Stack_top;
        Stack_top = Stack_top->next; // Top을 다음 노드로 변경
        item = p->data;              // Top의 데이터를 item에 저장
        free(p);                     // Top의 노드를 삭제
        return (item);               // Top의 데이터를 반환
    }
}

void printStack()
{
    nodeType *p;
    printf("스택의 크기는 %d입니다.\n", getSize());
    for (p = Stack_top; p != NULL; p = p->next) // Top부터 끝까지
        printf("%c\n", p->data);                // 데이터 출력 (역순). Top이 가장 마지막에 출력됨
}
