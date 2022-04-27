#ifndef _MAP_DEF_
#define _MAP_DEF_

#include <stdlib.h>
#include <stdio.h>
#include "arraystack.h"

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// 정적 전역 변수로 선언된 정수 배열-> 이거 어케 써야함...? 그리고 이게 더 헷갈리는데 그냥 1, 2, 3, 4를 상하좌우로 하면 안되나?
// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0, -1},		// 상 -> 좌
	{1, 0},			// 우 -> 하
	{0, 1},			// 하 -> 우
	{-1, 0}			// 좌 -> 상
}; // 화살표 표시한대로 바꾸는게 더 이중배열 상 위치로 직관적이지 않나?

// enum은 정수 상수를 편하게 정의하는 것이라고 생각하면 됨
enum PosStatus { NOT_VISITED = 0, WALL = 1 , VISITED = 2 };

typedef struct MapPositionType
{
	int x;				// x좌표
	int y;				// y좌표
	int direction;		// 가야할 방향. DIRECTION_OFFSETS[NUM_DIRECTIONS]에서 들어갈 인덱스 번호라고 생각하면 됨
} MapPosition;

#endif