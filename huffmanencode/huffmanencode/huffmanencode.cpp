#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int wigth;
	unsigned int lchild, rchild, parent;
}Node, *HFMTree;
typedef struct acode
{
	char abc;
	int wigth;
	char *code;
}abccode;
void selectnode(HFMTree ht, int end, int &node1, int &node2)
{
	int wigth1 = INT_MAX;
	int wight2 = INT_MAX;
	int j = 1;
	while (j <= end)
	{
		if (ht[j].parent == 0)
		{
			if (ht[j].wigth <= wigth1)
			{
				wight2 = wigth1;
				wigth1 = ht[j].wigth;
				node2 = node1;
				node1 = j;
				j++;
				continue;
			}
			else if (ht[j].wigth <= wight2)
			{
				wight2 = ht[j].wigth;
				node2 = j;
				j++;
				continue;
			}
			else
			{
				j++;
				continue;
			}
		}
		j++;
	}

}

void HuffMancode(HFMTree &T, char** &huffcode, int *wight, int len)
{
	int m = 2 * len - 1;
	T = (HFMTree)malloc(sizeof(Node)* (m + 1));
	int i;
	Node *p;
	int node1id, node2id;
	T[0] = { *wight, INT_MAX, INT_MAX, INT_MAX };
	for (p = T + 1, i = 1; i <= len; i++)
	{
		*p = { *wight, 0, 0, 0 };
		p++;
		wight++;
	}
	for (; i <= m; i++)
	{
		*p = { 0, 0, 0, 0 };
		p++;
	}
	for (i = len + 1; i <= m; i++)
	{
		selectnode(T, i - 1, node1id, node2id);
		//ÓÒ±ßÐ¡ÓÚ×ó±ß
		T[node1id].parent = i;
		T[node2id].parent = i;
		T[i].rchild = node1id;
		T[i].lchild = node2id;
		T[i].wigth = T[node1id].wigth + T[node2id].wigth;
	}
	huffcode = (char **)malloc(len * sizeof(char *));
	char *tmp = (char *)malloc(len * sizeof(char));
	tmp[len - 1] = '\0';
	for (i = 1; i <= len; i++)
	{
		int start = len - 2;
		Node tmpnode = T[i];
		int tmpid = i;
		while (tmpnode.parent != 0)
		{
			if (T[tmpnode.parent].lchild == tmpid)
			{
				tmp[start] = '1';
			}
			else
			{
				tmp[start] = '0';
			}
			start--;
			tmpid = tmpnode.parent;
			tmpnode = T[tmpnode.parent];
		}
		huffcode[i] = (char *)malloc(sizeof(char)* (len - start));
		strcpy(huffcode[i], tmp + start + 1);
	}
	free(tmp);
}
int huffmanencode(char *src, int len, char *&bit, abccode *huffcode, int abc_code_len)
{
	int index = 0;
	int now_len = 0;
	int max_len = 1024;
	bit = (char *)malloc(sizeof(char)* 1024);
	for (index; index < len; index++)
	{
		for (size_t i = 0; i < abc_code_len; i++)
		{
			if (src[index] == huffcode[i].abc)
			{
				if ((now_len + strlen(huffcode[i].code)) > max_len)
				{
					max_len += 512;
					bit = (char *)realloc(bit, max_len);
				}
				strcpy(bit + now_len, huffcode[i].code);
				now_len += strlen(huffcode[i].code);
			}
		}
	}
	return 0;
}
int huffmandecode(char *bit, int len, char *&des, abccode *huffcode, int abc_code_len)
{
	int index = 0;
	int now_len = 0;
	int tmplen = 512;
	char tmp[512];

	int des_len = 0;
	des = (char *)malloc(sizeof(char)* 512);
	while (bit[index] != '\0')
	{
		int flg = 0;
		for (size_t i = 0; i < len; i++)
		{
			int j = 0;
			tmp[i] = bit[index + i];
			tmp[i + 1] = '\0';
			for (int i = 0; i < abc_code_len; i++)
			{
				if (strcmp(tmp, huffcode[i].code) == 0)
				{
					flg += 1;
					j = i;
				}
			}
			if (flg == 1)
			{
				des[des_len] = huffcode[j].abc;
				des_len += 1;
				index = index + strlen(tmp);
				break;
			}
		}

	}
	des[des_len] = '\0';
	return 0;
}
int main()
{
	abccode abc_huff[6] = {
		{ '1', 5, NULL },
		{ '2', 15, NULL },
		{ '3', 20, NULL },
		{ '4', 30, NULL },
		{ '5', 10, NULL },
		{ '6', 20, NULL }
	};
	char *data = "6541216522145126561524";
	char *data2 = NULL;
	char *bit = NULL;
	char** code = NULL;
	HFMTree T;
	int *wight = (int *)malloc(sizeof(int)* (sizeof(abc_huff) / sizeof(abccode)));
	for (size_t i = 0; i < (sizeof(abc_huff) / sizeof(abccode)); i++)
	{
		wight[i] = abc_huff[i].wigth;
	}
	HuffMancode(T, code, wight, sizeof(abc_huff) / sizeof(abccode));
	for (size_t i = 0; i < sizeof(abc_huff) / sizeof(abccode); i++)
	{
		abc_huff[i].code = code[i + 1];
		printf("%c:%s\n",abc_huff[i].abc,abc_huff[i].code);
	}
	huffmanencode(data, strlen(data), bit, abc_huff, sizeof(abc_huff) / sizeof(abccode));
	huffmandecode(bit, strlen(bit), data2, abc_huff, sizeof(abc_huff) / sizeof(abccode));

	printf("%s\n%d\n%s\n", bit, strlen(bit), data2);
	return 0;
}