#ifndef _GRAPH_LINKEDLIST_
#define _GRAPH_LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct GraphVertexType
{
    int vertexID;       // 노드 ID
    int weight;         // 가중치
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex vertex;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	ListNode headerNode;		// 헤더 노드(Header Node)
} LinkedList;

typedef struct ListGraphType
{
    int maxVertexCount;     // 최대 노드 개수
    int currentVertexCount; // 현재 사용되는 노드의 개수
    int graphType;          // 그래프 종류: 1-Undirected, 2-Directed
    LinkedList *pAdjEdge;	// 간선 저장을 위한 리스트 배열
    int *pVertex;           // 노드 저장을 위한 정수 배열
} ListGraph;


// 그래프 생성
ListGraph* createListGraph(int maxVertexCount);
ListGraph* createListDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteListGraph(ListGraph* pGraph);

// 공백 그래프 여부 판단
int isEmptyLG(ListGraph* pGraph);

// 노드 추가
int addVertexLG(ListGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeLG(ListGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(ListGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검.
int checkVertexValid(ListGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexLG(ListGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeLG(ListGraph* pGraph, int fromVertexID, int toVertexID);

// 그래프 정보 출력
void displayListGraph(ListGraph* pGraph);

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

void displayLinkedList(LinkedList* pList);
void reverseLinkedList(LinkedList* pList);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED                1
#define NOT_USED            0

#define SUCCESS             1
#define FAIL                0

#define TRUE                1
#define FALSE               0
#define ERROR				-1

#define GRAPH_UNDIRECTED    1
#define GRAPH_DIRECTED      2
#endif
