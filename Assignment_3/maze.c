#include "mapdef.h"

/*
헤더에 의문점 써놓은 것부터 해결하고 시작
ArrayStack에서 노드의 형식을 바꿔주고 그에 맞게 api도 수정

맵 정보를 동적할당해서 저장
길이 64짜리 빈 ArrayStack도 만들어둔다
현재 position을 stack에 push
while (1)
{
	pop을 한다
	사방을 살핀다
	if 출구로 갈 수 있는 경우
		종료. 경로 찾음
	else
	{
		if 이동가능한 방향이 있음 && 거기가 안가본 곳임
			이동 좌표와 방향을 스택에 push
			맵에 visited 표시
		else
			종료. 경로 없음
	}
}
return (ArrayStack)

*/

/*
"S0000000"
"00000000"
"00000000"
"00000000"
"00000000"
"00000000"
"00000000"
"0000000E"
*/
int main(int argc, char **argv)
{
	int	**map;

	if (argc != 9)
		return (1);

	map = malloc(sizeof(int *) * HEIGHT);
	for (int i = 0; i < HEIGHT; i++)
	{
		map[i] = malloc(sizeof(int) * WIDTH);
		for (int j = 0; j < WIDTH; j++)
			map[i][j] = argv[i + 1][j] - '0';
	}
	/*
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
	*/
	
	//maze(map);
}