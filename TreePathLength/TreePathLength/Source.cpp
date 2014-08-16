#include "mytree.h"
#include <stdio.h>
int atree[] = { 8,6,5,69,282,39,3,46,4,10 };
int main()
{
	BinTree T;
	Bintreeinit(T, *atree);
	for (size_t i = 1; i < 10; i++)
	{
		sorttree_insert(T, atree[i]);
	}
	printf("\n\n\n");
	midnode(T);
	printf("\n\n\n");
	printf("%d\n\n\n",hightree(T));
	delbintree(T);
	return 0;
}