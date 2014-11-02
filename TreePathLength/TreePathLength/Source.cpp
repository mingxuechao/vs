#include "mytree.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x) >= (y) ? (x) : (y))
#define MIN(x,y) ((x) >= (y) ? (y) : (x))
int atree[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 18, 17, 16, 15, 14, 13, 12, 12 ,19};
/*
* 将排序二叉树，转换成双向列表。
* 返回双向列表的头节点
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
#define MAX(x,y) ((x) >= (y) ? (x) : (y))
#define MIN(x,y) ((x) >= (y) ? (y) : (x))
int function(BinTree T, int &max, int &min)
{

	if (T != NULL)
	{
		int maxl, maxr, minl, minr;
		function(T->lchild, maxl, minl);
		function(T->rchild, maxr, minr);
		min = MIN(MIN(minl, minr), T->data);
		max = MAX(MAX(maxr, maxl), T->data);
	}
	else
	{
		min = INT_MAX;
		max = INT_MIN;
	}
	return max - min;
}
int function1(BinTree t, int &max, int &min)
{
	if (t != NULL)
	{
		int maxl, minl, maxr, minr;
		function1(t->lchild, maxl, minl);
		function1(t->rchild, maxr, minr);
		if (t->data >= maxl && t->data >= maxr)
		{
			max = t->data;
		}
		else if (maxr > maxl)
		{
			max = maxr;
		}
		else
		{
			max = maxl;
		}
		if (t->data <= minl && t->data <= minr)
		{
			min = t->data;
		}
		else if (minr < minl)
		{
			min = minr;
		}
		else
		{
			min = minl;
		}
	}
	else
	{
		max = INT_MIN;
		min = INT_MAX;
	}

	return max - min;
}
int main()
{
	BinTree T;
	int max, min, res,res1,min1,max1;
	Bintreeinit(T, *atree);
	BinTreeNode link;
	link.data = 10;
	link.lchild = NULL;
	link.rchild = NULL;
	for (size_t i = 1; i < sizeof(atree) / sizeof(int); i++)
	{
		sorttree_insert(T, atree[i]);
	}
	res = function(&link, max, min);
	res1 = function1(T, max1, min1);

	/*BinTree end = NULL;*/
	//link = tree2link(T, end);
	//printf("link1:");
	//printf("%d\t", link->data);

	//do
	//{
	//	//printf("%d\t", link->data);
	//	link = link->rchild;
	//	printf("%d\t", link->data);
	//} while (link->rchild != NULL);
	//printf("\n");
	//printf("link1:");
	//while (link != NULL)
	//{
	//	printf("%d\t", link->data);
	//	link = link->lchild;
	//}
	/*
	printf("\n\n\n");
	midnode(T);
	printf("\n\n\n");
	printf("%d\n\n\n", hightree(T));
	delbintree(T);
	*/
	return 0;
}