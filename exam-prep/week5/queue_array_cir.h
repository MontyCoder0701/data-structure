#define MaxQueueSize 6 // 큐의 최대 크기

typedef struct
{
	int Front;				// 큐의 시작을 가리키는 인덱스
	int Rear;				// 큐의 마지막 원소를 가리키는 인덱스
	int Count;				// 큐에 저장된 원소의 수
	int data[MaxQueueSize]; // 큐의 원소를 저장하는 배열
} queueType;

void init(queueType *Qptr)
{
	// Front를 0, Rear를 -1로 초기화
	Qptr->Front = 0;
	Qptr->Rear = -1;
	Qptr->Count = 0;
}

int isEmpty(queueType *Qptr)
{
	// Count == 0이면 큐가 비어있는 경우임
	return (Qptr->Count == 0);
}

int isFull(queueType *Qptr)
{
	// Count == MaxQueueSize 일 경우 꽉 차 있다고 판단
	return (Qptr->Count == MaxQueueSize);
}

int getSize(queueType *Qptr)
{
	// Count 값을 리턴
	return (Qptr->Count);
}

void insert(queueType *Qptr, int Item)
{
	if (isFull(Qptr))
		printf("더이상 넣을 수 없습니다.!!!\n");
	else
	{
		// data[Rear+1]에 데이터 삽입, Rear를 1증가
		Qptr->Rear = (Qptr->Rear + 1) % MaxQueueSize; // % 연산자를 이용하여 배열의 인덱스를 0~MaxQueueSize-1로 유지
		Qptr->data[Qptr->Rear] = Item;
		Qptr->Count = Qptr->Count + 1;
	}
}

int delete(queueType *Qptr)
{
	int temp;

	if (isEmpty(Qptr))
	{
		printf("큐가 비어있습니다.\n");
		return -1;
	}
	else
	{
		// data[Front]의 값을 반환, Front를 1증가, Count 1감소
		temp = Qptr->data[Qptr->Front];
		Qptr->Front = (Qptr->Front + 1) % MaxQueueSize; // % 연산자를 이용하여 배열의 인덱스를 0~MaxQueueSize-1로 유지
		Qptr->Count = Qptr->Count - 1;

		return temp;
	}
}

void queuePrint(queueType *Qptr)
{
	int i, j; // i: 반복문을 위한 변수, j: 큐의 Front를 가리키는 변수
	printf("큐에는 총 %d개의 원소가 있습니다.\n", getSize(Qptr));

	// 변수 j를 큐의 Front를 가리키게함
	j = Qptr->Front;
	for (i = 1; i <= Qptr->Count; i++) // 큐에 저장된 원소의 수만큼 반복
	{
		printf("큐의 %d번째 원소는 %d입니다.\n", i, Qptr->data[j % MaxQueueSize]); // % 연산자를 이용하여 배열의 인덱스를 0~MaxQueueSize-1로 유지
		j = j + 1;
	}
}
