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
	pQueue->currentElementCount = 0;
	pQueue->maxElementCount = maxElementCount;
	pQueue->front = 0;
	pQueue->rear = 0;
	for (int i = 0; i < maxElementCount; i++)
		pQueue->pElement[i].data = 0;
	return (pQueue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue == NULL)
	{
		printf("invalid Array Queue\n");
		return (NULL);
	}
	if (isArrayQueueFull(pQueue) == TRUE)
		return (pQueue->currentElementCount);
	if (isArrayQueueEmpty(pQueue) == TRUE)
		pQueue->pElement[0].data = element.data;
	else
	{
		pQueue->pElement[(pQueue->rear + 1) % pQueue->maxElementCount].data = element.data;
		pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	}
	pQueue->currentElementCount++;
	return (pQueue->currentElementCount);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*ret;

	if (pQueue == NULL)
	{
		printf("invalid Array Queue\n");
		return (NULL);
	}
	if (isArrayQueueEmpty(pQueue) == TRUE)
		return (NULL);
	ret = &(pQueue->pElement[pQueue->front]);
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (ret);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
	{
		printf("invalid Array Queue\n");
		return (NULL);
	}
	if (isArrayQueueEmpty(pQueue) == TRUE)
		return (NULL);
	else
		return (&pQueue->pElement[pQueue->front]);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
	{
		printf("invalid Array Queue\n");
		return (ERROR);
	}
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
	{
		printf("invalid Array Queue\n");
		return (ERROR);
	}
	return (pQueue->currentElementCount == pQueue->maxElementCount ? TRUE : FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (pQueue == NULL)
	{
		printf("invalid Array Queue\n");
		return (ERROR);
	}
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}



int	main(void)
{
	ArrayQueue *pQueue;
	ArrayQueueNode element;

	element.data = 42;
	pQueue = createArrayQueue(1);
	for (int i = 0; i < 6; i++)
	{
		enqueueAQ(pQueue, element);
		element.data++;
	}
	/*
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n", peekAQ(pQueue)->data);
		dequeueAQ(pQueue);
	}
	*/

}