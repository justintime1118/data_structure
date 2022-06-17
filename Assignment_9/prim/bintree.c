#include "BST.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *pBinTree;

	pBinTree = (BinTree *)malloc(sizeof(BinTree));
	if (pBinTree == NULL)
		return (NULL);
	pBinTree->pRootNode = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (pBinTree->pRootNode == NULL)
		return (NULL);
	pBinTree->pRootNode->data = rootNode.data;
	return (pBinTree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (pBinTree == NULL || pBinTree->pRootNode == NULL)
		return (NULL);
	return (pBinTree->pRootNode);
}

// 삽입될 자리는 항상 비어있다고 가정
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL)
		return (NULL);
	pParentNode->pLeftChild = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (pParentNode->pLeftChild == NULL)
		return (NULL);
	pParentNode->pLeftChild->data = element.data;
	return (pParentNode->pLeftChild);
}

// 삽입될 자리는 항상 비어있다고 가정
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (pParentNode == NULL)
		return (NULL);
	pParentNode->pRightChild = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
	if (pParentNode->pRightChild == NULL)
		return (NULL);
	pParentNode->pRightChild->data = element.data;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	deleteTraverse(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteTraverse(BinTreeNode* pParentNode)
{
	if (pParentNode == NULL)
		return ;
	deleteTraverse(pParentNode->pLeftChild);
	deleteTraverse(pParentNode->pRightChild);
	deleteBinTreeNode(pParentNode);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return ;
	free(pNode);
	pNode->data = 0;
	pNode->visited = FALSE;
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
}

void traversePreorder(BinTreeNode* pParentNode)
{
	if (pParentNode == NULL)
		return ;
	printf("%d ", pParentNode->data);
	traversePreorder(pParentNode->pLeftChild);
	traversePreorder(pParentNode->pRightChild);
}

void traverseInorder(BinTreeNode* pParentNode)
{
	if (pParentNode == NULL)
		return ;
	traverseInorder(pParentNode->pLeftChild);
	printf("%d ", pParentNode->data);
	traverseInorder(pParentNode->pRightChild);
}

void traversePostorder(BinTreeNode* pParentNode)
{
	if (pParentNode == NULL)
		return ;
	traversePostorder(pParentNode->pLeftChild);
	traversePostorder(pParentNode->pRightChild);
	printf("%d ", pParentNode->data);
}
