#include "mapdef.h"

int     pushMapPosition(ArrayStack *pStack, MapPosition data)
{
	return (pushAS(pStack, data));
}

MapPosition*	popMapPosition(ArrayStack* pStack)
{
	return (popAS(pStack));
}

void    printMaze(int mazeArray[HEIGHT][WIDTH])
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			printf("%d ", mazeArray[i][j]);
		printf("\n");
	}
}

void    showPath(ArrayStack *pStack)
{
	printf("#\t[x, y]\n\n");
	for (int i = 0; i < pStack->currentElementCount; i++)
		printf("%d\t[%d, %d]\n", \
			i, pStack->pElement[i].x, pStack->pElement[i].y);
}

int    findPath(int mazeArray[HEIGHT][WIDTH], \
                MapPosition startPos, MapPosition endPos, \
                ArrayStack *pStack)
{
	MapPosition	currPos;
	MapPosition	*topPos;
	int			topFlag;
	int			topDirection;
	int			xTmp;
	int			yTmp;
	int			i;

	topFlag = FALSE;
	currPos = startPos;
	while (TRUE)
	{
		mazeArray[currPos.y][currPos.x] = VISITED; // 현 위치 방문으로 표시
		if (currPos.x == endPos.x && currPos.y == endPos.y) // 출구에 도달했는지 확인
			return (printf("RESULT: Path Found!\n"));
		i = ((topFlag == TRUE) ? topDirection : -1); // top을 받아왔으면 top direction, 아니면 다시 0부터 순회하도록 방향 설정
		topFlag = FALSE;
		// 이동가능한 방향을 둘러보는 루프
		while (++i < NUM_DIRECTIONS)
		{
			xTmp = currPos.x + DIRECTION_OFFSETS[i][0];
			yTmp = currPos.y + DIRECTION_OFFSETS[i][1];
			if (xTmp < 0 || 7 < xTmp || yTmp < 0 || 7 < yTmp)
				continue ;
			if (mazeArray[yTmp][xTmp] == WALL \
				|| mazeArray[yTmp][xTmp] == VISITED)
				continue ;
			currPos.direction = i;
			pushMapPosition(pStack, currPos);
			currPos.x = xTmp;
			currPos.y = yTmp;
			break ;
		}
		if (i == NUM_DIRECTIONS) // 여기에 걸리면 이동가능한 방향이 없다는 것. pop을 시도한다.
		{
			topPos = popMapPosition(pStack);
			if (topPos == NULL)
				return (printf("RESULT: No path..TT\n"));
			topFlag = TRUE;
			currPos.x = topPos->x;
			currPos.y = topPos->y;
			topDirection = topPos->direction;
			free(topPos);
		}
	}
}

int main(int argc, char **argv)
{
	int mazeArray[HEIGHT][WIDTH] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};
	ArrayStack	*pStack;
	MapPosition	startPos;
	MapPosition	endPos;
	
	startPos.x = 0;
	startPos.y = 0;
	startPos.direction = 0;
	endPos.x = 7;
	endPos.y = 7;
	endPos.direction = 0;

	pStack = createArrayStack(64);
	printf("[map_before]\n");
	printMaze(mazeArray);
	printf("---------------\n");
	printf("\n");
	findPath(mazeArray, startPos, endPos, pStack);
	printf("\n");
	showPath(pStack);
	printf("\n");
	printf("[map_after]\n");
	printMaze(mazeArray);
	printf("---------------\n");
	deleteArrayStack(pStack);
	return (0);
}