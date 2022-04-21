#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyList* createDoublyList()
{
	DoublyList *pList;

	pList = (DoublyList *)malloc(sizeof(DoublyList));
	if (pList == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	pList->currentElementCount = 0;
	pList->headerNode.data = 0;
	pList->headerNode.pLLink = &(pList->headerNode);
	pList->headerNode.pRLink = &(pList->headerNode);
	return (pList);
}

void deleteDoublyList(DoublyList* pList);

int addDLElement(DoublyList* pList, int position, DoublyListNode element);

int removeDLElement(DoublyList* pList, int position);

void clearDoublyList(DoublyList* pList);

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return(ERROR);
	}
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (NULL);
	}
	if (pList->currentElementCount < 0 && position != -1)
	{
		printf("the LinkedList is empty\n");
		return (NULL);
	}
	if (position < -1 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	if (position == -1)
		return (&(pList->headerNode));
	get = (pList->headerNode).pRLink;
	for (cnt = 0; cnt < position; cnt++)
		get = get->pRLink;
	return (get);
}

void displayDoublyList(DoublyList* pList);