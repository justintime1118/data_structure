#include	"linkedlist.h"
#include	<stdio.h>
#include	<stdlib.h>


int	main(void)
{
	LinkedList *alist;
	ListNode element;
	ListNode *get;
	int	i;

	alist = createLinkedList();
	element.data = 33;
	element.pLink = NULL;

	for (int i = 0; i < 5; i++) // 33, 34, 35, 36, 37
	{
		addLLElement(alist, i, element);
		element.data++;
	}
	for (int i = 0; i < getLinkedListLength(alist); i++)
		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");

	removeLLElement(alist, 2);

	element.data = 100;
	addLLElement(alist, 2, element);

	removeLLElement(alist, 4);

	for (int i = 0; i < getLinkedListLength(alist); i++)
 		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");



	for (int i = 0; i < 5; i++)
	{
		addLLElement(alist, i, element);
		element.data++;
	}
	for (int i = 0; i < getLinkedListLength(alist); i++) // 100, 101, 102, 103, 104
 		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");

	printf("get length %d\n", getLinkedListLength(alist));



	clearLinkedList(alist);
	for (int i = 0; i < getLinkedListLength(alist); i++)
 		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");



	for (int i = 0; i < 5; i++)
	{
		addLLElement(alist, i, element);
		element.data++;
	}
	for (int i = 0; i < getLinkedListLength(alist); i++) // 105, 106, 107, 108, 109
 		printf("%d ", getLLElement(alist, i)->data);
	printf("\n");




	deleteLinkedList(alist);
	printf("after delete test!\n");

	addLLElement(alist, 0, element);
	removeLLElement(alist, 0);
	getLLElement(alist, 0);
	clearLinkedList(alist);
	printf("get length %d\n", getLinkedListLength(alist));
	deleteLinkedList(alist);

//	system("leaks a.out");
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
	ListNode *front;
	ListNode *new;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (-1);
	}
	if (pList->currentElementCount == -1)
	{
		printf("deleted LinkedList\n");
		return (-1);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position out of bounds\n");
		return (-1);
	}
	new = (ListNode *)malloc(sizeof(ListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (-1);
	}
	new->data = element.data;
	front = getLLElement(pList, position - 1); //
	new->pLink = front->pLink;
	front->pLink = new;
	pList->currentElementCount++;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 삭제 */
int removeLLElement(LinkedList* pList, int position)
{
	ListNode *remove;
	ListNode *front;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (-1);
	}
	if (pList->currentElementCount == -1)
	{
		printf("deleted LinkedList\n");
		return (-1);
	}
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (-1);
	}
	front = getLLElement(pList, position - 1);
	remove = front->pLink;
	front->pLink = remove->pLink;
	free(remove);
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 반환 */ /////
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (NULL);
	}
	if (pList->currentElementCount == -1)
	{
		printf("deleted LinkedList\n");
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
	get = (pList->headerNode).pLink; // 0번째 노드
	for (cnt = 0; cnt < position; cnt++) // position만큼 뒤로 이동
		get = get->pLink;
	return (get);
}

/* 연결리스트 초기화 */
void clearLinkedList(LinkedList* pList)
{
	ListNode *clear;

	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else if (pList->currentElementCount == -1)
		printf("deleted Linked List\n");
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

/* 연결리스트 길이 반환 */
int getLinkedListLength(LinkedList* pList)
{
	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return(-1);
	}
	else if (pList->currentElementCount == -1)
	{
		printf("deleted Linked List\n");
		return (-1);
	}
	return (pList->currentElementCount);
}

/* 연결리스트 삭제 */
void deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else if (pList->currentElementCount == -1)
		printf("deleted Linked List\n");
	else
	{
		clearLinkedList(pList);
		free(pList);
		pList->currentElementCount = -1;
	}
}
