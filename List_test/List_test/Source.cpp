#include <stdio.h>
#include <stdlib.h>
typedef struct Mynode
{
	int data;
	struct Mynode *next;
} Node;

int main()
{
	int i;
	Node *list;
	Node *Delete;
	if ((list = (Node *)malloc(sizeof(Node))) == NULL)
	{
		return -1;
	}
	list->data = 1;
	list->next = NULL;

	for (int i = 0; i < 10; i++)
	{
		Node *tmp;
		if ((tmp = (Node *)malloc(sizeof(Node))) == NULL)
		{
			return -1;
		}
		tmp->data = i;
		tmp->next = list->next;
		list->next = tmp;
	}
	Delete = list;
	while (Delete)
	{
		if (Delete->data != 3)
		{
			Delete = Delete->next;
			continue;
		}
		break;
	}
	delete(Delete);
	printf("%d",Delete->data);

	return 0;
}