#define MaxStackSize 10

typedef struct
{
    int Top;
    int data[MaxStackSize];
} stackType;

void init(stackType *Sptr)
{
    Sptr->Top = -1;
}

int isEmpty(stackType *Sptr)
{
    return (Sptr->Top < 0);
}

int isFull(stackType *Sptr)
{
    return (Sptr->Top >= MaxStackSize - 1);
}

int getSize(stackType *Sptr)
{
    return (Sptr->Top + 1);
}

void push(stackType *Sptr, int Item)
{
    if (isFull(Sptr))
        printf("더이상 넣을 수 없습니다.!!!\n");
    else
    {
        Sptr->data[Sptr->Top + 1] = Item;
        Sptr->Top = Sptr->Top + 1;
    }
}

int pop(stackType *Sptr)
{
    int temp;
    if (isEmpty(Sptr))
    {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    else
    {
        temp = Sptr->data[Sptr->Top];
        Sptr->Top = Sptr->Top - 1;
        return temp;
    }
}

int peek(stackType *Sptr)
{
    int temp;
    if (isEmpty(Sptr))
    {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    else
    {
        temp = Sptr->data[Sptr->Top];
        return temp;
    }
}

void printStack(stackType *Sptr)
{
    if (isEmpty(Sptr))
        printf("스택이 비어있습니다.\n");
    else
    {
        printf("스택의 총 원소 수는 %d입니다.\n", getSize(Sptr));

        for (int i = 0; i <= Sptr->Top; i++)
            printf("스택의 %d번째 원소는 %d입니다.\n", i + 1, Sptr->data[i]);
    }
}
