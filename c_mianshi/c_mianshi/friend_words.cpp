#include <stdio.h>
#include <stdlib.h>
//1234的排列组合
static int num = 0;
static char **res = (char **)malloc(sizeof(char *)* 24);
void swap(char *a, char *b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void **perm(char *list, int start, int end)
{
	if (start == end)
	{		
		int i;
		res[num] = (char *)malloc(sizeof(char)* (end + 1));
		for (i = 0; i <= end; i++)
		{
			printf("%c", *(list + i));
			res[num][i] = list[i];
		}
		res[num][i] = '\0';
		num++;
		printf("\n");
	}
	else
	{
		for (int j = start; j <= end; j++)
		{
			swap(list + start, list + j);
			perm(list, start + 1, end);
			swap(list + start, list + j);
		}
	}
	return NULL;
}
/*
int main()
{
	char list[] = { 'a', 'b', 'c', 'd' };
	perm(list, 0, 3);
	printf("\n");
	for (int i = 0; i < 24; i++)
	{
		printf("%s\n", res[i]);
	}
	free(res);
	return 0;
	} */