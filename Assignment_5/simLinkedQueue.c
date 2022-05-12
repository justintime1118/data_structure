#include "simLinkedQueue.h"

LinkedQueue *createLinkedQueue(void)
{
	LinkedQueue *queue;

	queue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
	if (!queue)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	queue->currentElementCount = 0;
	queue->front = 0;
	queue->rear = 0;
	return (queue);
}

void deleteLinkedQueue(LinkedQueue *pQueue)
{
	LinkedQueueNode *node;
	LinkedQueueNode *temp;

	if (!pQueue)
	{
		printf("[error] Queue is null.\n");
		return;
	}
	node = pQueue->front;
	while (node)
	{
		temp = node->pLink;
		free(node);
		node = temp;
	}
	free(pQueue);
	pQueue = NULL;
}

LinkedQueueNode *dequeueLQ(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	LinkedQueueNode *node;
	node = pQueue->front;
	pQueue->front = pQueue->front->pLink;
	node->pLink = NULL;
	if (pQueue->currentElementCount == 1) //노드가 한개일 때는 리어 처리도 해야 함
		pQueue->rear = NULL;
	pQueue->currentElementCount--;
	return (node);
}

int enqueueLQ(LinkedQueue *pQueue, LinkedQueueNode element)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (FALSE);
	}

	LinkedQueueNode *node;
	node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
	if (!node)
	{
		printf("[error] Memory allocate failed.\n");
		return (FALSE);
	}

	*node = element;
	node->pLink = NULL;
	if (isLinkedQueueEmpty(pQueue) == 1)
	{
		pQueue->front = node;
		pQueue->rear = node;
	}
	else
	{
		pQueue->rear->pLink = node;
		pQueue->rear = node;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

int	isLinkedQueueEmpty(LinkedQueue *pQueue)
{
	if (!pQueue)
		return (-1);
	if (pQueue->currentElementCount == 0)
		return (1);
	return (0);
}

LinkedQueueNode *peekLQ(LinkedQueue *pQueue)
{
	if (pQueue == NULL)
	{
		printf("[error] Queue is null.\n");
		return (NULL);
	}
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("[error] Queue is empty.\n");
		return (NULL);
	}
	return (pQueue->front);
}