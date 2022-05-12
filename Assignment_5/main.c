#include "simLinkedQueue.h"

int main(void)
{
	int total_b_h;			  // 총 영업시간
	int currentTime;		  // 현재 시각
	int end_b_h;			  // 영업 종료시간
	int check;				  // 고객을 입력받을지 안받을지 확인
	int serviceTime;		  // 고객을 입력받을 시 고객의 서비스 타임
	int serviceUserCount = 0; // 총 고객 수
	int totalWaitTime = 0;	  // 총 고객의 기다림 시간 합
	int totalServiceTime = 0; // 총 서비스 시간
	int customerNumber = 1;	  // 번호표

	// 총 영업시간 입력
	printf("Setting total business hours.\n");
	scanf("%d", &total_b_h);

	// 현재 시각 입력
	printf("Setting current time.\n");
	scanf("%d", &currentTime);

	// 영업 종료시간 계산
	end_b_h = currentTime + total_b_h;

	LinkedQueue *pArrivalQueue;
	LinkedQueue *pWaitQueue;
	LinkedQueueNode *pServiceNode;
	pArrivalQueue = createLinkedQueue();
	pWaitQueue = createLinkedQueue();
	pServiceNode = NULL;

	while (currentTime <= end_b_h)
	{
		printf("\n===================================\n");
		printf("[ Current Time is %d, remaining business time is %d ]\n", currentTime, end_b_h - currentTime);
		printf("--------------------------------\n");
		if (end_b_h - currentTime != 0)
		{
			printf("If you would like to add a new customer, press 1. Otherwise, press another\n");
			printf("press number! : ");
			scanf("%d", &check);
			if (check == 1)
			{
				//도착큐에 insert하기 전에 유효성 검사
				if (pServiceNode && pServiceNode->data.endTime >= end_b_h)
					printf("Sorry. Today's service queue is full.\n");
				else
				{
					printf("Please enter the required service time.\n");
					printf("press number! : ");
					scanf("%d", &serviceTime);
					if (totalServiceTime + currentTime >= end_b_h)
						printf("Sorry. It is outside of today's business hours.\n");
					else
					{
						// 집어 넣을 수 있는 상황일 때 도착큐에 insert
						if (serviceTime != 0)
						{
							insertCustomer(currentTime, serviceTime, customerNumber, pArrivalQueue);
							totalServiceTime += serviceTime;
							customerNumber += 1;
						}
						else
							printf("[error] Invalid Time.\n");
					}
				}
			}
		}
		// 도착큐에 뭐가 있으면 디큐 후 대기큐로 인큐
		if (pArrivalQueue->front != NULL)
			processArrival(currentTime, pArrivalQueue, pWaitQueue);

		// 서비스중인 상태인데, 서비스 종료시간이 현재시각과 같으면, 서비스를 종료.
		if (pServiceNode && (pServiceNode->data.endTime - currentTime == 0))
		{
			pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &serviceUserCount, &totalWaitTime);
			printf("[ %dnd customer service end. ]\n", pServiceNode->data.customerNumber);
			free(pServiceNode);
			pServiceNode = NULL;
		}
		if (pServiceNode == NULL && pWaitQueue->front != NULL)
		{
			pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
			printf("[ %dnd customer service start! ]\n", pServiceNode->data.customerNumber);
		}

		// 대기 목록 출력
		if (pWaitQueue)
		{
			printf("--------------------------------\n");
			printWaitQueueStatus(currentTime, pWaitQueue);
		}

		// 서비스 상태 출력
		printf("--------------------------------\n");
		if (pServiceNode != NULL)
		{
			printf("The %dth customer is using the service.\n", pServiceNode->data.customerNumber);
			printf("Remaining time is %d.\n", pServiceNode->data.endTime - currentTime);
		}
		else
			printf("There are no customers using the service.\n");
		++currentTime;
	}

	// 영업 종료 후 결산 출력
	printReport(serviceUserCount, totalWaitTime, totalServiceTime);

	// 큐 삭제
	deleteLinkedQueue(pWaitQueue);
	deleteLinkedQueue(pArrivalQueue);
	system("leaks test");
}