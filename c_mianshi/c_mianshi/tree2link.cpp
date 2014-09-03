#include "mytree.h"
#include <stdlib.h>
/*
* �������������ת����˫���б�
* ����˫���б��ͷ�ڵ�
*/
BinTreeNode * tree2link(BinTree &T, BinTree &end)
{
	BinTreeNode *start = NULL, *startr = NULL, *endr = NULL, *startl = NULL, *endl = NULL;
	if (T->lchild != NULL)
	{
		startl = tree2link(T->lchild, endl);
	}
	else
	{
		startl = T;
		endl = T;
	}
	if (T->rchild != NULL)
	{
		startr = tree2link(T->rchild, endr);
	}
	else
	{
		startr = T;
		endr = T;
	}

	endl->rchild = T;
	T->lchild = endl;
	endl = T;

	if (startr != endr || endr != T)
	{
		endl->rchild = startr;
		startr->lchild = endl;
	}
	start = startl;
	end = endr;

	start->lchild = NULL;
	end->rchild = NULL;
	return start;
}