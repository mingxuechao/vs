#include <stdio.h>
#include <stdlib.h>
typedef struct myLinkNode
{
	int data;
	myLinkNode * next;
} myLinkNode, *myLink;
int reversal(myLink &Li, int k)
{
	int tmpk = k;
	int flg = 1;
	myLink k_head = NULL, k_end, header, Li_tmp, Next_tmp, tmp_tmp;
	header = NULL;
	Li_tmp = NULL;
	Next_tmp = Li;
	while (Next_tmp != NULL)
	{
		if (tmpk > 0)
		{
			if (tmpk == k){
				k_end = Next_tmp;
				k_head = Next_tmp;
				k--;
				Next_tmp = Next_tmp->next;
			}
			else
			{
				tmp_tmp = Next_tmp;
				Next_tmp = Next_tmp->next;
				tmp_tmp->next = k_head;
				k_head = tmp_tmp;
			}
		}
		else
		{
			Li_tmp = Next_tmp;
			if (flg == 1)
			{
				header = k_head;
				flg = 0;
			}
		}
	}
	Li = header;
	return 0;
}
//int main()
//{
//	myLinkNode node[10];
//	myLink link = node;
//	for (size_t i = 0; i < 10; i++)
//	{
//		node[i].data = i;
//		node[i].next = (node + i + 1);
//	}
//	node[9].next = NULL;
//	reversal(link, 2);
//	return 0;
//}