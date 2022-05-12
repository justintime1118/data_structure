#include "simLinkedQueue.h"

// 1. 도착 큐에 고객 넣기
void insertCustomer(int arrivalTime, int serviceTime, int customerNumber, LinkedQueue *pQueue)
{
	if (!pQueue)
	{
		printf("[error] Queue is Null.\n");
		return;
	}
	if (arrivalTime < 0 || serviceTime <= 0)
	{
		printf("[error] Invalid Time.\n");
		return;
	}
	SimCustomer customer;
	customer.status = arrival;
	customer.arrivalTime = arrivalTime;
	customer.serviceTime = serviceTime;
	customer.startTime = -1;
	customer.endTime = -1;
	customer.customerNumber = customerNumber;

	LinkedQueueNode node;
	node.data = customer;
	node.pLink = NULL;
	enqueueLQ(pQueue, node);
}

// 2. 고객 도착 : 도착큐에 있는 고객을 대기 큐로 이동
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	if (!pArrivalQueue || !pWaitQueue)
	{
		printf("[error] Queue is Null.\n");
		return;
	}
	// 현재 시각이 도착시각과 같다면 대기큐로 이동
	if (currentTime == pArrivalQueue->front->data.arrivalTime)
		enqueueLQ(pWaitQueue, *(dequeueLQ(pArrivalQueue)));
}

// 3. 서비스 종료 : 현재 시간에 기존 서비스 중이던 고객이 서비스 완료되었다면 종료 처리
LinkedQueueNode *processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (pServiceNode->data.endTime == currentTime)
	{
		pServiceNode->data.status = end;
		*(pServiceUserCount) += 1;
		*(pTotalWaitTime) += pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
	}
	else
	{
		printf("[error] Still in service.\n");
		return (NULL);
	}
	return (pServiceNode);
}

// 4. 서비스 시작 : 현재 시간에 서비스 중이 아니라면 대기 큐에서 고객을 반환하여 서비스 시작
//서비스 중이 아닌 건.. main에서 판단..?
LinkedQueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	if (!pWaitQueue)
	{
		printf("[error] Queue is Null.\n");
		return (NULL);
	}

	LinkedQueueNode *node;
	node = dequeueLQ(pWaitQueue);
	node->data.status = start;
	node->data.startTime = currentTime;
	node->data.endTime = currentTime + node->data.serviceTime;
	return (node);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	if (customer.status == arrival)
		printf("status : arrival\n");
	else if (customer.status == start)
		printf("status : start\n");
	else if (customer.status == end)
		printf("status : end\n");
	printf("arrivalTime : %d\n", customer.arrivalTime);
	printf("serviceTime : %d\n", customer.serviceTime);
}

// 5. 대기 큐 상태 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	if (!pWaitQueue)
	{
		printf("[error] Queue is Null.\n");
		return;
	}

	if (isLinkedQueueEmpty(pWaitQueue))
	{
		printf("No one is waiting yet.\n");
		return;
	}
	LinkedQueueNode *node;
	node = pWaitQueue->front;
	int count = 0;
	printf("<waiting list>\n");
	while (node)
	{
		printf("%d\n", node->data.customerNumber);
		node = node->pLink;
		++count;
	}
	printf("Total waiting num : %d\n", count);
}

// 6. 최종 시뮬레이션 결과 출력
void printReport(int serviceUserCount, int totalWaitTime, int totalServiceTime)
{
	if (serviceUserCount == 0)
	{
		printf("There are 0 customers who used the service.\n");
		return;
	}
	printf("%d people used the service.\n", serviceUserCount);
	printf("Total waiting time is %d.\n", totalWaitTime);
	printf("Total Service time is %d.\n", totalServiceTime);
}