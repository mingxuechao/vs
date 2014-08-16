#include "mytree.h"
#include <stdio.h>
#include <stdlib.h>

int BBT_Init(BinTree &T, int data)
{
	if ((T = (BinTree)malloc(sizeof(BinTreeNode))) == NULL){ return -1; };
	*T = { 0, data, NULL, NULL };
	return 0;
}


int BBT_Del(BinTree &T)
{
	if (T->lchild != NULL)
	{
		BBT_Del(T->lchild);
	}
	if (T->rchild != NULL)
	{
		BBT_Del(T->rchild);
	}
	free(T);
	return 0;
}

int BBT_Insert(BinTree &T, int data)
{
	BinTreeNode *tmp;
	BinTreeNode *path[MAXHIGH];
	path[0] = T;
	BinTreeNode *father = T;
	int pathlen;
	int tmpbf;
	BinTreeNode *datatmp = (BinTreeNode *)malloc(sizeof(BinTreeNode));

	*datatmp = { 0, data, NULL, NULL };
	tmp = T;
	pathlen = 0;

	while (1)
	{
		if (tmp->data > data)
		{
			if (tmp->lchild != NULL)
			{
				pathlen++;
				path[pathlen] = tmp;
				tmp = tmp->lchild;
			}
			else
			{
				pathlen++;
				path[pathlen] = tmp;
				tmp->lchild = datatmp;
				break;
			}
		}
		else
		{
			if (tmp->rchild != NULL)
			{
				pathlen++;
				path[pathlen] = tmp;
				tmp = tmp->rchild;
			}
			else
			{
				pathlen++;
				path[pathlen] = tmp;
				tmp->rchild = datatmp;
				break;
			}
		}
	}
	while (pathlen > 0)
	{
		tmpbf = hightree(path[pathlen]->lchild);
		tmpbf = tmpbf - hightree(path[pathlen]->rchild);
		path[pathlen]->bf = tmpbf;
		father = path[pathlen - 1];
		if (tmpbf > 1 || tmpbf < -1)
		{
			if (father->lchild == path[pathlen])
			{
				father->lchild = change(path[pathlen]);
				break;
			}
			if (father->rchild == path[pathlen])
			{
				father->rchild = change(path[pathlen]);
				break;
			}
			if (T == path[pathlen])
			{
				T = change(path[pathlen]); break;
			}

		}
		pathlen--;
	}
	return 0;
}



BinTree change(BinTree T)
{
	BinTreeNode *nodeA = NULL;
	BinTreeNode *nodeB = NULL;
	BinTreeNode *nodeC = NULL;
	BinTreeNode *tmp1 = NULL;
	BinTreeNode *tmp2 = NULL;
	if (T->bf == 2)
	{
		if (T->lchild != NULL)
		{
			if (T->lchild->bf == -1)
			{
				//goto LR;
				nodeA = T;
				nodeB = nodeA->lchild;
				nodeC = nodeB->rchild;
				tmp1 = nodeC->lchild;
				tmp2 = nodeC->rchild;

				T = nodeC;
				nodeC->lchild = nodeB;
				nodeC->rchild = nodeA;
				nodeB->rchild = tmp1;
				nodeA->lchild = tmp2;
				nodeA->bf = -1;
				nodeB->bf = 0;
				nodeC->bf = 0;
			}
			else
			{
				//goto LL;
				nodeA = T;
				nodeB = nodeA->lchild;
				tmp1 = nodeB->rchild;

				T = nodeB;
				nodeA->lchild = nodeB->rchild;
				nodeB->rchild = nodeA;
				nodeA->bf = 0;
				nodeB->bf = 0;
			}
		}
	}
	else
	{
		if (T->rchild != NULL)
		{
			if (T->rchild->bf == -1)
			{
				//goto RR;
				nodeA = T;
				nodeB = T->rchild;
				tmp1 = nodeB->lchild;

				T = nodeB;
				nodeB->lchild = nodeA;
				nodeA->rchild = tmp1;
				nodeA->bf = 0;
				nodeB->bf = 0;
			}
			else
			{
				//goto RL;
				nodeA = T;
				nodeB = nodeA->rchild;
				nodeC = nodeB->lchild;
				tmp1 = nodeC->lchild;
				tmp2 = nodeC->rchild;

				T = nodeC;
				nodeC->lchild = nodeA;
				nodeC->rchild = nodeB;
				nodeA->rchild = tmp1;
				nodeB->lchild = tmp2;
				nodeA->bf = 0;
				nodeB->bf = -1;
				nodeC->bf = 0;
			}
		}
	}
	return T;
}

int hightree(BinTree &T)
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
		printf("%d:%d::%d\t", T->data,T->bf,hightree(T->lchild) -hightree(T->rchild));
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
void pernode(BinTree T, int(*visit)(int data))
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

//旋转造成的结果是不增加自身的高度，更不会减少
//旋转不改变原来的高度，因此对上一级没有影响
/*
LL:
T = nodeA->lchild;
nodeB = nodeA->lchild;
nodeA->lchild = nodeB->rchild;
nodeB->rchild = nodeA;
nodeA->bf = 0;
nodeB->bf = 0;
LR:
nodeA = T;
nodeB = nodeA->lchild;
nodeC = nodeB->rchild;
tmp1 = nodeC->lchild;
tmp2 = nodeC->rchild;

T = nodeC;
nodeC->lchild = nodeB;
nodeC->rchild = nodeA;
nodeB->rchild = tmp1;
nodeA->lchild = tmp2;
nodeA->bf = -1;
nodeB->bf = 0;
nodeC->bf = 0;
RR:
nodeA = T;
nodeB = T->rchild;
tmp1 = nodeB->lchild;

T = nodeB;
nodeB->lchild = nodeA;
nodeA->lchild = nodeB;
nodeA->bf = 0;
nodeB->bf = 0;
RL:
nodeA = T;
nodeB = nodeA->rchild;
nodeC = nodeA->lchild;
tmp1 = nodeC->lchild;
tmp2 = nodeC->rchild;

T = nodeC;
nodeC->lchild = nodeA;
nodeC->rchild = nodeB;
nodeA->rchild = tmp1;
nodeB->lchild = tmp2;
nodeA->bf = 0;
nodeB->bf = -1;
nodeC->bf = 0;
*/