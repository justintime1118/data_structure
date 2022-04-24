#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *pStack = (ArrayStack *)malloc(sizeof(ArrayStack));

	pStack->maxElementCount = maxElementCount;
	pStack->currentElementCount = 0;
	pStack->pElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (pStack->pElement == 0)
	{
		printf("malloc failed\n");
		return (NULL);
	}
	for (int i = 0; i < maxElementCount; i++)
		pStack->pElement[i].data = 0;
	return (pStack);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
	if (pStack == 0)
		return (ERROR);
	if (isArrayStackFull(pStack) == TRUE)
		return (ERROR);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
	if (pStack == 0)
		return (NULL);
	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	pStack->currentElementCount--;
	return (&(pStack->pElement[pStack->currentElementCount]));
}

StackNode* peekAS(ArrayStack* pStack)
{
	if (pStack == 0)
		return (NULL);
	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	return (&(pStack->pElement[pStack->currentElementCount - 1]));
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack == 0)
		return ;
	pStack->currentElementCount = 0;
	pStack->maxElementCount = 0;
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (pStack == 0)
	{
		printf("pStack is NULL\n");
		return (ERROR);
	}
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack == 0)
	{
		printf("pStack is NULL\n");
		return (ERROR);
	}
	return (pStack->currentElementCount == 0);
}

int	main(void)
{
	ArrayStack *pStack;
	StackNode element;

	element.data = 0;
	pStack = createArrayStack(10);
	for (int i = 0; i < 11; i++)
	{
		pushAS(pStack, element);
		element.data++;
	}
	if (isArrayStackFull(pStack))
		printf("Stack is FULL!\n");
	printf("peek result = %d\n", peekAS(pStack)->data);
	while (pStack->currentElementCount)
		printf("%d ", popAS(pStack)->data);
	printf("\n");
	if (isArrayStackEmpty(pStack))
		printf("Stack is EMPTY!\n");
	deleteArrayStack(pStack);
	printf("peek result = %d\n", peekAS(pStack)->data);
	return (0);
}