#define MaxQueueSize 10 // 큐의 최대 크기

typedef struct
{
    int Front;              // 큐의 시작을 가리키는 인덱스
    int Rear;               // 큐의 마지막 원소를 가리키는 인덱스
    int data[MaxQueueSize]; // 큐의 원소를 저장하는 배열
} queueType;

void init(queueType *Qptr) // Qptr is a pointer to a queueType
{
    // Front를 0, Rear를 -1로 초기화
    Qptr->Front = 0;
    Qptr->Rear = -1;
}

int isEmpty(queueType *Qptr)
{
    // Front > Rear 이면 큐가 비어있는 경우임. (0 > -1)
    return (Qptr->Front > Qptr->Rear);
}

int isFull(queueType *Qptr)
{
    // Rear >= MaxQueueSize-1 일 경우 꽉 차 있다고 판단
    return (Qptr->Rear >= MaxQueueSize - 1);
}

int getSize(queueType *Qptr)
{
    // Rear-Front+1 를 리턴 (Rear가 0부터 시작하므로)
    return (Qptr->Rear - Qptr->Front + 1);
}

void insert(queueType *Qptr, int Item)
{
    if (isFull(Qptr))
        printf("더이상 넣을 수 없습니다.!!!\n");
    else
    {
        // Rear 1증가
        Qptr->Rear = Qptr->Rear + 1;
        Qptr->data[Qptr->Rear] = Item; // data[Rear] 에 데이터 삽입
    }
}

int delete(queueType *Qptr)
{
    int temp; // 삭제할 원소를 저장할 변수

    if (isEmpty(Qptr))
    {
        printf("큐가 비어있습니다.\n");
        return -1;
    }
    else
    {
        temp = Qptr->data[Qptr->Front]; // 삭제할 원소를 temp에 저장
        Qptr->Front = Qptr->Front + 1;  // Front 1증가하여 다음 원소를 가리키게 함. (삭제)
        return temp;
    }
}

void queuePrint(queueType *Qptr)
{
    int i = 1, j; // i는 출력할 때 사용할 변수, j는 반복문에서 사용할 변수

    printf("큐에는 총 %d개의 원소가 있습니다.\n", getSize(Qptr));

    for (int j = Qptr->Front; j <= Qptr->Rear; j++) // Front부터 Rear까지 반복 (큐의 모든 원소 출력)
        printf("큐의 %d번째 원소는 %d입니다.\n", i++, Qptr->data[j]);
}
