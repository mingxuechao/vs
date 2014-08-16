#include "mytree.h"
#include <stdio.h>
int atree[] = { 16, 10, 9, 8, 7, 6, 5, 4, 3, 14, 13, 12, 11, 2, 1 ,3, 14, 13 };
int main()
{
	BinTree T;
	BBT_Init(T, *atree);
	for (size_t i = 1; i < sizeof(atree)/sizeof(int); i++)
	{
		BBT_Insert(T, atree[i]);
	}
	midnode(T);
	printf("\nthe depth is :%d\n\n\n",hightree(T));
	BBT_Del(T);
	return 0;
}