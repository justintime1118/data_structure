#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	ArrayList *pList;
	ArrayListNode node;

	node.data = 1;
	
	pList = createArrayList(5);
	
	for (int i = 0; i < 6; i++)
	{
		addALElement(pList, i, node);
		printf("length == %d\n", getArrayListLength(pList));
		node.data++;
	}
	
	if (isArrayListFull(pList) == TRUE)
		printf("TRUE FULL\n");
	removeALElement(pList, 3);
	addALElement(pList, 1, node);
	// deleteArrayList(pList);
	// clearArrayList(pList);
	// addALElement(pList, 0, node);
	displayArrayList(pList);
}

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

void deleteArrayList(ArrayList* pList)
{
	if (pList == NULL)
	{
		printf("the ArrayList is NULL\n");
		return ;
	}
	pList->maxElementCount = 0;
	pList->currentElementCount = 0;
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (pList == NULL)
	{
		printf("the ArrayList is NULL\n");
		return (-1);
	}
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

// position이 index 번호로 주어진다고 가정
// 여기서 자바에서 사용하는 ArrayList처럼 만들어야 할지, 아니면 C의 primitive 배열처럼 만들어야 할지 고민이 됐다
// 고민 좀 하다가 둘이 섞은 방식으로 하기로 함
int addALElement(ArrayList* pList, int position, ArrayListNode element) 
{
	int	value = element.data;

	if (pList == NULL || pList->pElement == NULL)
	{
		printf("ArrayList is invalid\n");
		return (-1);
	}
	if (isArrayListFull(pList) == TRUE)
	{
		printf("the ArrayList is full\n");
		return (-1);
	}
	if (position < 0 || pList->currentElementCount < position)
	{
		printf("position out of bound\n");
		return (-1);
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
		printf("ArrayList is invalid\n");
	else if (pList->currentElementCount == 0)
		printf("the ArrayList is empty\n");
	else if (0 <= position && position < pList->currentElementCount)
	{
		for (int i = position; i < pList->currentElementCount - 1; i++)
			pList->pElement[i].data = pList->pElement[i + 1].data;
		pList->currentElementCount--;
		pList->pElement[pList->currentElementCount].data = 0;
		return (position);
	}
	return (-1);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("ArrayList is invalid\n");
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
	if (pList == NULL || pList->pElement == 0)
	{
		printf("ArrayList is invalid\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("the ArrayList is empty\n");
		return ;
	}
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("%d ", pList->pElement[i].data);
}

void clearArrayList(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("ArrayList is invalid\n");
		return ;
	}
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i].data = 0;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL || pList->pElement == 0)
	{
		printf("ArrayList is invalid\n");
		return (-1);
	}
	return (pList->currentElementCount);
}
