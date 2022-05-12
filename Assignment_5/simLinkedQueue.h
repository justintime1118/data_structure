#ifndef _SIMLINKED_QUEUE_
#define _SIMLINKED_QUEUE_

#include <stdlib.h>
#include <stdio.h>

typedef enum SimStatusType
{
	arrival,
	start,
	end
} SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime; // 도착 시각.
	int serviceTime; // 서비스 시간.
	int startTime;	 // 시작 시각.
	int endTime;	 // 종료 시각: 시작 시각 + 서비스 시간.
	int customerNumber;
} SimCustomer;

typedef struct SimLinkedQueueNodeType
{
	SimCustomer data;
	struct SimLinkedQueueNodeType *pLink;
} LinkedQueueNode;

typedef struct SimLinkedQueueType
{
	int currentElementCount;
	LinkedQueueNode *front;
	LinkedQueueNode *rear;
} LinkedQueue;

LinkedQueue *createLinkedQueue(void);
int enqueueLQ(LinkedQueue *pQueue, LinkedQueueNode element);
LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue);
LinkedQueueNode *peekLQ(LinkedQueue *pQueue);
void deleteLinkedQueue(LinkedQueue *pQueue);
int isLinkedQueueEmpty(LinkedQueue *pQueue);
void displayLinkedQueue(LinkedQueue *pQueue);

void insertCustomer(int arrivalTime, int serviceTime, int customerNumber, LinkedQueue *pQueue);
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);
LinkedQueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);
LinkedQueueNode *processServiceNodeEnd(int currentTime, LinkedQueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);
void printReport(int serviceUserCount, int totalWaitTime, int totalServiceTime);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif