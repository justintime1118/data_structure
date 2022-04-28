#include "mapdef.h"


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
	pStack->pElement = (MapPosition *)malloc(sizeof(MapPosition) * maxElementCount);
	if (pStack->pElement == NULL)
	{
		printf("Error: malloc failed\n");
		free(pStack);
		return (NULL);
	}
	memset(pStack->pElement, 0, pStack->maxElementCount);
	return (pStack);
}

int pushAS(ArrayStack* pStack, MapPosition element)
{
	if (pStack == NULL)
		return (ERROR);
	if (isArrayStackFull(pStack) == TRUE)
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

MapPosition* popAS(ArrayStack* pStack)
{
	MapPosition *ret;

	if (pStack == NULL)
		return (NULL);
	if (isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	ret = malloc(sizeof(MapPosition));
	if (ret == NULL)
		return (NULL);
	pStack->currentElementCount--;
	*ret = pStack->pElement[pStack->currentElementCount];
	return (ret);
}

MapPosition* peekAS(ArrayStack* pStack)
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
