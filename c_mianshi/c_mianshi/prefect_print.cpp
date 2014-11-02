#include "std.h"
#include <math.h>
int word_sum(int word_len[], int start, int end)
{
	int sum = 0;
	for (size_t i = start; i <= end; i++)
	{
		sum = sum + word_len[i];
	}
	return sum;
}
int word_print(int wordlen[], int M, int len, int history[], int pos[])
{
	int blanklen[100][100] = { 0 };
	int blanklenp3[100][100] = { 0 };
	for (int i = 1; i <= len; i++)
	{
		for (int j = i; j <= len; j++)
		{
			blanklen[i][j] = M - j + i - word_sum(wordlen, i, j);
			if (blanklen[i][j] < 0)
			{//超过了这一行
				blanklenp3[i][j] = INT_MAX;
			}
			else if (j == len)
			{//最后一行长度不算
				blanklenp3[i][j] = 0;
			}
			else
			{//
				blanklenp3[i][j] = _Pow_int(blanklen[i][j], 3);
			}
			int tmp = history[i - 1] + blanklenp3[i][j];
			if (tmp < history[j])
			{
				history[j] = tmp;
				pos[i - 1] = j;
			}
		}
	}
}
