#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

// 헤더는 그냥 비어있고 그 다음 노드부터가 리스트의 시작으로 한다.
LinkedList* createLinkedList()
{
	LinkedList *pList;

	pList = (LinkedList *)malloc(sizeof(LinkedList));
	if (pList == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	pList->currentElementCount = 0;
	pList->headerNode.data = 0;
	pList->headerNode.pLink = NULL;
	return (pList);
}

// position이 만약 0이면 헤더를 가리키는 것으로 본다. 1이면 첫번째 노드
int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *tmp = &(pList->headerNode);

	if (position > pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (-1);
	}
	else
	{
		// 아직 미완성임. 여기서부터 이어서 가자
		for (int i = 0; i < position; i++)
			tmp = tmp->pLink;
		
	}
	return (pList->currentElementCount);
}
int removeLLElement(LinkedList* pList, int position)
{
	// if 문으로 position 값 적절한지 체크
	// 반복문 돌려서 position 빼고 노드 연결시켜주고
	// position에 해당하는 노드 free, NULL 처리
}
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList)
{
	// 뒤에서부터 free 하고 NULL 처리
}
int getLinkedListLength(LinkedList* pList)
{
	// 너무 쉬움
}
void deleteLinkedList(LinkedList* pList)
{
	// clear 하고 pList까지 free 및 NULL 처리
}