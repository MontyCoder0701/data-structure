#define ConstCloseTime 120 // 업무시간 2시간(120분)으로 가정
#define ConstMaxInterval 5 // 0~4분 간격으로 랜덤하게 도착
#define ConstMaxSvcTime 10 // 서비스 시간은 1 ~ 9분으로 랜덤하게 발생

// 고객 정의
typedef struct
{
	int ArrivalTime; // 고객의 도착 시간
	int ServiceTime; // 고객의 서비스 소요시간
} customerType;

// 고객리스트 정의 - 연결리스트로 구현한 큐
typedef struct node
{
	customerType Customer; // 고객 데이터 저장
	struct node *next;	   // 다음 고객을 가리키는 링크
} nodeType;

// Front, Rear을 가리키는 포인터 선언
nodeType *Front;
nodeType *Rear;

// 서비스 통계 정의
typedef struct
{
	int CustomerNumber;	  // 서비스를 받은 고객의 수
	int ServiceStartTime; // 서비스를 시작하는 시간
	int WaitingTime;	  // 고객이 기다린 시간
	int TotalWaitingTime; // 고객이 기다린 시간의 총합
	float AvgWaitingTime; // 고객의 평균 대기 시간
} serverType;

void init()
{
	Front = NULL;
	Rear = NULL;
}

int isEmpty()
{
	return (Front == NULL);
}

void insert(customerType NewCustomer)
{
	// 삽입할 고객(신규생성 고객노드)를 임시 포인터 p가 가리킨다.
	nodeType *p = (nodeType *)malloc(sizeof(nodeType));
	p->Customer = NewCustomer; // 고객 데이터를 노드에 대입
	p->next = NULL;

	// 빈큐이면 Front,Rear 모두 생성된 노드를 가리킴
	if (isEmpty())
	{
		Front = p;
		Rear = p;
	}
	else
	{
		Rear->next = p; // Rear 뒤에 삽입
		Rear = p;
	}
}

customerType delete()
{
	nodeType *p;			// 삭제할 노드를 가리킬 포인터
	customerType temp_data; // 반환할 고객데이터

	if (isEmpty())
	{
		printf("큐가 비어있습니다.\n");
		temp_data.ArrivalTime = -1;
		temp_data.ServiceTime = -1;
		return temp_data;
	}
	else
	{
		p = Front;
		Front = Front->next;	 // Front 다음 노드 가리킴
		temp_data = p->Customer; // Front 데이터를 저장
		free(p);				 // Front 노드 삭제
		return (temp_data);
	}
}
