#define _CRT_SECURE_NO_WARNINGS
#include "std.h"
#include <string.h>
#define MAX(a,b) (a) > (b)? a:b
/*回文算法*/

//连续的回文才算。
int find_palin(char *data, int datalen, int &palen)
{
	if (datalen > 1)
	{
		if (*data != *(data + datalen - 1))
		{
			int tmp1 = 0;
			int tmp2 = 0;
			find_palin(data + 1, datalen - 1, tmp1);
			find_palin(data, datalen - 1, tmp2);
			palen = MAX(tmp1, tmp2);
		}
		else
		{
			palen = palen + 2;
			find_palin(data + 1, datalen - 2, palen);
		}
	}
	else
	{
		palen++;
	}
	return palen;
}
//整个连中回文都算。
int find_palin1(char *data, int datalen, int &palen)
{
	if (datalen > 1)
	{
		if (*data != *(data + datalen - 1))
		{
			int tmp1 = 0;
			int tmp2 = 0;
			find_palin1(data + 1, datalen - 1, tmp1);
			find_palin1(data, datalen - 1, tmp2);
			palen = palen + MAX(tmp1, tmp2);
		}
		else
		{
			find_palin1(data + 1, datalen - 2, palen);
			palen = palen + 2;
		}
	}
	else
	{
		palen++;
	}
	return palen;
}

typedef struct Mypath
{
	int len = 0;
	char *str = NULL;
}Mypath;
//带备忘录的，自顶向下的回文
int find_palin2(char *data, int start, int end, Mypath path[100][100])
{
	if (path[start][end].str != NULL)
	{
		return path[start][end].len;
	}
	else
	{
		if (start < end)
		{
			if (*(data + start) != *(data + end))
			{
				int tmp1 = 0;
				int tmp2 = 0;
				tmp1 = find_palin2(data, start + 1, end, path);
				tmp2 = find_palin2(data, start, end - 1, path);
				char *tmpstr = (char *)malloc(sizeof(char)* MAX(tmp1, tmp2) + 1);
				if (tmp1 >tmp2)
				{
					strncpy(tmpstr, path[start + 1][end].str, tmp1);
					tmpstr[tmp1] = '\0';
				}
				else
				{
					strncpy(tmpstr, path[start][end - 1].str, tmp2);
					tmpstr[tmp2] = '\0';
				}
				path[start][end].len = MAX(tmp1, tmp2);
				path[start][end].str = tmpstr;
				return 	 path[start][end].len;
			}
			else
			{
				find_palin2(data, start + 1, end - 1, path);
				int len = path[start + 1][end - 1].len;
				char *tmpstr = (char *)malloc(sizeof(char)* len + 3);
				tmpstr[0] = data[start];
				strncpy(tmpstr + 1, path[start + 1][end - 1].str, len);
				tmpstr[len + 1] = data[start];
				tmpstr[len + 2] = '\0';
				path[start][end].str = tmpstr;
				path[start][end].len = path[start + 1][end - 1].len + 2;
				return path[start][end].len;
			}
		}
		else
		{
			if (start == end)
			{
				char *tmpstr = (char *)malloc(sizeof(char)* 2);
				tmpstr[0] = data[start];
				tmpstr[1] = '\0';
				path[start][end].str = tmpstr;
				path[start][end].len = 1;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

//带备忘的，自底向上的算法。
int fucntion(char *data, int start, int end, Mypath path[100][100])
{
	int len;
	char *tmpstr;
	if (end < start)
	{
		return 0;
	}
	else
	{
		if (start == end)
		{
			len = 1;
			tmpstr = (char *)malloc(sizeof(char)* len + 1);
			tmpstr[0] = data[start];
			tmpstr[1] = '\0';
		}
		else
		{
			if (data[start] == data[end])
			{
				len = path[start + 1][end - 1].len + 2;
				tmpstr = (char *)malloc(sizeof(char)* len + 1);
				tmpstr[0] = data[start];
				strncpy((tmpstr + 1), path[start + 1][end - 1].str, path[start + 1][end - 1].len);
				tmpstr[len -1] = data[start];
				tmpstr[len ] = '\0';
			}
			else
			{
				int tmp1 = path[start + 1][end].len;
				int tmp2 = path[start][end - 1].len;
				if (tmp1 > tmp2)
				{
					len = tmp1;
					tmpstr = (char *)malloc(sizeof(char)* len + 1);
					strcpy(tmpstr , path[start + 1][end].str);
				}
				else
				{
					len = tmp2;
					tmpstr = (char *)malloc(sizeof(char)* len + 1);
					strcpy(tmpstr, path[start][end - 1].str);
				}
			}
		}
		path[start][end].len = len;
		path[start][end].str = tmpstr;
	}
	return 0;
}
int find_palin3(char *data, int len, Mypath path[100][100])
{
	for (int i = len - 1; i >= 0; i--)
	{
		for (int j = i; j < len; j++)
		{
			fucntion(data, i, j, path);
		}
	}
	return path[0][len -1].len;
}


/*
int main()
{
	char *data1 = "chacaracatcer";
	int datalen = 13;
	Mypath path[100][100];
	int len = 0;
	//len = find_palin2(data1, 0, 12, path);
	len = find_palin3(data1, 13, path);
	printf("%d\n", len);
	printf("%s\n", path[0][12].str);
	return 0;
}
*/