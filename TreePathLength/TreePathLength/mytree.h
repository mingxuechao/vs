#ifndef _MyBintree
#define _MyBintree
#include "mytree.h"
typedef struct BinTreeNode
{
	int data;
	struct BinTreeNode *lchild, *rchild;
}*BinTree,BinTreeNode;

int initbintree(BinTree &T, int *data, int length, int lennow =0);
int delbintree(BinTree &T);
int hightree(BinTree T);
void pernode(BinTree T);
void midnode(BinTree T);
void lastnode(BinTree T);
void pernode(BinTree T,int (* visit)(int e));
int myvisit(int data);
#endif