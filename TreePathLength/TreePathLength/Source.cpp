#include "mytree.h"
#include <stdio.h>
int atree[] = { 1, 2, 3, 4, -1, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
int main()
{
	BinTree T;
	initbintree(T, atree, sizeof(atree) / sizeof(int));
	pernode(T);

	printf("\n\n\n");
	pernode(T, myvisit);
	printf("\n\n\n");
	//printf("%d",hightree(T));
	delbintree(T);
	return 0;
}