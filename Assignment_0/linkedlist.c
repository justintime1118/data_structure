#include	"linkedlist.h"
#include	<stdio.h>
#include	<stdlib.h>


int	main(void)
{
	LinkedList *alist;
	ListNode *element;
	ListNode *get;
	int	i;

	alist = createLinkedList();
	element = (ListNode *)malloc(sizeof(ListNode));
	element->data = 33;
	element->pLink = NULL;
	for (int i = 0; i < 5; i++)
	{
		addLLElement(alist, i, *element);
		element->data++;
	}
	for (int i = 0; i < getLinkedListLength(alist); i++)
		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");
	//removeLLElement(alist, 2);
	deleteLinkedList(alist);
	// for (int i = 0; i < getLinkedListLength(alist); i++)
	// 	printf("%d ", getLLElement(alist, i)->data);
	// printf("\n");
	// printf("size == %d\n", getLinkedListLength(alist));
	system("leaks a.out");
	return(0);
}

/* 연결리스트 생성 */
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

/* 연결리스트 원소 추가 */
int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *tmp;
	ListNode *new;

	if (position < 0 || position > pList->currentElementCount)
	{
		printf("1position out of bound\n");
		return (-1);
	}
	new = (ListNode *)malloc(sizeof(ListNode));
	new->data = element.data;
	new->pLink = NULL;
	if (position == 0)
	{
		tmp = (pList->headerNode).pLink;
		(pList->headerNode).pLink = new;
	}
	else
	{
		tmp = getLLElement(pList, position - 1);
		element.pLink = tmp->pLink;
		tmp->pLink = new;
	}
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 삭제 */
int removeLLElement(LinkedList* pList, int position)
{
	ListNode *remove;
	ListNode *tmp;

	if (position < 0 || position > pList->currentElementCount)
	{
		printf("2position is out of bound\n");
		return (-1);
	}
	tmp = getLLElement(pList, position - 1);
	remove = tmp->pLink;
	tmp->pLink = remove->pLink;
	free(remove);
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 반환 */ /////
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *tmp;
	int	cnt;

	if (pList == NULL)
		printf("the Array List is NULL\n");
	else if (pList->currentElementCount == 0)
		printf("LinkedList is empty\n");
	else if (position < 0 || position >= pList->currentElementCount)
		printf("3position is out of bound\n");
  	else
	{
		tmp = (pList->headerNode).pLink; // 첫번째 노드
		for (cnt = 0; cnt < position; cnt++) // position만큼 뒤로 이동
			tmp = tmp->pLink;
		return (tmp);
	}
	return (NULL);
}

/* 연결리스트 초기화 */
void clearLinkedList(LinkedList* pList)
{
	ListNode *clear;

	if (pList == NULL)
		printf("the Array List is NULL\n");
	else if (pList->currentElementCount == 0)
		;
	else
	{
		clear = (pList->headerNode).pLink;
		while (--(pList->currentElementCount))
		{
			(pList->headerNode).pLink = clear->pLink;
			free(clear);
			clear = (pList->headerNode).pLink;
		}
		(pList->headerNode).pLink = NULL;
	}
}

/* 연결리스트 길이 반환 */
int getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
	{
		printf("the Array List is NULL\n");
		return (-1);
	}
	return (pList->currentElementCount);
}

/* 연결리스트 삭제 */
void deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		printf("the Array List is NULL\n");
	else
	{
		clearLinkedList(pList);
		free(pList);
		pList->currentElementCount = -1;
	}
}