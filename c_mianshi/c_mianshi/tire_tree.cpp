#include "std.h"
typedef struct Node
{
	bool isStr = false;
	TireTree next[26] = { NULL };
}*TireTree, TireTreeNode;

void set_null(TireTree &t)
{
	for (size_t i = 0; i < 26; i++)
	{
		t->next[i] = NULL;
	}
}
int TireTree_insert(TireTree &root, char *str)
{
	if (root == NULL)
	{
		return 0;
	}
	TireTree tmp = root;
	char * tmpchar = str;
	while (*tmpchar != '\0')
	{
		if (tmp->next[*tmpchar - 'a'] == NULL)
		{
			TireTree tmpnode = (TireTree)malloc(sizeof(Node));
			if (*(tmpchar + 1) == '\0')
			{
				tmpnode->isStr = true;
			}
			else
			{
				tmpnode->isStr = false;
			}
			set_null(tmpnode);
			tmp->next[*tmpchar - 'a'] = tmpnode;
		}
		tmp = tmp->next[*tmpchar - 'a'];
		tmpchar++;
	}
}
bool TireTree_serch(TireTree &root, char *str)
{
	char *tmp = str;
	TireTree tmptree = root;
	while (*tmp != '\0' && tmptree->next[*tmp - 'a'] != NULL)
	{
		tmp++;
		tmptree = tmptree->next[*tmp - 'a'];
	}
}