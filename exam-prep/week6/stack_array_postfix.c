#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_array_postfix.h"

// 후위 표기법 계산 함수 -> stack array로 구현함
// double is used because the result of the calculation can be a decimal number.

double cal_postfix(char expr[])
{
	// 연산에 필요한 임시 변수 정의
	char c;
	int i = 0;
	int st_value, val_left, val_right; // st_value means value that is pushed in stack

	stackType st1; // 스택 생성
	init(&st1);	   // 스택 초기화

	for (i = 0; i < strlen(expr); i++)
	{
		c = expr[i]; // 각각의 문자를 변수 c에 저장

		// c가 숫자일 경우 스택에 넣고
		if (c >= '0' && c <= '9')
		{
			st_value = c - '0'; // 문자를 숫자로 변환. For example, the ASCII code for '0' is 48, and the ASCII code for '1' is 49. So, if c is '1', then c - '0' is equal to 49 - 48, which is 1.
			push(&st1, st_value);
		}
		else
		// 연산자일 경우 스택에서 2개를 꺼내 계산 후
		// 결과를 스택에 삽입
		{
			val_right = pop(&st1); // 먼저 꺼낸 숫자가 오른쪽
			val_left = pop(&st1);  // 나중에 꺼낸 숫자가 왼쪽
			switch (c)
			{
			case '+':
				push(&st1, (val_left + val_right));
				break;
			case '-':
				push(&st1, (val_left - val_right));
				break;
			case '*':
				push(&st1, (val_left * val_right));
				break;
			case '/':
				push(&st1, (val_left / val_right));
				break;
			}
		}
	}

	// 스택에는 최종 결과만 남아있음
	return pop(&st1);
}

int main()
{

	// 연산식 2개 정의
	char expr1[10] = "25+3*1-";
	char expr2[10] = "25+3+2/";

	printf("연산식: %s의 값은 %lf 입니다.\n", expr1, cal_postfix(expr1));
	printf("연산식: %s의 값은 %lf 입니다.\n", expr2, cal_postfix(expr2));
}
