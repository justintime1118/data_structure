#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct BinTreeNodeType
{
	char data;
	int visited;

	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTreeNode* insertNodeBST(BinTreeNode* pRootNode, BinTreeNode element);
void deleteNodeBST(BinTreeNode* pRootNode, BinTreeNode element);
BinTreeNode* searchNodeBST(BinTreeNode* pRootNode, BinTreeNode element);
BinTreeNode* searchParentNodeBST(BinTreeNode* pRootNode, BinTreeNode element);

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteTraverse(BinTreeNode* pParentNode);
void deleteBinTreeNode(BinTreeNode* pNode);
void traversePreorder(BinTreeNode* pParentNode);
void traverseInorder(BinTreeNode* pParentNode);
void traversePostorder(BinTreeNode* pParentNode);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif