#ifndef _MAP_DEF_
#define _MAP_DEF_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

enum e_bool
{
	ERROR = -1,
	FALSE,
	TRUE
};

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 상
	{1, 0},			// 우
	{0, 1},			// 하
	{-1, 0}			// 좌
};

enum PosStatus { NOT_VISITED = 0, WALL = 1 , VISITED = 2 };

typedef struct MapPositionType
{
	int x;				// x좌표
	int y;				// y좌표
	int direction;		// 가야할 방향
} MapPosition;

typedef struct ArrayStackType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	MapPosition* pElement;
} ArrayStack;

int    findPath(int mazeArray[HEIGHT][WIDTH], \
                MapPosition startPos, MapPosition endPos, \
                ArrayStack *pStack);
int     		pushMapPosition(ArrayStack *pStack, MapPosition data);
MapPosition*	popMapPosition(ArrayStack* pStack);
void    showPath(ArrayStack *pStack);
void    printMaze(int mazeArray[HEIGHT][WIDTH]);

ArrayStack*		createArrayStack(int maxElementCount);
int				pushAS(ArrayStack* pStack, MapPosition element);
MapPosition*	popAS(ArrayStack* pStack);
MapPosition*	peekAS(ArrayStack* pStack);
void			deleteArrayStack(ArrayStack* pStack);
int				isArrayStackFull(ArrayStack* pStack);
int				isArrayStackEmpty(ArrayStack* pStack);

#endif