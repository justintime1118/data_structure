#include "arraygraph.h"
#include "arrayqueue.h"

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;
	
	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = calloc(1, sizeof(ArrayGraph));
	if (pGraph == NULL)
		return (NULL);
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
	if (pGraph->ppAdjEdge == NULL)
		return (NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i] = calloc(maxVertexCount, sizeof(int));
		if (pGraph->ppAdjEdge[i] == NULL)
		return (NULL);
	}
	pGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (pGraph->pVertex == NULL)
		return (NULL);
	return (pGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *pGraph;
	
	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = calloc(1, sizeof(ArrayGraph));
	if (pGraph == NULL)
		return (NULL);
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
	if (pGraph->ppAdjEdge == NULL)
		return (NULL);
	for (int i = 0; i < maxVertexCount; i++)
	{
		pGraph->ppAdjEdge[i] = calloc(maxVertexCount, sizeof(int));
		if (pGraph->ppAdjEdge[i] == NULL)
		return (NULL);
	}
	pGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (pGraph->pVertex == NULL)
		return (NULL);
	return (pGraph);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph)
{
	if (pGraph == NULL)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph) // 생각해보니 그냥 currentVertexCount 쓰면 되지 않나?
{
	if (pGraph == NULL)
		return (FAIL);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] != 0)
			return (FALSE);
	}
	return (TRUE);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == NULL ||
		checkVertexValid(pGraph, fromVertexID) == NOT_USED || checkVertexValid(pGraph, toVertexID) == NOT_USED)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = USED;
	return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (pGraph == NULL ||
		checkVertexValid(pGraph, fromVertexID) == NOT_USED || checkVertexValid(pGraph, toVertexID) == NOT_USED)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

// 노드의 유효성 점검.
int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	return (pGraph->pVertex[vertexID]);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	if (checkVertexValid(pGraph, vertexID) == FALSE)
		return (SUCCESS);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		pGraph->ppAdjEdge[vertexID][i] = NOT_USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
	{
		for (int i = 0; i < pGraph->maxVertexCount; i++)
			pGraph->ppAdjEdge[i][vertexID] = NOT_USED;
	}
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED;
	return (SUCCESS);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph)
{
	if (pGraph == NULL)
		return ;
	printf("maxVertexCount = %d\n", pGraph->maxVertexCount);
	printf("currentVertexCount = %d\n", pGraph->currentVertexCount);
	printf("graph type = %s\n", pGraph->graphType == GRAPH_DIRECTED ? "DIRECTED" : "UNDIRECTED");
	printf("Vertex Usage = ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("%d ", pGraph->pVertex[i]);
	printf("\n");
	printf("Graph Matrix\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
			printf("%d", pGraph->ppAdjEdge[i][j]);
		printf("\n");
	}
}

void dfs(ArrayGraph* pGraph, int currentVertexID, int *visited)
{
	if (pGraph == NULL || visited == NULL)
		return ;
	visited[currentVertexID] = 1;
	printf("%d ", currentVertexID);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[currentVertexID][i] == 0 || visited[i] == 1)
			continue ;
		dfs(pGraph, i, visited);
	}
}

void bfs(ArrayGraph* pGraph, int currentVertexID, int *visited, ArrayQueue *pQueue)
{
	ArrayQueueNode element;

	if (pGraph == NULL || visited == NULL || pQueue == NULL)
		return ;
	while (TRUE)
	{
		if (visited[currentVertexID] != 1)
		{
			visited[currentVertexID] = 1;
			printf("%d ", currentVertexID);
		}
		for (int i = 0; i < pGraph->maxVertexCount; i++)
		{
			if (pGraph->ppAdjEdge[currentVertexID][i] == 0 || visited[i] == 1)
				continue ;
			element.data = i;
			enqueueAQ(pQueue, element);
		}
		if (isArrayQueueEmpty(pQueue) == TRUE)
			return ;
		currentVertexID = dequeueAQ(pQueue)->data;
	}
}

int main(void)
{
	// 리턴 밸류에 대한 부분과 vertexID를 그래프 행렬의 인덱스에 대응시킨 것에 대해 민호님과 통일하는 작업
	// 아예 안쓰이는 Vertex와 차수가 0인 vertex 간의 차이가 matrix만 보고서는 알 수 없다는 점이 좀 걸림
	ArrayGraph *pGraph;

	pGraph = createArrayGraph(6);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		addVertexAG(pGraph, i);
	addEdgeAG(pGraph, 1, 0);
	addEdgeAG(pGraph, 2, 0);
	addEdgeAG(pGraph, 2, 1);
	addEdgeAG(pGraph, 3, 2);
	addEdgeAG(pGraph, 4, 3);
	addEdgeAG(pGraph, 5, 3);
	addEdgeAG(pGraph, 5, 4);
	//displayArrayGraph(pGraph);

	int *visited = calloc(pGraph->maxVertexCount, sizeof(int));
	printf("--------------DFS--------------\n");
	dfs(pGraph, 0, visited);
	printf("\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		visited[i] = 0;
	printf("\n--------------BFS--------------\n");
	ArrayQueue *pQueue = createArrayQueue(pGraph->maxVertexCount);
	bfs(pGraph, 0, visited, pQueue);
	printf("\n");
}