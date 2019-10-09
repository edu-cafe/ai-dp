#include <stdio.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{
	BTreeNode * pNode = NULL;    // parent node
	BTreeNode * cNode = *pRoot;    // current node
	BTreeNode * nNode = NULL;    // new node

	// 새로운 노드가 추가될 위치를 찾는다.
	while(cNode != NULL)
	{
		if(data == GetData(cNode))
			return;    // 키의 중복을 허용하지 않음

		pNode = cNode;

		if(GetData(cNode) > data)
			cNode = ...........
		else
			cNode = ...........
	}

	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = ........    // 새 노드의 생성
	SetData(nNode, data);    // 새 노드에 데이터 저장

	// pNode의 서브 노드에 새 노드를 추가
	if(pNode != NULL)    // 새 노드가 루트 노드가 아니라면,
	{
		if(data < GetData(pNode))
			..........
		else
			..........
	}
	else    // 새 노드가 루트 노드라면,
	{
		*pRoot = .......
	}
}

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode * cNode = bst;    // current node
	BSTData cd;    // current data

	while(cNode != NULL)
	{
		cd = GetData(cNode);

		if(target == cd)
			return ......
		else if(target < cd)
			cNode = ..........
		else
			cNode = ..........
	}

	return NULL;
}
