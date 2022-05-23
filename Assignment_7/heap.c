#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

Heap* createHeap(int maxElementCount)
{
	if (maxElementCount <= 1)
		return (NULL);
	Heap *pHeap = (Heap *)malloc(sizeof(Heap));

	pHeap->maxElementCount = maxElementCount;
	pHeap->currentElementCount = 0;
	pHeap->pElement = (HeapNode *)malloc(sizeof(HeapNode) * maxElementCount + 1);
	if (pHeap->pElement == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	for (int i = 0; i < maxElementCount; i++)
		pHeap->pElement[i].data = 0;
	return (pHeap);
}

void deleteHeap(Heap** pHeap)
{
	if (*pHeap == NULL || (*pHeap)->pElement == NULL)
	{
		printf("invalid Heap\n");
		return ;
	}
	free((*pHeap)->pElement);
	(*pHeap)->pElement = NULL;
	free(*pHeap);
	*pHeap = NULL;
}

void swap(Heap* pHeap, int i)
{
	int tmp;

	tmp = pHeap->pElement[i].data;
	pHeap->pElement[i].data = pHeap->pElement[i / 2].data;
	pHeap->pElement[i / 2].data = tmp;
}

void insertMaxHeap(Heap* pHeap, HeapNode node)
{
	if (pHeap == NULL || pHeap->pElement == 0)
	{
		printf("invalid Heap\n");
		return ;
	}
	if (pHeap->currentElementCount == pHeap->maxElementCount)
	{
		printf("Heap is full\n");
		return ;
	}
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->pElement[i].data = node.data;
	while (i != 1 && pHeap->pElement[i].data >= pHeap->pElement[i / 2].data)
	{
		swap(pHeap, i);
		i /= 2;
	}
}

void insertMinHeap(Heap* pHeap, HeapNode node)
{
	if (pHeap == NULL || pHeap->pElement == 0)
	{
		printf("invalid Heap\n");
		return ;
	}
	if (pHeap->currentElementCount == pHeap->maxElementCount)
	{
		printf("Heap is full\n");
		return ;
	}
	pHeap->currentElementCount++;
	int i = pHeap->currentElementCount;
	pHeap->pElement[i].data = node.data;
	while (i != 1 && pHeap->pElement[i].data <= pHeap->pElement[i / 2].data)
	{
		swap(pHeap, i);
		i /= 2;
	}
}

void deleteMaxHeap(Heap* pHeap)
{
	if (pHeap == NULL || pHeap->pElement == 0)
	{
		printf("invalid Heap\n");
		return ;
	}
	if (pHeap->currentElementCount == 0)
	{
		printf("Heap is empty\n");
		return ;
	}
	pHeap->pElement[1].data = pHeap->pElement[pHeap->currentElementCount].data;
	pHeap->currentElementCount--;
	int i = 1;
	while (TRUE)
	{
		if (i * 2 > pHeap->maxElementCount)
			break ;
		else if (i * 2 + 1 > pHeap->maxElementCount)
			i *= 2;
		else
		{
			if (pHeap->pElement[i * 2].data > pHeap->pElement[i * 2 + 1].data)
				i *= 2;
			else
				i = (i * 2) + 1;
		}
		if (pHeap->pElement[i].data >= pHeap->pElement[i / 2].data)
			swap(pHeap, i);
		else
			break ;
	}
}

void deleteMinHeap(Heap* pHeap)
{
	if (pHeap == NULL || pHeap->pElement == 0)
	{
		printf("invalid Heap\n");
		return ;
	}
	if (pHeap->currentElementCount == 0)
	{
		printf("Heap is empty\n");
		return ;
	}
	pHeap->pElement[1].data = pHeap->pElement[pHeap->currentElementCount].data;
	pHeap->currentElementCount--;
	int i = 1;
	while (TRUE)
	{
		if (i * 2 > pHeap->maxElementCount)
			break ;
		else if (i * 2 + 1 > pHeap->maxElementCount)
			i *= 2;
		else
		{
			if (pHeap->pElement[i * 2].data < pHeap->pElement[i * 2 + 1].data)
				i *= 2;
			else
				i = (i * 2) + 1;
		}
		if (pHeap->pElement[i].data <= pHeap->pElement[i / 2].data)
			swap(pHeap, i);
		else
			break ;
	}
}

void displayHeap(Heap* pHeap)
{
	int	i;

	if (pHeap == NULL || pHeap->pElement == 0)
	{
		printf("invalid Heap\n");
		return ;
	}
	if (pHeap->currentElementCount == 0)
	{
		printf("the Heap is empty\n");
		return ;
	}
	for (i = 1; i <= pHeap->currentElementCount; i++)
		printf("%d ", pHeap->pElement[i].data);
}

int main(void)
{
	Heap *pHeap = createHeap(7);
	HeapNode node;

	/*
	node.data = 20;
	insertMaxHeap(pHeap, node);
	node.data = 2;
	insertMaxHeap(pHeap, node);
	node.data = 4;
	insertMaxHeap(pHeap, node);
	node.data = 6;
	insertMaxHeap(pHeap, node);
	node.data = 12;
	insertMaxHeap(pHeap, node);
	node.data = 30;
	insertMaxHeap(pHeap, node);
	node.data = 5;
	insertMaxHeap(pHeap, node);
	displayHeap(pHeap); // 결과값 30 12 20 2 6 4 5
	printf("\n");
	deleteMaxHeap(pHeap);
	displayHeap(pHeap); // 결과값 20 12 5 2 6 4
	*/

	node.data = 20;
	insertMinHeap(pHeap, node);
	node.data = 2;
	insertMinHeap(pHeap, node);
	node.data = 4;
	insertMinHeap(pHeap, node);
	node.data = 6;
	insertMinHeap(pHeap, node);
	node.data = 12;
	insertMinHeap(pHeap, node);
	node.data = 30;
	insertMinHeap(pHeap, node);
	node.data = 5;
	insertMinHeap(pHeap, node);
	displayHeap(pHeap); // 결과값 2 6 4 20 12 30 5
	printf("\n");
	deleteMinHeap(pHeap);
	displayHeap(pHeap); // 결과값 4 6 5 20 12 30
}