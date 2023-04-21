#include <stdio.h>
#include <stdlib.h>
#include "bank.h"

// 서비스 창구가 1개인 경우
void main()
{
	int CustomerArrivalTime = 0; // 도착시간 저장을 위한 임시 변수
	customerType C1;			 // 고객 정보를 다루기 위한 변수 선언

	// 서비스 정보를 다루기 위한 변수 선언 및 초기화
	serverType S1;
	S1.CustomerNumber = 0;	 // 총 고객의 수
	S1.WaitingTime = 0;		 // 고객 대기시간(1인)
	S1.TotalWaitingTime = 0; // 고객 대기시간(토탈)
	S1.AvgWaitingTime = 0;	 // 고객 대기시간(평균)
	S1.ServiceStartTime = 0; // (다음)서비스 시작 시간

	init(); // 대기열 초기화

	// 은행에 도착하는 고객을 임으로 생성하여 큐에 모두 넣음
	// 처음 도착한 고객의 시간(0~9분 사이의 값을 가짐)
	CustomerArrivalTime = rand() % ConstMaxInterval; // % 연산자를 이용하여 0~4분 사이의 값 생성
	while (CustomerArrivalTime <= ConstCloseTime)	 // 영업 종료 시간을 넘었는지 체크
	{
		C1.ArrivalTime = CustomerArrivalTime;		   // 고객의 도착시간
		C1.ServiceTime = rand() % ConstMaxSvcTime + 1; // 서비스 시간 : 1분 - 5분 사이
		insert(C1);									   // 대기열에 넣음

		// 다음 고객이 도착하는 시간을 계산해서 구함
		CustomerArrivalTime = CustomerArrivalTime + (rand() % ConstMaxInterval);
	}

	// 큐에서 고객을 1명씩 꺼내서 서비스
	while (!isEmpty())
	{
		// 고객을 1명 꺼내옴
		C1 = delete ();
		S1.CustomerNumber = S1.CustomerNumber + 1; // 고객의 수 증가

		// 고객이 기다리는 경우 대기시간 계산
		if (S1.ServiceStartTime >= C1.ArrivalTime)
		{
			S1.WaitingTime = S1.ServiceStartTime - C1.ArrivalTime;		// 기다린 시간
			S1.TotalWaitingTime = S1.TotalWaitingTime + S1.WaitingTime; // 기다린 시간 누적
			printf("%d번째 고객의 대기시간은 %d분 입니다.\n", S1.CustomerNumber, S1.WaitingTime);
		}
		else
		{
			// 서비스 시작 시간을 고객 도착 시간으로 재설정
			S1.ServiceStartTime = C1.ArrivalTime;
			printf("%d번째 고객의 대기시간은 0분 입니다.\n", S1.CustomerNumber);
		}

		// 다음 고객의 서비스 시작 시간 계산
		S1.ServiceStartTime = S1.ServiceStartTime + C1.ServiceTime;
	}

	// 분석 및 결과 출력
	S1.AvgWaitingTime = (float)S1.TotalWaitingTime / (float)S1.CustomerNumber;
	printf("방문한 고객의 총 수는 %d명 입니다.\n", S1.CustomerNumber);
	printf("방문한 고객의 총 대기시간은 %d분 입니다.\n", S1.TotalWaitingTime);
	printf("방문한 고객의 평균 대기시간은 %f분 입니다.\n", S1.AvgWaitingTime);
}
