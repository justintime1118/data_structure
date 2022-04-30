#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque *pDeque;

	pDeque = malloc(sizeof(LinkedDeque));
	pDeque->currentElementCount = 0;
	pDeque->pFrontNode = NULL;
	pDeque->pRearNode = NULL;
	return (pDeque);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	// front 만들어서 pFrontNode = 새로 만든 노드
	// current++
	// current == 1인 경우
		// pRearNode = pFrontNode
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	// rear 만들어서 pRearNode = 새로 만든 노드
	// current++
	// current == 1인 경우
		// pFrontNode = pRearNode
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	// 비어있는 경우
		// NULL을 리턴
	
	// tmp에 front 노드 저장. pFrontNode = pFrontNode->pRLink, free(tmp)
	// current--;
	// current 갯수가 0이다?
		// pRearNode = pFrontNode

}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	// 비어있는 경우
		// NULL을 리턴

	// tmp에 rear 노드 저장. pRearNode = pRearNode->pRLink, free(tmp) 
	// current--;
	// current 갯수가 0이다?
		// pFrontNode = pRearNode
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{

}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{

}

void deleteLinkedDeque(LinkedDeque* pDeque)
{

}

int isLinkedDequeFull(LinkedDeque* pDeque); // Linked로 구현하면 꽉 찰 수가 없지 않나?

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	return (pDeque->currentElementCount == 0 ? TRUE : FALSE);
}
