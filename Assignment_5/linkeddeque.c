#include "linkeddeque.h"

// 선형 양방향 리스트 덱으로 만든다
LinkedDeque* createLinkedDeque()
{
	LinkedDeque *pDeque;

	pDeque = malloc(sizeof(LinkedDeque));
	if (pDeque == NULL)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	pDeque->currentElementCount = 0;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	return (pDeque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*new;

	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (ERROR);
	}
	new = malloc(sizeof(DequeNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	new->data = element.data;
	new->pRLink = pDeque->pFrontNode;
	new->pLLink = NULL;
	if (pDeque->currentElementCount == 0)
		pDeque->pRearNode = new;
	else
		pDeque->pFrontNode->pLLink = new;
	pDeque->pFrontNode = new;
	pDeque->currentElementCount++;
	return (pDeque->currentElementCount);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*new;

	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (ERROR);
	}
	new = malloc(sizeof(DequeNode));
	if (new == NULL)
	{
		printf("malloc failed\n");
		return (ERROR);
	}
	new->data = element.data;
	new->pRLink = NULL;
	new->pLLink = pDeque->pRearNode;
	if (pDeque->currentElementCount == 0)
		pDeque->pFrontNode = new;
	else
		pDeque->pRearNode->pRLink = new;
	pDeque->pRearNode = new;
	pDeque->currentElementCount++;
	return (pDeque->currentElementCount);
}

int deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*tmp;

	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (ERROR);
	}
	if (pDeque->currentElementCount == 0)
		return (0);
	tmp = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	if (pDeque->currentElementCount == 1)
		pDeque->pRearNode = NULL;
	else
		pDeque->pFrontNode->pLLink = NULL;
	free(tmp);
	pDeque->currentElementCount--;
	return (pDeque->currentElementCount);
}

int deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*tmp;

	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (ERROR);
	}
	if (pDeque->currentElementCount == 0)
		return (0);
	tmp = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	if (pDeque->currentElementCount == 1)
		pDeque->pFrontNode = NULL;
	else
		pDeque->pRearNode->pRLink = NULL;
	free(tmp);
	pDeque->currentElementCount--;
	return (pDeque->currentElementCount);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (NULL);
	}
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (NULL);
	}
	return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	int			i;
	DequeNode	*target;
	DequeNode	*next;

	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return ;
	}
	next = pDeque->pFrontNode;
	while (next != NULL)
	{
		target = next;
		next = next->pRLink;
		free(target);
	}
	free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (pDeque == NULL)
	{
		printf("invalid Linked Deque\n");
		return (ERROR);
	}
	return (pDeque->currentElementCount == 0 ? TRUE : FALSE);
}

/*
int	main(void)
{
	LinkedDeque *pDeque;
	DequeNode element;
	DequeNode *tmp;

	element.data = 42;
	pDeque = createLinkedDeque();
	for (int i = 0; i < 5; i++)
	{
		insertFrontLD(pDeque, element);
		element.data++;
	}
	deleteFrontLD(pDeque);
	tmp = peekFrontLD(pDeque);
	printf("front == %d\n", tmp->data);
	for (int i = 0; i < 3; i++)
		deleteFrontLD(pDeque);
	tmp = peekFrontLD(pDeque);
	deleteLinkedDeque(pDeque);
	printf("front == %d\n", tmp->data);
	system("leaks test");
}
*/