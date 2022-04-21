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

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
	{
		printf("Invalid DoublyList\n");
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
		printf("Invalid DoublyList\n");
		return (NULL);
	}
	if (pList->currentElementCount < 0 && position != -1)
	{
		printf("the DoublyList is empty\n");
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

void displayDoublyList(DoublyList* pList)
{
	if (pList == NULL)
	{
		printf("Invalid DoublyList\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("the DoublyList is empty\n");
		return ;
	}
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("%d ", getDLElement(pList, i)->data);
	printf("\n");
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *front;
	DoublyListNode *new;

	if (pList == NULL)
	{
		printf("Invalid DoublyList\n");
		return (ERROR);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	new->data = element.data;
	front = getDLElement(pList, position - 1);
	new->pLLink = front;
	new->pRLink = front->pRLink;
	front->pRLink = new;
	new->pRLink->pLLink = new;
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *target;
	DoublyListNode *front;
	DoublyListNode *next;

	if (pList == NULL)
	{
		printf("Invalid DoublyList\n");
		return (ERROR);
	}
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	front = getDLElement(pList, position - 1);
	target = front->pRLink;
	next = target->pRLink;
	front->pRLink = next;
	next->pLLink = front;
	free(target);
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode *clear;

	if (pList == NULL)
		printf("Invalid DoublyList\n");
	else
	{
		clear = (pList->headerNode).pRLink;
		while (pList->currentElementCount)
		{
			pList->headerNode.pRLink = clear->pRLink;
			clear->data = 0;
			free(clear);
			clear = (pList->headerNode).pRLink;
			pList->currentElementCount--;
		}
		pList->headerNode.pLLink = &(pList->headerNode);
		pList->headerNode.pRLink = &(pList->headerNode);
	}
}

void deleteDoublyList(DoublyList** pList)
{
	if (*pList == NULL)
		printf("Invalid LinkedList\n");
	else
	{
		clearDoublyList(*pList);
		free(*pList);
		*pList = NULL;
	}
}

int	main(void)
{
	DoublyListNode element;
	element.data = 42;
	DoublyList *lst = createDoublyList();
	
	printf("0 before add, length == %d\n", getDoublyListLength(lst));

	for (int i = 0; i < 5; i++) {
		addDLElement(lst, i, element);
		element.data++;
	}
	displayDoublyList(lst);
	printf("1 after add, length == %d\n", getDoublyListLength(lst));

	for (int i = 0; i < 5; i++) 
		removeDLElement(lst, 0);
	displayDoublyList(lst);
	printf("2 after remove, length == %d\n", getDoublyListLength(lst));

	for (int i = 0; i < 5; i++) {
		addDLElement(lst, i, element);
		element.data++;
	}
	displayDoublyList(lst);
	printf("3 after add, length == %d\n", getDoublyListLength(lst));

	clearDoublyList(lst);
	displayDoublyList(lst);
	printf("4 after clear, length == %d\n", getDoublyListLength(lst));

	//deleteDoublyList(&lst);
	//displayDoublyList(lst);
	// 순환형이 계속 잘 유지되는지 검사
	// 0이 될 때까지 remove했을 때 헤더노드를 가리키도록 만들어야 함
}