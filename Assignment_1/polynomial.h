#ifndef _POLYLINKEDLIST_
#define _POLYLINKEDLIST_

typedef struct PolyNodeType  // 단항식
{
	int coef; //계수 cofficient
	int degree; //지수 exponent = degree
	struct PolyNodeType* pLink;
} PolyListNode;

typedef struct PolyListType // 다항식 polynomial
{
	int currentElementCount;	// 현재 저장된 원소의 개수
	PolyListNode headerNode;		// 헤더 노드(Header Node)
} PolyList;

PolyList* createPolyList();
int addPLElement(PolyList* pList, PolyListNode element);
PolyListNode* getPLElement(PolyList* pList, int position);
void displayPolyList(PolyList* pList);
PolyList* addPolyLists(PolyList* pList1, PolyList* pList2);
void deletePolyList(PolyList** pList);
#endif
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif