#include "linkedstack.h"

/*
<순서 체킹>
현재 들어온 괄호가 무엇인지를 판단
판단 결과에 따라서 스택 목록을 쭉 순회하면서 있어서는 안될 괄호가 먼저 나온적이 있는지를 검사해주면 됨
*/

void	display(LinkedStack *pStack)
{
	int	i;
	StackNode *node;

	node = pStack->pTopElement;
	while (node)
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
	LinkedStack *pStack;
	StackNode	element;
	char 		*input;
	int			i;

	if (argc > 1)
		input = argv[1];
	else
		input = "[ { ( ) } ]";
	pStack = createLinkedStack();
	if (input == NULL)
		return (1);
	i = -1;
	while (input[++i])
	{
		if (input[i] == '(' || input[i] == '{' || input[i] == '[')
		{
			element.data = input[i];
			pushLS(pStack, element);
		}
		else if (input[i] == ')' || input[i] == '}' || input[i] == ']')
		{
			if (isLinkedStackEmpty(pStack) == TRUE \
				|| checkMatching(pStack, input[i]) == FALSE)
			{
				printf("Unmatching!\n");
				deleteLinkedStack(pStack);
				return (0);
			}
			popLS(pStack);
		}
	}
	if (isLinkedStackEmpty(pStack) == TRUE)
		printf("Matching!\n");
	else
		printf("Unmatching!\n");
	deleteLinkedStack(pStack);
	return (0);
}