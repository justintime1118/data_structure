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
	{
		pHeap->pElement[i].x = 0;
		pHeap->pElement[i].y = 0;
		pHeap->pElement[i].weight = 0;
	}
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
	HeapNode tmp;

	tmp = pHeap->pElement[i];
	pHeap->pElement[i] = pHeap->pElement[i / 2];
	pHeap->pElement[i / 2] = tmp;
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
	pHeap->pElement[i] = node;
	while (i != 1 && pHeap->pElement[i].weight >= pHeap->pElement[i / 2].weight)
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
	pHeap->pElement[i] = node;
	while (i != 1 && pHeap->pElement[i].weight <= pHeap->pElement[i / 2].weight)
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
	pHeap->pElement[1].weight = pHeap->pElement[pHeap->currentElementCount].weight;
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
			if (pHeap->pElement[i * 2].weight > pHeap->pElement[i * 2 + 1].weight)
				i *= 2;
			else
				i = (i * 2) + 1;
		}
		if (pHeap->pElement[i].weight >= pHeap->pElement[i / 2].weight)
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
	pHeap->pElement[1].weight = pHeap->pElement[pHeap->currentElementCount].weight;
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
			if (pHeap->pElement[i * 2].weight < pHeap->pElement[i * 2 + 1].weight)
				i *= 2;
			else
				i = (i * 2) + 1;
		}
		if (pHeap->pElement[i].weight <= pHeap->pElement[i / 2].weight)
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
		printf("%d ", pHeap->pElement[i].weight);
}
