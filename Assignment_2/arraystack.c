#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack *pStack;

	pStack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (pStack == NULL)
	{
		printf("Error: malloc failed\n");
		return (NULL);
	}
	pStack->maxElementCount = maxElementCount;
	pStack->currentElementCount = 0;
	pStack->pElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (pStack->pElement == NULL)
	{
		printf("Error: malloc failed\n");
		free(pStack);
		return (NULL);
	}
	for (int i = 0; i < maxElementCount; i++)
		pStack->pElement[i].data = 0;
	return (pStack);
}

int pushAS(ArrayStack* pStack, StackNode element)
{
	if (pStack == NULL)
		return (ERROR);
	if (isArrayStackFull(pStack) == TRUE)
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popAS(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	pStack->currentElementCount--;
	return (&(pStack->pElement[pStack->currentElementCount]));
}

StackNode* peekAS(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (NULL);
	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	return (&(pStack->pElement[pStack->currentElementCount - 1]));
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack == NULL)
		return ;
	pStack->currentElementCount = 0;
	pStack->maxElementCount = 0;
	free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (ERROR);
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	if (pStack == NULL)
		return (ERROR);
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
	return (0);
}