#include "BST.h"

BinTreeNode* insertNodeBST(BinTreeNode* pRootNode, BinTreeNode element)
{
	BinTreeNode *pParentNode;
	BinTreeNode *pCurrentNode = pRootNode;
	BinTreeNode *pNewNode;

	if (pRootNode == NULL)
		return (NULL);
	while (pCurrentNode != NULL)
	{
		pParentNode = pCurrentNode;
		if (pCurrentNode->data < element.data)
			pCurrentNode = pCurrentNode->pRightChild;
		else if (pCurrentNode->data > element.data)
			pCurrentNode = pCurrentNode->pLeftChild;
		else
			return (NULL);
	}
	pNewNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	pNewNode->data = element.data;
	if (pParentNode->data < element.data)
			pParentNode->pRightChild = pNewNode;
	else
		pParentNode->pLeftChild = pNewNode;
	return (pNewNode);
}

void deleteNodeBST(BinTreeNode* pRootNode, BinTreeNode element)
{
	BinTreeNode *target;
	BinTreeNode *parent;
	BinTreeNode *tmp;

	target = searchNodeBST(pRootNode, element);
	if (target == NULL)
		return ;
	parent = searchParentNodeBST(pRootNode, element);
	if (target->pLeftChild == NULL && target->pRightChild == NULL)
	{
		if (parent->pLeftChild == target)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
		free(target);
	}
	// 왼쪽 서브트리로 내려가서 쭉 오른쪽으로 타고 내려가서 더 이상 오른쪽이 NULL이 나오는 애의 값을 target에 넣어주고
	// 그 오른쪽 끝에 있던 애의 부모 찾아서 링크 끊어주고, 오른쪽 끝에 애는 free 해준다
	else if (target->pLeftChild != NULL && target->pRightChild == NULL)
	{
		tmp = target->pLeftChild;
		while (tmp->pRightChild != NULL)
			tmp = tmp->pRightChild;
		element.data = tmp->data;
		deleteNodeBST(pRootNode, element);
		target->data = element.data;
	}
	// 오른쪽 서브트리로 내려가서 쭉 왼쪽으로 타고 내려가서 더 이상 왼쪽이 NULL이 나오는 애의 값을 target에 넣어주고
	// 그 왼쪽 끝에 있던 애의 부모 찾아서 링크 끊어주고, 왼쪽 끝에 애는 free 해준다
	else
	{
		tmp = target->pRightChild;
		while (tmp->pLeftChild != NULL)
			tmp = tmp->pLeftChild;
		element.data = tmp->data;
		deleteNodeBST(pRootNode, element);
		target->data = element.data;
	}
}

BinTreeNode* searchNodeBST(BinTreeNode* pRootNode, BinTreeNode element)
{
	BinTreeNode *ret = pRootNode;

	while (ret != NULL)
	{
		if (ret->data == element.data)
			return (ret);
		else if (ret->data < element.data)
			ret = ret->pRightChild;
		else
			ret = ret->pLeftChild;
	}
	return (ret);
}

BinTreeNode* searchParentNodeBST(BinTreeNode* pRootNode, BinTreeNode element)
{
	BinTreeNode *ret = pRootNode;

	while (ret != NULL)
	{
		if ((ret->pLeftChild != NULL && ret->pLeftChild->data == element.data)
			|| (ret->pRightChild != NULL && ret->pRightChild->data == element.data))
			return (ret);
		else if (ret->data < element.data)
			ret = ret->pRightChild;
		else
			ret = ret->pLeftChild;
	}
	return (ret);
}

int main(void)
{
	BinTree *pBinTree;
	BinTreeNode node;
	BinTreeNode *tmp;

	node.data = 3;
	pBinTree = makeBinTree(node);
	for (int i = 1; i <= 5; i++)
	{	
		node.data = i;
		insertNodeBST(pBinTree->pRootNode, node);
	}
	printf("rootNode->data == %d\n", pBinTree->pRootNode->data);
	traverseInorder(pBinTree->pRootNode);
	printf("\n");
	node.data = pBinTree->pRootNode->data;
	deleteNodeBST(pBinTree->pRootNode, node);
	printf("rootNode->data == %d\n", pBinTree->pRootNode->data);
	traverseInorder(pBinTree->pRootNode);
	printf("\n");
	//node.data++;
	//tmp = searchNodeBST(pBinTree->pRootNode, node);
	//printf("tmp == %p\ntmp.data == %d\n", tmp, tmp->data);
}