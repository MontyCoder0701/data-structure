#define MaxStackSize 10 // 스택의 최대 크기. This is a stack because it is LIFO.

typedef struct Node
{
	char item;		   // 노드 데이터
	struct Node *next; // 링크
} nodeType;

void initList(nodeType *headPtr) // parameter is a pointer to the head of the list because we want to modify the head pointer.
{
	headPtr = NULL; // 헤드 포인터를 NULL로 초기화
}

int isEmpty(nodeType *headPtr)
{
	if (headPtr == NULL)
		return 1;
	else
		return 0;
}

int getCurrentSize(nodeType *headPtr)
{
	nodeType *p;
	int count = 0;

	for (p = headPtr; p != NULL; p = p->next) // p가 NULL이 아닐 때까지 반복 (p가 NULL이면 끝)
		count = count + 1;

	return count;
}

char contains(nodeType *headPtr, int pos) // pos is the position of the node in the list.
{
	nodeType *p = headPtr; // p는 headPtr을 가리킴
	int i;

	for (i = 0; i < pos; p = p->next) // i는 pos가 될 때까지 반복
		if (p == NULL)				  // p가 NULL이면 0을 반환
			return 0;

	return p->item; // p가 NULL이 아니면 p의 item을 반환
}

void insertNext(nodeType *prevNode, nodeType *newNode)
{
	if (newNode != NULL)
	{
		newNode->next = prevNode->next; // newNode의 next는 prevNode의 next를 가리킴
		prevNode->next = newNode;		// prevNode의 next는 newNode를 가리킴 (결과는 prev -> new -> next)
	}
}

nodeType *removeNext(nodeType *prevNode)
{
	nodeType *removed = prevNode->next; // removed는 prevNode의 next를 가리킴

	if (removed != NULL)
		prevNode->next = removed->next; // prevNode의 next는 removed의 next를 가리킴

	return removed;
}

void printList(nodeType *headPtr)
{
	nodeType *p = headPtr;

	printf("리스트의 내용을 출력합니다.\n");
	for (p = headPtr; p != NULL; p = p->next) // p가 NULL이 아닐 때까지 반복 (p가 NULL이면 끝)
		printf("[%c] ", p->item);			  // p의 item을 출력. char이므로 %c

	printf("\n");
}
