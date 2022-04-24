#include "linkedstack.h"

// 순서 체킹 의사코드 작성
void	display(LinkedStack *pStack)
{
	int	i;
	StackNode *node;

	node = pStack->pTopElement;
	while (node != 0)
	{
		printf("%c ", node->data);
		node = node->pLink;
	}
	printf("\n");
}

int checkMatching(LinkedStack *pStack, char paren)
{
	char	matching;

	matching = peekLS(pStack)->data;
	if ((paren == ')' && matching == '(') \
		|| (paren == '}' && matching == '{') \
		|| (paren == ']' && matching == '['))
		return (TRUE);
	return (FALSE);
}

int main(int argc, char **argv)
{
	int	i = 0;
	char *input = argv[1];
	LinkedStack *pStack;
	StackNode element;

	pStack = createLinkedStack();

	if (input == NULL)
		return (1);
	while (input[i])
	{
		if (input[i] == '(' || input[i] == '{' || input[i] == '[')
		{	
			element.data = input[i];
			pushLS(pStack, element);
		}
		else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
		{
			if (isLinkedStackEmpty(pStack) == TRUE || checkMatching(pStack, input[i]) == FALSE)
			{
				printf("Unmatching!\n");
				deleteLinkedStack(pStack);
				return (0);
			}
			popLS(pStack);
		}
		i++;
		//display(pStack);
	}
	if (isLinkedStackEmpty(pStack) == TRUE)
		printf("Matching!\n");
	else
		printf("Unmatching!\n");
	deleteLinkedStack(pStack);
	return (0);
}