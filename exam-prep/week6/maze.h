#define MaxRowSize 7
#define MaxColSize 6

// 미로정의: 1은 이동 불가능, 0은 이동 가능
int maze[MaxRowSize + 2][MaxColSize + 2] = {
    {1, 1, 1, 1, 1, 1, 1, 1},  // 1행
    {1, 0, 1, 1, 0, 1, 1, 1},  // 2행
    {1, 0, 0, 1, 0, 1, 1, 1},  // 3행
    {1, 1, 0, 0, 0, 1, 1, 1},  // 4행
    {1, 1, 1, 0, 0, 0, 1, 1},  // 5행
    {1, 0, 0, 0, 1, 1, 1, 1},  // 6행
    {1, 1, 0, 1, 0, 0, 0, 1},  // 7행
    {1, 0, 0, 0, 0, 1, 0, 1},  // 8행
    {1, 1, 1, 1, 1, 1, 1, 1}}; // 9행

// 마우스의 좌표 타입 정의
typedef struct
{
     int x;   // 마우스의 x좌표
     int y;   // 마우스의 y좌표
     int dir; // 0:동, 1:남, 2:서, 3:북
} mouseType;

// 스택 자료구조와 함수 정의
typedef struct
{
     int Top;                                  // 스택의 탑을 표시하는 변수
     mouseType Stack[MaxRowSize * MaxColSize]; // 스택의 원소를 저장하는 배열
} stackType;

void initStack(stackType *Sptr)
{ // 탑 인덱스를 -1으로 빈스택을 표시
     Sptr->Top = -1;
}

void push(stackType *Sptr, mouseType Item) // doesn't return anything
{
     if (Sptr->Top >= MaxRowSize * MaxColSize)
          printf("더이상 넣을 수 없습니다.!!!\n");
     else
     {
          // Stack[Top+1]에 데이터 삽입, Top을 1증가
          Sptr->Stack[Sptr->Top + 1] = Item;
          Sptr->Top = Sptr->Top + 1;
     }
}

mouseType pop(stackType *Sptr) // returns mouseType
{
     mouseType temp;

     if (Sptr->Top < 0)
     {
          printf("스택이 비어있습니다.\n");
          temp.dir = -1;
          return temp;
     }
     else
     {
          // Stack[Top]의 값을 반환, Top을 1감소
          temp = Sptr->Stack[Sptr->Top];
          Sptr->Top = Sptr->Top - 1;
          return temp;
     }
}

void printStack(stackType *Sptr)
{
     int i;
     if (Sptr->Top >= 0)                                                                         // 스택이 비어있지 않으면
          for (i = 0; i <= Sptr->Top; i++)                                                       // 스택의 탑부터 출력
               printf("<%d, %d, %d>\n", Sptr->Stack[i].x, Sptr->Stack[i].y, Sptr->Stack[i].dir); // prints three values, x, y, dir
}
