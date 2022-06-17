#ifndef _HEAP_
#define _HEAP_

typedef struct HeapNodeType
{
	int x;
	int y;
	int weight;
} HeapNode;

typedef struct HeapType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	HeapNode *pElement;	// 원소 저장을 위한 1차원 배열
} Heap;

Heap* createHeap(int maxElementCount);
void deleteHeap(Heap** pHeap);
void insertMaxHeap(Heap* pHeap, HeapNode node);
void insertMinHeap(Heap* pHeap, HeapNode node);
void deleteMaxHeap(Heap* pHeap);
void deleteMinHeap(Heap* pHeap);
void displayHeap(Heap* pHeap);

#endif

#ifndef _HEAP_DEF_
#define _HEAP_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif
