#include "graphlinkedlist.h"

/* 연결리스트 생성 */
LinkedList* createLinkedList()
{
	LinkedList *pList;

	pList = calloc(1, sizeof(LinkedList));
	if (pList == NULL)
	{
		printf("malloc failed\n");
		return (NULL);
	}
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
		return (ERROR);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	new = (ListNode *)malloc(sizeof(ListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	*new = element;
	front = getLLElement(pList, position - 1);
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
		return (ERROR);
	}
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	front = getLLElement(pList, position - 1);
	remove = front->pLink;
	front->pLink = remove->pLink;
	free(remove);
	pList->currentElementCount--;
	return (pList->currentElementCount);
}

/* 연결리스트 원소 반환 */
ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return (NULL);
	}
	if (pList->currentElementCount == 0 && position != -1)
	{
		printf("the LinkedList is empty\n");
		return (NULL);
	}
	if (position < -1 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (NULL);
	}
	if (position == -1) // add 함수에서 0번째 인덱스에 노드를 추가할 수 있게 하려면 이런 장치가 필요함
		return (&(pList->headerNode));
	get = (pList->headerNode).pLink;
	for (cnt = 0; cnt < position; cnt++)
		get = get->pLink;
	return (get);
}

/* 연결리스트 초기화 */
void clearLinkedList(LinkedList* pList)
{
	ListNode *clear;

	if (pList == NULL)
		printf("Invalid LinkedList\n");
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
		return(ERROR);
	}
	return (pList->currentElementCount);
}

/* 연결리스트 삭제 */
void deleteLinkedList(LinkedList* pList)
{
	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else
	{
		clearLinkedList(pList);
		free(pList);
	}
}

/* 연결리스트 출력 */
void displayLinkedList(LinkedList* pList)
{
	int	i;

	if (pList == NULL)
	{
		printf("Invalid LinkedList\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("the LinkedList is empty\n");
		return ;
	}
	for (i = 0; i < pList->currentElementCount; i++)
		printf("%d ", getLLElement(pList, i)->vertex.vertexID);
	printf("\n");
}

/* 연결리스트 순서 반전 */
void reverseLinkedList(LinkedList* pList)
{
	int	position;
	ListNode *get;
	ListNode *attach;
	ListNode *last;

	if (pList == NULL)
		printf("Invalid LinkedList\n");
	else
	{
		last = getLLElement(pList, pList->currentElementCount - 1);
		attach = last;
		for (position = pList->currentElementCount - 2; position >= 0; position--)
		{
			get = getLLElement(pList, position);
			attach->pLink = get;
			attach = get;
		}
		attach->pLink = NULL;
		pList->headerNode.pLink = last;
	}
}
