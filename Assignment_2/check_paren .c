#include "linkedstack.h"

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

int	check_paren(char *input)
{
	LinkedStack *pStack;
	StackNode	element;
	int			flag_unmatch;
	int			i;

	if (input == NULL)
		return (ERROR);
	pStack = createLinkedStack();
	flag_unmatch = FALSE;
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
				flag_unmatch = TRUE;
				break ;
			}
			free(popLS(pStack));
		}
	}
	if (flag_unmatch == TRUE || isLinkedStackEmpty(pStack) == FALSE)
		printf("%s\t -> Unmatched\n", input);
	else
		printf("%s\t -> Matched\n", input);
	deleteLinkedStack(pStack);
	return (!flag_unmatch);
}

int main(int argc, char **argv)
{
	char 		*input;
	
	if (argc > 1)
		input = argv[1];
	else
		input = "[ { ( ) } ]";
	
	check_paren(input);
	check_paren("(A+B)*C ");
	check_paren("{(A+B)*C}*D");

	check_paren("(A+B)*C)");
	check_paren("((A+B)*B");
	check_paren("{(A+B})*C*D");

	check_paren("( ( A * B ) / C ) - { ( D + E ) && ( F – G ) }");
	check_paren("( ( A * B ) / C - { ( D + E ) && ( F – G ) ) }");

	return (0);
}
