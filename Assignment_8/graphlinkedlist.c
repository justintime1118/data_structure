#include "graphlinkedlist.h"
#include "arrayqueue.h"

// 그래프 생성
ListGraph* createListGraph(int maxVertexCount)
{
	ListGraph *pGraph;
	
	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = calloc(1, sizeof(ListGraph));
	if (pGraph == NULL)
		return (NULL);
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_UNDIRECTED;
	pGraph->pAdjEdge = calloc(maxVertexCount, sizeof(LinkedList));
	if (pGraph->pAdjEdge == NULL)
		return (NULL);
	pGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (pGraph->pVertex == NULL)
		return (NULL);
	return (pGraph);
}
ListGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ListGraph *pGraph;
	
	if (maxVertexCount <= 0)
		return (NULL);
	pGraph = calloc(1, sizeof(ListGraph));
	if (pGraph == NULL)
		return (NULL);
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->currentVertexCount = 0;
	pGraph->graphType = GRAPH_DIRECTED;
	pGraph->pAdjEdge = calloc(maxVertexCount, sizeof(LinkedList));
	if (pGraph->pAdjEdge == NULL)
		return (NULL);
	pGraph->pVertex = calloc(maxVertexCount, sizeof(int));
	if (pGraph->pVertex == NULL)
		return (NULL);
	return (pGraph);
}

// 그래프 삭제
void deleteListGraph(ListGraph* pGraph)
{
	if (pGraph == NULL)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		deleteLinkedList(&(pGraph->pAdjEdge[i]));
	free(pGraph->pAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyLG(ListGraph* pGraph) // 생각해보니 그냥 currentVertexCount 쓰면 되지 않나?
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
int addVertexLG(ListGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int addEdgeLG(ListGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (pGraph == NULL ||
		checkVertexValid(pGraph, fromVertexID) == NOT_USED ||
		checkVertexValid(pGraph, toVertexID) == NOT_USED)
		return (FAIL);
	
	for (int i = 0; i < pGraph->pAdjEdge[fromVertexID].currentElementCount; i++)
	{
		if (getLLElement(&(pGraph->pAdjEdge[fromVertexID]), i)->vertex.vertexID == toVertexID)
			return(SUCCESS);
	}
	ListNode element;
	element.vertex.vertexID = toVertexID;
	element.vertex.weight = 1;
	addLLElement(&(pGraph->pAdjEdge[fromVertexID]),
		pGraph->pAdjEdge[fromVertexID].currentElementCount, element);
	
	if (pGraph->graphType == GRAPH_DIRECTED)
		return (SUCCESS);
	
	for (int i = 0; i < pGraph->pAdjEdge[toVertexID].currentElementCount; i++)
	{
		if (getLLElement(&(pGraph->pAdjEdge[toVertexID]), i)->vertex.vertexID == toVertexID)
			return(SUCCESS);
	}
	element.vertex.vertexID = fromVertexID;
	element.vertex.weight = 1;
	addLLElement(&(pGraph->pAdjEdge[toVertexID]),
		pGraph->pAdjEdge[toVertexID].currentElementCount, element);
	return (SUCCESS);
}
int addEdgewithWeightLG(ListGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (pGraph == NULL ||
		checkVertexValid(pGraph, fromVertexID) == NOT_USED ||
		checkVertexValid(pGraph, toVertexID) == NOT_USED)
		return (FAIL);

	for (int i = 0; i < pGraph->pAdjEdge[fromVertexID].currentElementCount; i++)
	{
		if (getLLElement(&(pGraph->pAdjEdge[fromVertexID]), i)->vertex.vertexID == toVertexID)
			return(SUCCESS);
	}
	ListNode element;
	element.vertex.vertexID = toVertexID;
	element.vertex.weight = weight;
	addLLElement(&(pGraph->pAdjEdge[fromVertexID]),
		pGraph->pAdjEdge[fromVertexID].currentElementCount, element);

	if (pGraph->graphType == GRAPH_DIRECTED)
		return (SUCCESS);
	
	for (int i = 0; i < pGraph->pAdjEdge[toVertexID].currentElementCount; i++)
	{
		if (getLLElement(&(pGraph->pAdjEdge[toVertexID]), i)->vertex.vertexID == toVertexID)
			return(SUCCESS);
	}
	element.vertex.vertexID = fromVertexID;
	element.vertex.weight = weight;
	addLLElement(&(pGraph->pAdjEdge[toVertexID]),
		pGraph->pAdjEdge[toVertexID].currentElementCount, element);
	return (SUCCESS);
}

// 노드의 유효성 점검.
int checkVertexValid(ListGraph* pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	return (pGraph->pVertex[vertexID]);
}

// 노드 제거
int removeVertexLG(ListGraph* pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE)
		return (FALSE);
	pGraph->pVertex[vertexID] = NOT_USED;
	pGraph->currentVertexCount--;
	clearLinkedList(&(pGraph->pAdjEdge[vertexID]));
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (i == vertexID)
			continue ;
		for (int j = 0; j < pGraph->pAdjEdge[i].currentElementCount; j++)
		{
			if (getLLElement(&(pGraph->pAdjEdge[i]), j)->vertex.vertexID == vertexID)
				removeLLElement(&(pGraph->pAdjEdge[i]), j);
		}
	}
	return (SUCCESS);
}

// 간선 제거
int removeEdgeLG(ListGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE || checkVertexValid(pGraph, toVertexID) == FALSE)
		return (FALSE);
	for (int i = 0; i < pGraph->pAdjEdge[fromVertexID].currentElementCount; i++)
	{
		if (getLLElement(&(pGraph->pAdjEdge[fromVertexID]), i)->vertex.vertexID == toVertexID)
			removeLLElement(&(pGraph->pAdjEdge[fromVertexID]), i);
	}

	if (pGraph->graphType == GRAPH_DIRECTED)
		return (SUCCESS);
	
	for (int i = 0; i < pGraph->pAdjEdge[toVertexID].currentElementCount; i++)
	{
		if (getLLElement(&(pGraph->pAdjEdge[toVertexID]), i)->vertex.vertexID == fromVertexID)
			removeLLElement(&(pGraph->pAdjEdge[toVertexID]), i);
	}
	return (SUCCESS);
}

// 그래프 정보 출력
void displayListGraph(ListGraph* pGraph)
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
	printf("-----------Graph List-----------\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("%d) : ", i);
		for (int j = 0; j < pGraph->pAdjEdge[i].currentElementCount; j++)
			printf("%d ", getLLElement(&(pGraph->pAdjEdge[i]), j)->vertex.vertexID);
		printf("\n");
	}
}


void dfs(ListGraph* pGraph, int currentVertexID, int *visited)
{
	if (pGraph == NULL || visited == NULL)
		return ;
	visited[currentVertexID] = 1;
	printf("%d ", currentVertexID);
	for (int i = 0; i < pGraph->pAdjEdge[currentVertexID].currentElementCount; i++)
	{
		// 연결된 점을 쭉 순회하면서 방문한 적이 없으면 dfs!
		if (visited[getLLElement(&(pGraph->pAdjEdge[currentVertexID]), i)->vertex.vertexID] == 0)
			dfs(pGraph, getLLElement(&(pGraph->pAdjEdge[currentVertexID]), i)->vertex.vertexID, visited);
	}
}

void bfs(ListGraph* pGraph, int currentVertexID, int *visited, ArrayQueue *pQueue)
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
		for (int i = 0; i < pGraph->pAdjEdge[currentVertexID].currentElementCount; i++)
		{
			if (visited[getLLElement(&(pGraph->pAdjEdge[currentVertexID]), i)->vertex.vertexID] == 1)
				continue ;
			element.data = getLLElement(&(pGraph->pAdjEdge[currentVertexID]), i)->vertex.vertexID;
			enqueueAQ(pQueue, element);
		}
		if (isArrayQueueEmpty(pQueue) == TRUE)
			return ;
		currentVertexID = dequeueAQ(pQueue)->data;
	}
}

int main(void)
{
	ListGraph *pGraph;

	pGraph = createListGraph(6);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		addVertexLG(pGraph, i);
	addEdgeLG(pGraph, 1, 0);
	addEdgeLG(pGraph, 2, 0);
	addEdgeLG(pGraph, 2, 1);
	addEdgeLG(pGraph, 3, 2);
	addEdgeLG(pGraph, 4, 3);
	addEdgeLG(pGraph, 5, 3);
	addEdgeLG(pGraph, 5, 4);

	// displayListGraph(pGraph);
	// removeVertexLG(pGraph, 4);
	// removeEdgeLG(pGraph, 0, 1);

	// displayListGraph(pGraph);

	int *visited = calloc(pGraph->maxVertexCount, sizeof(int));
	printf("--------------DFS--------------\n");
	dfs(pGraph, 0, visited);
	printf("\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		visited[i] = 0;
	printf("\n--------------BFS--------------\n");
	ArrayQueue *pQueue = createArrayQueue(pGraph->maxVertexCount);
	bfs(pGraph, 0, visited, pQueue);
}
