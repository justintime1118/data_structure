#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>



/* 원형 연결리스트 생성 */
CircularList* createCircularList()
{
	CircularList *pList;

	pList = (CircularList *)malloc(sizeof(CircularList));
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

/* 원형 연결리스트 원소 추가 */
int addCLElement(CircularList* pList, int position, CircularListNode element)
{
	CircularListNode *front;
	CircularListNode *new;
	CircularListNode *back;

	if (pList == NULL)
	{
		printf("Invalid CircularList\n");
		return (ERROR);
	}
	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position out of bounds\n");
		return (ERROR);
	}
	new = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	new->data = element.data;
	front = getCLElement(pList, position - 1);
	new->pLink = front->pLink;
	front->pLink = new;
	pList->currentElementCount++;
	if (position == 0 && pList->currentElementCount != 1) // 0번째 유일하지 않은 노드에 변화가 있을때
	{
		back = getCLElement(pList, pList->currentElementCount - 1);
		back->pLink = new;
	}
	else if (pList->currentElementCount == 1) //처음 만들어진 노드이면 자기자신을 가리키도록
		new->pLink = new;
	return (pList->currentElementCount);
}

/* 원형 연결리스트 원소 삭제 */
int removeCLElement(CircularList* pList, int position)
{
	CircularListNode *remove;
	CircularListNode *front;
	CircularListNode *back;

	if (pList == NULL)
	{
		printf("Invalid CircularList\n");
		return (ERROR);
	}
	if (position < 0 || position >= pList->currentElementCount)
	{
		printf("position out of bound\n");
		return (ERROR);
	}
	front = getCLElement(pList, position - 1);
	remove = front->pLink;
	front->pLink = remove->pLink;
	free(remove);
	pList->currentElementCount--;
	if (remove == pList->headerNode.pLink)  // remove가 마지막 노드였다면, headernode에 널처리
		pList->headerNode.pLink = NULL;
	else if (position == 0)
	{
		back = getCLElement(pList, pList->currentElementCount - 1);
		back->pLink = pList->headerNode.pLink;
	}
	return (pList->currentElementCount);
}

/* 원형 연결리스트 원소 반환 */
CircularListNode* getCLElement(CircularList* pList, int position)
{
	CircularListNode *get;
	int	cnt;

	if (pList == NULL)
	{
		printf("Invalid CircularList\n");
		return (NULL);
	}
	if (pList->currentElementCount < 0 && position != -1)
	{
		printf("the CircularList is empty\n");
		return (NULL);
	}
	if (position < -1) //
	{
		printf("position out of bound\n");
		return (NULL);
	}
	if (position == -1)
		return (&(pList->headerNode));
	position = position % pList->currentElementCount; // position이 넘어가도 계산이 된다.
	get = (pList->headerNode).pLink;
	for (cnt = 0; cnt < position; cnt++)
		get = get->pLink;
	return (get);
}

/* 원형 연결리스트 초기화 */
void clearCircularList(CircularList* pList)
{
	CircularListNode *clear;

	if (pList == NULL)
		printf("Invalid CircularList\n");
	else
	{
		clear = (pList->headerNode).pLink;
		while (pList->currentElementCount)
		{
			pList->headerNode.pLink = clear->pLink;
			clear->data = 0;
			free(clear);
			clear = (pList->headerNode).pLink;
			pList->currentElementCount--;
		}
		(pList->headerNode).pLink = NULL;
	}
}

/* 원형 연결리스트 길이 반환 */
int getCircularListLength(CircularList* pList)
{
	if (pList == NULL)
	{
		printf("Invalid CircularList\n");
		return(ERROR);
	}
	return (pList->currentElementCount);
}

/* 원형 연결리스트 삭제 */
void deleteCircularList(CircularList** pList)
{
	if (pList == NULL)
		printf("Invalid CircularList\n");
	else
	{
		clearCircularList(*pList);
		free(*pList);
		*pList = NULL;
	}
}

/* 원형 연결리스트 출력 */
void displayCircularList(CircularList* pList)
{
	int	i;

	if (pList == NULL)
		printf("Invalid CircularList\n");
	else if (pList->currentElementCount == 0) //추가
		printf("the CircularList is empty\n");
	else
	{
		for (i = 0; i < pList->currentElementCount - 1; i++)
			printf("%d ", getCLElement(pList, i)->data);
 		printf("%d\n", getCLElement(pList, i)->data);
	}
}

/* 원형 연결리스트 순서 반전 */
void reverseLinkedList(CircularList* pList) ///
{
	int	position;
	CircularListNode *get;
	CircularListNode *attach;
	CircularListNode *last;

	if (pList == NULL)
		printf("Invalid CircularList\n");
	else if (pList->currentElementCount == 0) //추가
		printf("the CircularList is empty\n");
	else
	{
		last = getCLElement(pList, pList->currentElementCount - 1);
		attach = last;
		for (position = pList->currentElementCount - 2; position >= 0; position--)
		{
			get = getCLElement(pList, position);
			attach->pLink = get;
			attach = get;
		}
		attach->pLink = last; //수정
		pList->headerNode.pLink = last;
	}
}


int main(void)
{
	CircularListNode	node;
	CircularList* pList;

	node.data = 1;
	node.pLink = NULL;
	pList = createCircularList();
	addCLElement(pList, 0, node);
	displayCircularList(pList);
	node.data = 2;
	addCLElement(pList, 1, node);
	node.data = 3;
	addCLElement(pList, 2, node);
	printf("get %d\n", getCLElement(pList, 2)->data);
	displayCircularList(pList);

	printf("get %d\n", getCLElement(pList, 2)->pLink->data);

	removeCLElement(pList, 2);
	displayCircularList(pList);
	printf("get %d\n", getCLElement(pList, 2)->data); //get 수정
	getchar();

	clearCircularList(pList);

	displayCircularList(pList);

	deleteCircularList(&pList);

	displayCircularList(pList);
//	system("leaks a.out");
	return (0);
}


// 원형리스트는 언제 쓰이는가?
// RR 스케줄링 알고리즘
// ..