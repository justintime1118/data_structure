#include "BST.h"
#include "heap.h"

/*
모든 간선을 나타내는 최소 힙(그냥 주어지는 값으로 하자. 왜냐면 이걸 만드는 건 그렇게 어려운 작업이 아님)
정점 정보가 나타나있는 이진탐색트리

우선순위 큐에서 팝해서 나온 간선으로 정점 두개 연결
그 다음꺼 팝해서 나온 간선이 이미 방문한 정점 두개를 잇는 거면 버리고, 그게 아니면 그걸로 정점 연결
모든 정점이 방문될 때까지 반복
*/

int prim(Heap *pq, BinTree *pBinTree, int vertexNumber)
{
	HeapNode tmp;
	int	visited = 1;
	int result = 0;

	
	while (visited != vertexNumber)
	{
		tmp = pq->pElement[0];
		deleteMinHeap(pq);
		// 이진탐색트리 확인해서 간선에 연결된 두 정점이 모두 방문한 정점이면 continue ;
		// else
			// 그 weight를 result에 더해주고 visited++
			// 이진 트리에 해당 간선이 연결하는 두 정점 노드를 찾아가서 visited로 바꿔줌
	}
}

int main(void)
{
	Heap *pq;
	HeapNode node;

	pq = createHeap(7);

	node.x = 0;
	node.y = 1;
	node.weight = 4;
	insertMinHeap(pq, node);

	node.x = 0;
	node.y = 2;
	node.weight = 3;
	insertMinHeap(pq, node);

	node.x = 1;
	node.y = 2;
	node.weight = 2;
	insertMinHeap(pq, node);

	node.x = 2;
	node.y = 3;
	node.weight = 1;
	insertMinHeap(pq, node);

	node.x = 3;
	node.y = 4;
	node.weight = 1;
	insertMinHeap(pq, node);

	node.x = 3;
	node.y = 5;
	node.weight = 5;
	insertMinHeap(pq, node);

	node.x = 4;
	node.y = 5;
	node.weight = 6;
	insertMinHeap(pq, node);

	BinTree *pBinTree;
	BinTreeNode tmp;

	tmp.data = 0;
	tmp.pLeftChild = NULL;
	tmp.pRightChild = NULL;
	tmp.visited = 0;
	pBinTree = makeBinTree(tmp);

	for (int i = 1; i < 6; i++)
	{
		tmp.data = i;
		insertNodeBST(pBinTree->pRootNode, tmp);
	}

	int result;

	result = prim(pq, pBinTree, 6);
	printf("result: %d\n", result);
}