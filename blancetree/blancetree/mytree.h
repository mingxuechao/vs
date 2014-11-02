#ifndef _MyBintree
#define _MyBintree
#include "mytree.h"
#define MAXHIGH	  10  
typedef struct BinTreeNode
{
	int bf;
	int data;
	struct BinTreeNode *lchild, *rchild;
}*BinTree,BinTreeNode;

int BBT_Init(BinTree &T, int data);
int BBT_Insert(BinTree &T, int data);
int BBT_Del(BinTree &T);
BinTree change(BinTree T);
int hightree(BinTree &T);
void pernode(BinTree T);
void midnode(BinTree T);
void lastnode(BinTree T);
void pernode(BinTree T,int (* visit)(int e));
int myvisit(int data);

#endif