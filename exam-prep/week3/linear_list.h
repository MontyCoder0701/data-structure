#define maxItems 100 // 최대 100개를 저장. define means constant value.

// 리스트 구조 정의
int itemCount;       // 리스트의 크기를 저장
int items[maxItems]; // 리스트아이템 타입은 정수형

void initList()
{
    itemCount = 0;
}

int isEmpty()
{
    if (itemCount == 0)
        return 1;
    else
        return 0;
}

int isFull()
{
    if (itemCount == maxItems)
        return 1;
    else
        return 0;
}

int getCurrentSize()
{
    return itemCount;
}

int contains(int pos) // pos means position (index)
{
    return items[pos]; // returns the value at the given position
}

void insert(int pos, int item)
{
    int i;
    if (isFull() == 0 && pos >= 0 && pos <= itemCount) // 리스트가 포화상태가 아니고, 지정한 위치가 0이상 itemCount이하이면
    {
        for (i = itemCount; i > pos; i--) // i는 itemCount부터 pos까지 감소. i-- means i = i - 1 (decrement).
            items[i] = items[i - 1];      // 한칸씩 값을 뒤로 이동 (빈자리를 만듦). items[3] = items[2]가 되어 뒤로 한칸으로 이동하는 것.

        items[pos] = item;         // 지정한 위치에 item 값을 넣음
        itemCount = itemCount + 1; // 리스트 크기를 1증가시킴
    }
    else
        printf("리스트가 포화상태이거나 삽입 위치가 잘못되었습니다.\n");
}

void delete(int pos)
{
    int i;
    if (isEmpty() == 0 && 0 <= pos && pos < itemCount) // 리스트가 공백상태가 아니고, 지정한 위치가 0이상 itemCount미만이면
    {
        for (i = pos + 1; i < itemCount; i++) // i는 pos+1부터 itemCount까지 증가. i++ means i = i + 1 (increment). Increment until i == itemCount.
            items[i - 1] = items[i];          // 한칸씩 값을 앞으로 이동 (정해진 숫자의 자리를 채움). items[2] = items[3]가 되어 앞으로 한칸으로 이동하는 것.

        itemCount = itemCount - 1; // 리스트 크기를 1감소시킴
    }
    else
        printf("리스트가 공백상태이거나 삭제 위치가 잘못되었습니다.\n");
}

void printList()
{
    int i;
    printf("리스트의 내용을 출력합니다.\n");
    for (i = 0; i < itemCount; i++) // 리스트의 크기만큼 반복.
        printf("[%d]", items[i]);   // 리스트의 아이템을 출력

    printf("\n");
}
