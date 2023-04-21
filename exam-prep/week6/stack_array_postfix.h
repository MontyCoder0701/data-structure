#define MaxStackSize 10 // 스택의 최대 크기

typedef struct
{
  int Top;                   // 스택의 탑을 표시하는 변수
  double data[MaxStackSize]; // 스택의 원소를 저장하는 배열
} stackType;

void init(stackType *Sptr)
{
  // 탑 인덱스를 -1으로 빈스택을 표시
  Sptr->Top = -1;
}

int isEmpty(stackType *Sptr)
{
  // Top < 0 일 경우 비어있다고 판단
  return (Sptr->Top < 0);
}

int isFull(stackType *Sptr)
{
  // Top >= MaxStackSize-1 일 경우 꽉 차 있다고 판단
  return (Sptr->Top >= MaxStackSize - 1);
}

int getSize(stackType *Sptr)
{
  return (Sptr->Top + 1);
}

void push(stackType *Sptr, double Item)
{
  if (isFull(Sptr))
    printf("더이상 넣을 수 없습니다.!!!\n");
  else
  {
    // data[Top+1]에 데이터 삽입, Top을 1증가
    Sptr->data[Sptr->Top + 1] = Item;
    Sptr->Top = Sptr->Top + 1;
  }
}

double pop(stackType *Sptr)
{
  double temp;
  if (isEmpty(Sptr))
  {
    printf("스택이 비어있습니다.\n");
    return -1;
  }
  else
  {
    // data[Top]의 값을 반환, Top을 1감소
    temp = Sptr->data[Sptr->Top];
    Sptr->Top = Sptr->Top - 1;
    return temp;
  }
}
