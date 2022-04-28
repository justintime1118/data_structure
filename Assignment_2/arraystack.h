#ifndef _ARRAY_STACK_
# define _ARRAY_STACK_

# include <stdlib.h>
# include <stdio.h>

typedef struct StackNodeType
{
	int x;				// x좌표
	int y;				// y좌표
	int direction;		// 가야할 방향. DIRECTION_OFFSETS[NUM_DIRECTIONS]에서 들어갈 인덱스 번호라고 생각하면 됨
} StackNode;

typedef struct ArrayStackType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	StackNode* pElement;
} ArrayStack;

ArrayStack*	createArrayStack(int maxElementCount);
int			pushAS(ArrayStack* pStack, StackNode element);
StackNode*	popAS(ArrayStack* pStack);
StackNode*	peekAS(ArrayStack* pStack);
void		deleteArrayStack(ArrayStack* pStack);
int			isArrayStackFull(ArrayStack* pStack);
int			isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
# define _COMMON_STACK_DEF_

# define TRUE		1
# define FALSE		0
# define ERROR		-1

#endif