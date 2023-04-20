#define MaxStackSize 10 // 스택의 최대 크기

typedef struct
{
    int Top;                // 스택의 탑을 표시하는 변수 (index)
    int data[MaxStackSize]; // 스택의 원소를 저장하는 배열
} stackType;                // Defines a new type called stackType

void init(stackType *Sptr) // sptr is a pointer to a stackType
{
    // 탑 인덱스를 -1으로 빈스택을 표시
    Sptr->Top = -1; // Sptr->Top = Sptr.Top
}

int isEmpty(stackType *Sptr)
{
    // Top < 0 일 경우 비어있다고 판단
    return (Sptr->Top < 0);
}

int isFull(stackType *Sptr)
{
    // Top >= MaxStackSize-1 일 경우 꽉 차 있다고 판단. (0부터 시작하므로 -1)
    return (Sptr->Top >= MaxStackSize - 1);
}

int getSize(stackType *Sptr)
{
    return (Sptr->Top + 1); // Top은 0부터 시작하므로 +1
}

void push(stackType *Sptr, int Item)
{
    if (isFull(Sptr))
        printf("더이상 넣을 수 없습니다.!!!\n");
    else
    {
        // sptr -> Top + 1 위치에 Item을 저장
        Sptr->data[Sptr->Top + 1] = Item; // Sptr->data[Sptr.Top+1] = Item
        Sptr->Top = Sptr->Top + 1;        // Top을 1증가
    }
}

int pop(stackType *Sptr)
{
    int temp; // 꺼낸 원소를 저장할 변수
    if (isEmpty(Sptr))
    {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    else
    {
        // data[Top]의 값을 temp에 저장
        temp = Sptr->data[Sptr->Top]; // temp = Sptr->data[Sptr.Top]
        Sptr->Top = Sptr->Top - 1;    // Top을 1감소
        return temp;
    }
}

int peek(stackType *Sptr) // 스택의 탑에 있는 원소를 반환
{
    int temp;
    if (isEmpty(Sptr))
    {
        printf("스택이 비어있습니다.\n");
        return -1;
    }
    else
    {
        // data[Top]의 값을 temp에 저장
        temp = Sptr->data[Sptr->Top]; // temp = Sptr->data[Sptr.Top]
        return temp;                  // temp를 반환 (Top은 변화 없음)
    }
}

void printStack(stackType *Sptr)
{
    if (isEmpty(Sptr))
        printf("스택이 비어있습니다.\n");
    else
    {
        printf("스택의 총 원소 수는 %d입니다.\n", getSize(Sptr));

        for (int i = 0; i <= Sptr->Top; i++)                                  // Top까지 반복 (0부터 시작)
            printf("스택의 %d번째 원소는 %d입니다.\n", i + 1, Sptr->data[i]); // data[i] 출력
    }
}
