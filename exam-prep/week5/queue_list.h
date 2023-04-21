typedef struct node
{
    char data;
    struct node *next; // linked list
} nodeType;            // 노드타입 정의

// Front, Rear을 가리키는 포인터 선언
nodeType *Front;
nodeType *Rear;

void init()
{
    Front = NULL;
    Rear = NULL;
}

int isEmpty()
{
    return (Front == NULL);
}

int getSize()
{
    nodeType *p;
    int count = 0;

    for (p = Front; p != NULL; p = p->next) // Front부터 Rear까지
        count = count + 1;

    return count;
}

void insert(char item)
{
    // 삽입할 노드의 생성
    nodeType *p = (nodeType *)malloc(sizeof(nodeType));
    p->data = item;
    p->next = NULL; // 새로 생성되는 노드는 Rear 뒤에 삽입되므로 NULL

    if (isEmpty())
    // 빈큐이면 Front,Rear 모두 생성된 노드를 가리킴
    {
        Front = p;
        Rear = p;
    }
    else
    // Rear 뒤에 삽입
    {
        Rear->next = p;
        Rear = p;
    }
}

char delete()
{
    nodeType *p;
    char item; // 삭제할 원소를 저장할 변수

    if (isEmpty())
    {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    else
    {
        p = Front;
        Front = Front->next; // Points to the next node
        item = p->data;
        free(p); // 메모리 해제
        return (item);
    }
}

void printQueue()
{
    nodeType *p;
    printf("Queue의 크기는 %d입니다.\n", getSize());
    for (p = Front; p != NULL; p = p->next) // Front부터 Rear까지
        printf("%c\n", p->data);
}
