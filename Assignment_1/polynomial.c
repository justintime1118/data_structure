#include "polynomial.h"
#include <stdio.h>
#include <stdlib.h>

PolyList* createPolyList()
{
	PolyList *pList;

	pList = (PolyList *)malloc(sizeof(PolyList));
	if (pList == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	pList->currentElementCount = 0;
	pList->headerNode.coef = 0;
	pList->headerNode.degree = 0;
	pList->headerNode.pLink = NULL;
	return (pList);
}

int addPLElement(PolyList* pList, PolyListNode element)
{
	PolyListNode *front;
	PolyListNode *new;

	if (pList == NULL)
	{
		printf("Invalid PolyList\n");
		return (ERROR);
	}

	new = (PolyListNode *)malloc(sizeof(PolyListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	new->coef = element.coef;
	new->degree = element.degree;
	front = getPLElement(pList, pList->currentElementCount - 1);
	new->pLink = front->pLink;
	front->pLink = new;
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

PolyListNode* getPLElement(PolyList* pList, int position)
{
	PolyListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Invalid PolyList\n");
		return (NULL);
	}
	if (pList->currentElementCount == 0 && position != -1)
	{
		printf("the PolyList is empty\n");
		return (NULL);
	}
	if (position < -1 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	if (position == -1)
		return (&(pList->headerNode));
	get = (pList->headerNode).pLink;
	for (cnt = 0; cnt < position; cnt++)
		get = get->pLink;
	return (get);
}

void clearPolyList(PolyList* pList)
{
	PolyListNode *clear;

	if (pList == NULL)
		printf("Invalid PolyList\n");
	else
	{
		clear = (pList->headerNode).pLink;
		while (pList->currentElementCount)
		{
			pList->headerNode.pLink = clear->pLink;
			free(clear);
			clear = (pList->headerNode).pLink;
			pList->currentElementCount--;
		}
		(pList->headerNode).pLink = NULL;
	}
}

void deletePolyList(PolyList** pList)
{
	if (*pList == NULL)
		printf("Invalid PolyList\n");
	else
	{
		clearPolyList(*pList);
		free(*pList);
		*pList = NULL;
	}
}

void displayPolyList(PolyList* pList)
{
	PolyListNode *get;

	if (pList == NULL)
	{
		printf("Invalid PolyList\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("the PolyList is empty\n");
		return ;
	}
	for (get = getPLElement(pList, 0); get != NULL; get = get->pLink)
	{
		if (get->degree != 0)
			printf("%dx^%d ", get->coef, get->degree);
		else
			printf("%d ", get->coef);
	}
	printf("\n");
}

PolyList* addPolyLists(PolyList* pList1, PolyList* pList2)
{
	PolyList* ret = createPolyList();
	PolyListNode* node1 = getPLElement(pList1, 0);
	PolyListNode* node2 = getPLElement(pList2, 0);

	PolyListNode node;

	while (node1 != NULL && node2 != NULL)
	{
		if (node1->degree == node2->degree)
		{
			node.degree = node1->degree;
			node.coef = node1->coef + node2->coef;
			node1 = node1->pLink;
			node2 = node2->pLink;
		}
		else if (node1->degree > node2->degree)
		{
			node = *node1;
			node1 = node1->pLink;
		}
		else
		{
			node = *node2;
			node2 = node2->pLink;
		}
		addPLElement(ret, node);
	}
	if (node1 == NULL && node2 == NULL)
		return (ret);
	node = (node1 == NULL ? *node2 : *node1);
	printf("out!\n");
	while (1)
	{
		addPLElement(ret, node);
		if (node.pLink == NULL)
			break ;
		node = *(node.pLink);
	}
	return(ret);
}

/*
int main(void)
{
	PolyListNode	node;
	PolyList* lst1;
	PolyList* lst2;
	PolyList* res;

	// 다항식 두개 만들기
	int co_arr1[] = {2, 4, 6, 8, 10};
	int deg_arr1[] = {12, 10, 8, 6, 4};
	int co_arr2[] = {2, 4, 6, 8, 10, 4, 3, 1};
	int deg_arr2[] = {13, 10, 8, 7, 5, 3, 2, 1};
	lst1 = createPolyList();
	lst2 = createPolyList();
	for (int i = 0; i < 5; i++)
	{
		node.coef = co_arr1[i];
		node.degree = deg_arr1[i];
		addPLElement(lst1, node);
	}
	for (int i = 0; i < 8; i++)
	{
		node.coef = co_arr2[i];
		node.degree = deg_arr2[i];
		addPLElement(lst2, node);
	}

	displayPolyList(lst1);
	displayPolyList(lst2);
	printf("0 done!\n");
	// 다항식 덧셈 연산
	res = addPolyLists(lst1, lst2);
	displayPolyList(res);

	deletePolyList(&res);
	displayPolyList(res);
	system("leaks test");
	return (0);
}
*/