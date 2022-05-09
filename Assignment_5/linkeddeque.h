#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

#include <stdlib.h>
#include <stdio.h>

typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

typedef struct LinkedDequeType
{
	int currentElementCount;	// 현재 원소의 개수
	DequeNode* pFrontNode;		// Front 노드의 포인터
	DequeNode* pRearNode;		// Rear 노드의 포인터
} LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
int deleteFrontLD(LinkedDeque* pDeque);
int deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
// int isLinkedDequeFull(LinkedDeque* pDeque); -> 꽉 차는 경우가 거의 없을 것으로 생각 됨
int isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif