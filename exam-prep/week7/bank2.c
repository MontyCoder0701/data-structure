#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "bank.h"

// 서비스 창구가 1개인 경우
void main()
{
	// nodeType* Queue;		// 고객 대기열
	int CustomerArrivalTime = 0; // 도착시간 저장을 위한 임시 변수
	float AvgWaitingTime = 0;	 // 고객의 평균 대기시간

	// 서비스 정보를 다루기 위한 변수 선언 및 초기화
	serverType S1;
	S1.CustomerNumber = 0;
	S1.WaitingTime = 0;
	S1.TotalWaitingTime = 0;
	S1.AvgWaitingTime = 0;
	S1.ServiceStartTime = 0;

	serverType S2;
	S2.CustomerNumber = 0;
	S2.WaitingTime = 0;
	S2.TotalWaitingTime = 0;
	S2.AvgWaitingTime = 0;
	S2.ServiceStartTime = 0;

	// 고객 정보를 다루기 위한 변수 선언
	customerType C1;

	init(); // 대기열 초기화

	// 은행에 도착하는 고객을 임으로 생성하여 큐에 모두 넣음
	// ConstAvgInterval에서 정의한 시간에 1명정도 도착을 가정
	// 처음 도착한 고객의 시간(0~4분 사이의 값을 가짐)
	CustomerArrivalTime = rand() % ConstMaxInterval; // % 이용해서 0~4분 사이의 값 생성
	while (CustomerArrivalTime <= ConstCloseTime)	 // 영업 종료 시간을 넘었는지 체크
	{
		C1.ArrivalTime = CustomerArrivalTime;		   // 고객의 도착 시간
		C1.ServiceTime = rand() % ConstMaxSvcTime + 1; // 서비스 시간 : 1분-9분 사이
		insert(C1);									   // 대기열에 넣음

		// 다음 고객이 도착하는 시간을 계산해서 구함
		CustomerArrivalTime = CustomerArrivalTime + (rand() % ConstMaxInterval);
	}

	// 큐에서 고객을 1명씩 꺼내서 서비스
	while (!isEmpty())
	{
		// 고객을 1명 꺼내옴
		C1 = delete ();

		// 서비스를 S1에서 할지 S2에서 할 지 결정
		// 서비스 시작 시간이 빠른 쪽에서 서비스
		if (S1.ServiceStartTime <= S2.ServiceStartTime)
		{
			S1.CustomerNumber = S1.CustomerNumber + 1; // 고객의 수 증가
			// 고객이 기다리는 경우 대기시간 계산
			if (S1.ServiceStartTime >= C1.ArrivalTime)
			{
				S1.WaitingTime = S1.ServiceStartTime - C1.ArrivalTime;
				S1.TotalWaitingTime = S1.TotalWaitingTime + S1.WaitingTime;
				printf("S1의 %d번째 고객의 대기시간은 %d분 입니다.\n", S1.CustomerNumber, S1.WaitingTime);
			}
			else
			{
				S1.ServiceStartTime = C1.ArrivalTime;
				printf("S1의 %d번째 고객의 대기시간은 0분 입니다.\n", S1.CustomerNumber);
			}
			// 다음 고객의 서비스 시작 시간 계산
			S1.ServiceStartTime = S1.ServiceStartTime + C1.ServiceTime;
		}
		else
		{
			S2.CustomerNumber = S2.CustomerNumber + 1; // 고객의 수 증가

			// 고객이 기다리는 경우 대기시간 계산
			if (S2.ServiceStartTime >= C1.ArrivalTime)
			{
				S2.WaitingTime = S2.ServiceStartTime - C1.ArrivalTime;
				S2.TotalWaitingTime = S2.TotalWaitingTime + S2.WaitingTime;
				printf("S2의 %d번째 고객의 대기시간은 %d분 입니다.\n", S2.CustomerNumber, S2.WaitingTime);
			}
			else
			{
				S2.ServiceStartTime = C1.ArrivalTime;
				printf("S2의 %d번째 고객의 대기시간은 0분 입니다.\n", S2.CustomerNumber);
			}
			// 다음 고객의 서비스 시작 시간 계산
			S2.ServiceStartTime = S2.ServiceStartTime + C1.ServiceTime;
		}
	}

	// 분석 및 결과 출력
	// S1에서 서비스 받은 고객의 대기시간 통계
	S1.AvgWaitingTime = (float)S1.TotalWaitingTime / (float)S1.CustomerNumber;
	printf("S1에서 서비스 받은 고객의 총 수는 %d명 입니다.\n", S1.CustomerNumber);
	printf("S1에서 서비스 받은 고객의 총 대기 시간은 %d분 입니다.\n", S1.TotalWaitingTime);
	printf("S1에서 서비스 받은 고객의 평균 대기 시간은 %f분 입니다.\n", S1.AvgWaitingTime);

	// S2에서 서비스 받은 고객의 대기시간 통계
	S2.AvgWaitingTime = (float)S2.TotalWaitingTime / (float)S2.CustomerNumber;
	printf("S2에서 서비스 받은 고객의 총 수는 %d명 입니다.\n", S2.CustomerNumber);
	printf("S2에서 서비스 받은 고객의 총 대기 시간은 %d분 입니다.\n", S2.TotalWaitingTime);
	printf("S2에서 서비스 받은 고객의 평균 대기 시간은 %f분 입니다.\n", S2.AvgWaitingTime);

	// 전체 고객의 대기시간 통계
	AvgWaitingTime = (float)(S1.TotalWaitingTime + S2.TotalWaitingTime) / (float)(S1.CustomerNumber + S2.CustomerNumber);
	printf("방문한 고객의 총 수는 %d명 입니다.\n", S1.CustomerNumber + S2.CustomerNumber);
	printf("방문한 고객의 총 대기 시간은 %d분 입니다.\n", S1.TotalWaitingTime + S2.TotalWaitingTime);
	printf("방문한 고객의 평균 대기 시간은 %f분 입니다.\n", AvgWaitingTime);
}
