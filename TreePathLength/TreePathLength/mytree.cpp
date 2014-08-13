#include "mytree.h"
#include <stdio.h>
#include <stdlib.h>
#define _NULLFLG -1
//将用满二叉的数组表示形式的二叉树转换为链式表示，当值为 _NULLFLG 表示这个这个为空树。
int initbintree(BinTree &T, int *data, int len, int lennow)
{
	int lchild = 2 * lennow + 1;
	int rchild = 2 * lennow + 2;
	if (lennow < len && *(data + lennow) != _NULLFLG)
	{
		if ((T = (BinTreeNode *)malloc(sizeof(BinTreeNode))) == NULL){ return -1; }
		T->data = *(data + lennow);
		initbintree(T->lchild, data, len, lchild);
		initbintree(T->rchild, data, len, rchild);
	}
	else
	{
		T = NULL;
	}
	return 0;
}
//删除二叉树
int delbintree(BinTree &T)
{
	if (T->lchild != NULL)
	{
		free(T->lchild);
	}
	if (T->rchild != NULL)
	{
		free(T->rchild);
	}
	free(T);
	return 0;
}
int hightree(BinTree T)
{
	if (T == NULL)
	{
		return 0;
	}
	else
	{
		int left = hightree(T->lchild);
		int right = hightree(T->rchild);
		if (left > right)
		{
			return  left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}
void pernode(BinTree T)
{
	if (T != NULL)
	{
		printf("%d\t", T->data);
		pernode(T->lchild);
		pernode(T->rchild);
	}
}
void midnode(BinTree T)
{
	if (T != NULL)
	{
		midnode(T->lchild);
		printf("%d\t", T->data);
		midnode(T->rchild);
	}
}
void lastnode(BinTree T)
{
	if (T != NULL)
	{
		lastnode(T->lchild);
		lastnode(T->rchild);
		printf("%d\t", T->data);
	}
}
void pernode(BinTree T, int (* visit)(int data))
{
	if (T != NULL)
	{
		visit(T->data);
		pernode(T->lchild, visit);
		pernode(T->rchild, visit);
	}
}
int myvisit(int data)
{
	printf("%d\t", (data + 1));
	return 0;
}