#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *pList = (ArrayList *)malloc(sizeof(ArrayList));

	pList->maxElementCount = maxElementCount;
	pList->currentElementCount = 0;
	pList->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (pList->pElement == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	for (int i = 0; i < maxElementCount; i++)
		pList->pElement[i].data = 0;
	return (pList);
}

void deleteArrayList(ArrayList** pList)
{
	if (*pList == NULL || (*pList)->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return ;
	}
	free((*pList)->pElement);
	(*pList)->pElement = NULL;
	free(*pList);
	*pList = NULL;
}

int isArrayListFull(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == NULL)
	{
		printf("invalid Array List\n");
		return (ERROR);
	}
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

int addALElement(ArrayList* pList, int position, ArrayListNode element) 
{
	int	value = element.data;

	if (pList == NULL || pList->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return (ERROR);
	}
	if (position < 0 || pList->currentElementCount < position || pList->maxElementCount == position)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	if (isArrayListFull(pList) == TRUE)
	{
		printf("the ArrayList is full\n");
		return (ERROR);
	}
	if (position <= pList->currentElementCount - 1)
	{
		for (int i = pList->currentElementCount - 1; i >= position; i--)
			pList->pElement[i + 1].data = pList->pElement[i].data;
	}
	pList->pElement[position].data = value;
	pList->currentElementCount++;
	return (position);
}

int removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL || pList->pElement == 0)
		printf("invalid ArrayList\n");
	else if (pList->currentElementCount == 0)
		printf("the ArrayList is empty\n");
	else if (position < 0 || (pList->currentElementCount) <= position)
		printf("position out of bound\n");
	else if (0 <= position && position < (pList->currentElementCount))
	{
		for (int i = position; i < pList->currentElementCount - 1; i++)
			pList->pElement[i].data = pList->pElement[i + 1].data;
		pList->currentElementCount--;
		pList->pElement[pList->currentElementCount].data = 0;
		return (position);
	}
	return (ERROR);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("invalid ArrayList\n");
		return (NULL);
	}
	if (position < 0 || pList->currentElementCount <= position)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	return (&(pList->pElement[position]));
}

void displayArrayList(ArrayList* pList)
{
	int	i;

	if (pList == NULL || pList->pElement == 0)
	{
		printf("invalid ArrayList\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("the ArrayList is empty\n");
		return ;
	}
	for (i = 0; i < pList->currentElementCount - 1; i++)
		printf("%d ", pList->pElement[i].data);
	printf("%d\n", pList->pElement[i].data);
}

void clearArrayList(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("invalid ArrayList\n");
		return ;
	}
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i].data = 0;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == NULL)
	{
		printf("invalid ArrayList\n");
		return (ERROR);
	}
	return (pList->currentElementCount);
}

/*
int main(void)
{
	ArrayList *pList;
	ArrayListNode node;

	node.data = 1;
	
	pList = createArrayList(10);
	
	for (int i = 0; i < 11; i++)
	{
		addALElement(pList, i, node);
		printf("CYCLE %d: length == %d\n", i, getArrayListLength(pList));
		node.data++;
	}
	
	if (isArrayListFull(pList) == TRUE)
		printf("TRUE: FULL\n");
	else
		printf("FALSE: NOT FULL\n");
	
	// removeALElement(pList, 3);
	// removeALElement(pList, 11);
	
	// if (isArrayListFull(pList) == TRUE)
	// 	printf("TRUE: FULL\n");
	// else
	// 	printf("FALSE: NOT FULL\n");
	
	// addALElement(pList, 10, node);

	// addALElement(pList, 3, node);
	// deleteArrayList(pList);
	// clearArrayList(pList);
	// addALElement(pList, 0, node);
	displayArrayList(pList);
}
*/