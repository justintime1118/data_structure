/*
<구현해야 할 것들>
큐 배열
큐 링크
원형큐 배열로
데큐 이중연결로

-> 큐 배열을 애초에 원형 큐 배열로 구현하고, 데큐가 어쨌든 리스트를 써서 구현하니까 그냥 이 두개로 퉁쳐도 되지않을까?
*/

#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *pQueue;

	pQueue = malloc(sizeof(ArrayQueue));
	if (pQueue == NULL)
		return (NULL);
	pQueue->pElement = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (pQueue->pElement == NULL)
		return (NULL);
	return (pQueue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	/*
	꽉 찼는지 확인
	자리 있으면 [(rear + 1) % max] 인덱스에 값 넣기
	rear 값도 마찬가지로 변경
	current++
	*/
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	/*
	front = (front + 1) % max
	current--
	*/
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	// front 인덱스에 접근하여 값 가져오기
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	// element 배열 free 후 ArrayQueue free
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	// current 와 max값 비교
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	// current 값 비교
}