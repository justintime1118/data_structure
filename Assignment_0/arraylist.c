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
		perror(NULL);
	return (pList);
}

// 매개변수로 주어지는 pList가 NULL일 경우에 대해서 따로 처리를 해줘야할까?

void deleteArrayList(ArrayList* pList)
{
	pList->maxElementCount = 0;
	pList->currentElementCount = 0;
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
}

int isArrayListFull(ArrayList* pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	else
		return (FALSE);
}

// position이 index 번호로 주어진다고 가정.
int addALElement(ArrayList* pList, int position, ArrayListNode element) 
{
	// 기존 배열이 꽉 차있었는지 등등에 따라서 달라짐
	// currentElementCount에도 반영해줘야 함
}

int removeALElement(ArrayList* pList, int position)
{
	if (0 <= position && position < pList->currentElementCount)
	{
		for (int i = position; i < pList->currentElementCount - 1; i++)
			pList->pElement[i].data = pList->pElement[i + 1].data;
		pList->currentElementCount--;
		pList->pElement[pList->currentElementCount].data = 0;
		return (position);
	}
	else if (pList->currentElementCount == 0)
		printf("the ArrayList is empty\n");
	return (-1);
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (0 <= position && position < pList->maxElementCount)
		return (&(pList->pElement[position]));
	else
		return (NULL);
}

void displayArrayList(ArrayList* pList)
{
	for (int i = 0; i < pList->currentElementCount; i++)
		printf("%d ", pList->pElement[i]);
}

void clearArrayList(ArrayList* pList)
{
	for (int i = 0; i < pList->currentElementCount; i++)
		pList->pElement[i].data = 0;
}

int getArrayListLength(ArrayList* pList)
{
	return (pList->currentElementCount);
}

/*
선형 자료구조 - 배열, 리스트
비선형 자료구조 - 트리, 그래프

시간복잡도
insert - 배열 n, 리스트 1
값 추출 - 배열 1, 리스트 n

두 자료구조 간의 차이와 장단점, 어떤 경우에 어떤 자료구조를 선택하는 것이 좋은지에 대해서 잘 생각해 볼 것
*/