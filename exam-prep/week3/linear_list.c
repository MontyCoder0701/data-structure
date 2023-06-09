#include <stdio.h>
#include "linear_list.h"

// array is fixed size
// list is dynamic size (like vector)

// This code is for array-based list.
// An array-based list is a type of list that is implemented using an array.
// It is not strictly an array or a list, but rather a hybrid data structure that combines features of both.

int main()
{

    initList();    // 리스트 초기화
    insert(0, 10); // 0번째 위치에 10을 넣어라
    insert(0, 20); // 0번째 위치에 20을 넣어라
    insert(1, 30); // 1번째 위치에 30을 넣어라
    insert(1, 40); // 1번째 위치에 40을 넣어라
    printList();

    delete (2); // 2번째 위치의 아이템을 삭제
    printList();
}
