#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

// Solving maze using stack

// 마우스 초기화
void initMouse(mouseType *Mouse)
{
	Mouse->x = 1; // 처음 좌표 : (1,1)
	Mouse->y = 1;
	Mouse->dir = 0; // 방향 : 동
}

// 마우스를 해당 방향으로 1칸 움직임
void moveMouse(mouseType *Mouse)
{
	switch (Mouse->dir)
	{
	case 0:
		Mouse->y++;
		break; // 동으로 이동
	case 1:
		Mouse->x++;
		break; // 남으로 이동
	case 2:
		Mouse->y--;
		break; // 서로 이동
	case 3:
		Mouse->x--;
		break; // 북으로 이동
	}

	Mouse->dir = 0;				  // 이동할 방향 초기화
	maze[Mouse->x][Mouse->y] = 1; // 현재 이동한 지점을 다시 가지 않도록 1로 표시
}

// 마우스를 해당 방향으로 움직일 수 있는지 검사
// 우선 해당 방향으로 1칸 이동한 후, 이동 가능한지 검사 (DFS)
// 1: 이동 가능, 0: 이동 불가능
int movePossible(int x, int y, int direction)
{
	switch (direction)
	{
	case 0:
		y++;
		break; // 동으로 이동
	case 1:
		x++;
		break; // 남으로 이동
	case 2:
		y--;
		break; // 서로 이동
	case 3:
		x--;
		break; // 북으로 이동
	}

	if (maze[x][y] == 1)
		return 0; // 이동 불가능
	else
		return 1; // 이동 가능
}

int main(void)
{
	stackType Path_Stack; // 경로 선택시 사용할 스택 정의
	mouseType Mouse;	  // 미로를 찾을 마우스 정의

	initStack(&Path_Stack); // call by reference
	initMouse(&Mouse);

	push(&Path_Stack, Mouse); // 처음 위치와 방향(1,1,0) 삽입

	while (Path_Stack.Top >= 0)
	{
		Mouse = pop(&Path_Stack);

		// 시도 해볼 방향이 있는 한 계속 시도
		while (Mouse.dir <= 3) // 0:동, 1:남, 2:서, 3:북
		{
			if (Mouse.x == 7 && Mouse.y == 6) // 목표 지점이 오면 종료한다.
			{
				push(&Path_Stack, Mouse); // 스택에 삽입
				printf("마우스의 이동 경로는 다음과 같습니다.\n");
				printStack(&Path_Stack);
				exit(0);
			}
			else
			{
				if (movePossible(Mouse.x, Mouse.y, Mouse.dir) == 1)
				{
					push(&Path_Stack, Mouse); // 스택에 삽입
					moveMouse(&Mouse);		  // 마우스 이동
				}
				else
				{
					Mouse.dir = Mouse.dir + 1; // 다음 이동할 방향을 설정
				}
			}
		}
	}
}
