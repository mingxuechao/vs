#include <stdio.h>
#include <stdlib.h>
typedef struct treenode
{
	int data;
	struct treenode *lchild, *rchild;
}*myTree, myNode;

myTree per_mid_2tree(int per[], int perstart, int perend, int mid[], int midstart, int midend)
{
	if (perend < perstart)
	{
		return NULL;
	}
	else
	{
		myNode *nodedata = (myTree)malloc(sizeof(myNode));
		int index;
		bool flg = false;
		for (index = midstart; index <= midend; index++)
		{
			if (per[perstart] == mid[index])
			{
				flg = true;
				break;
			}
		}
		if (!flg)
		{
			exit(0);
		}
		int lcnum = index - midstart;
		int rcnum = midend - index;
		nodedata->data = per[perstart];
		nodedata->lchild = per_mid_2tree(per, perstart + 1, perstart + lcnum, mid, midstart, index - 1);
		nodedata->rchild = per_mid_2tree(per, perstart + lcnum + 1, perend, mid, index + 1, midend);
		return nodedata;
	}
}

/*
int main()
{
	int per[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int mid[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	myTree my;
	my = per_mid_2tree(per, 0, 7, mid, 0, 7);
	printf("ddddd");
	return 0;
}
*/