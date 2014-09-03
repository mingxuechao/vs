#include "std.h"
#define MAXLENGTH 1024
#define MAX(a,b) ((a) >= (b) ? (a):(b))
//动态规划,钢材分割问题
//ddddddddddddddddd, 1, 2, 3, 4,  5,  6,  7,  8,  9, 10
int price[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 90 };//i米钢材的价格
//无动态规划的直接递归算法
int maxprice(int len, int *price, int pricelen)
{
	int max = INT_MIN;
	if (len <= 0)
	{
		max = 0;
	}
	else
	{
		for (int i = 1; i <= len; i++)
		{
			if (i <= pricelen)
			{
				max = MAX(max, price[i] + maxprice(len - i, price, pricelen));
			}

		}
	}
	return max;
}
//自顶向下的动态规划
int getmaxsplit(int len, int *price, int pricelen, int *dyprice, int &dypricelen)
{
	int max = INT_MIN;
	if (len <= 0)
	{
		max = 0;
	}
	else
	{
		if (dyprice[len] != 0)
		{
			max = dyprice[len];
		}
		else
		{
			for (int i = 1; i <= len; i++)
			{
				if (i <= pricelen)
				{
					max = MAX(max, price[i] + getmaxsplit(len - i, price, pricelen, dyprice, dypricelen));
				}
			}
			dypricelen++;
			dyprice[dypricelen] = max;
		}
	}
	return max;
}
int dymaxprice(int len, int *price, int pricelen)
{
	int *dyprice = (int *)malloc((len + 1) * sizeof(int));
	int max = 0;
	int dypricelen = 0;
	for (int i = 0; i <= len; i++)
	{
		dyprice[i] = 0;
	}
	max = getmaxsplit(len, price, pricelen, dyprice, dypricelen);
	free(dyprice);
	return max;
}

//自底向上的算法

int dymaxprice2(int len, int *price, int pricelen)
{
	int *dyprice = (int *)malloc((len + 1) * sizeof(int));	//记录对应长度的最高价格
	int max = 0;
	int dypricelen = 0;
	for (int i = 0; i <= len; i++)
	{
		dyprice[i] = 0;
	}
	for (int i = 1; i <= len; i++)
	{
		max = INT_MIN;
		for (int j = 1; j <= i; j++)
		{
			if (j <= pricelen)
			{
				max = MAX(max, (price[j] + dyprice[i - j]));
			}
		}
		dyprice[i] = max;
	}
	free(dyprice);
	return max;
}

int dymaxprice3(int len, int *price, int pricelen, int *parts, int &partslen)
{
	int *dyprice = (int *)malloc((len + 1) * sizeof(int));	//记录对应长度的最高价格
	int **dyparts = (int **)malloc((len + 1) *sizeof(int));	 // [i][0]记录长度 ，
	int max = 0;
	int dypricelen = 0;
	dyparts[0] = (int *)malloc(sizeof(int));
	dyparts[0][0] = 0;
	for (int i = 0; i <= len; i++)
	{
		dyprice[i] = 0;
	}
	for (int i = 1; i <= len; i++)
	{
		int perlen = 0;
		max = INT_MIN;
		for (int j = 1; j <= i; j++)
		{
			if (j <= pricelen)
			{
				//max = MAX(max, (price[j] + dyprice[i - j]));
				int tmpmax = price[j] + dyprice[i - j];
				if (tmpmax > max)
				{
					max = tmpmax;
					perlen = j;
				}
			}
		}
		dyparts[i] = (int *)malloc(sizeof(int)*(dyparts[i - perlen][0] + 1 + 1));
		dyparts[i][0] = dyparts[i - perlen][0] + 1;
		dyparts[i][1] = perlen;
		for (int k = 1; k <= dyparts[i - perlen][0]; k++)
		{
			dyparts[i][k + 1] = dyparts[i - perlen][k];
		}
		dyprice[i] = max;
	}

	partslen = dyparts[len][0];
	for (int i = 0; i < partslen; i++)
	{
		parts[i] = dyparts[len][i + 1];
	}
	free(dyprice);
	return max;
}
int dymaxprice4(int len, int *price, int pricelen, int *parts, int &partslen)
{
	int *dyprice = (int *)malloc((len + 1) * sizeof(int));	//记录对应长度的最高价格
	int allpart[MAXLENGTH + 1][2]; //0#表示当前的长度，1#表示需要的前驱的长度
	int max = 0;
	int dypricelen = 0;
	allpart[0][0] = 0;
	allpart[0][1] = 0;
	for (int i = 0; i <= len; i++)
	{
		dyprice[i] = 0;
	}
	for (int i = 1; i <= len; i++)
	{
		max = INT_MIN;
		int perlen;
		for (int j = 1; j <= i; j++)
		{
			if (j <= pricelen)
			{
				int tmpmax = price[j] + dyprice[i - j];
				if (tmpmax > max)
				{
					max = tmpmax;
					perlen = j;
				}
			}
			allpart[i][0] = perlen;
			allpart[i][1] = i - perlen; 
		}
		dyprice[i] = max;
	}
	free(dyprice);
	int tmp = len;
	partslen = 0;
	while (allpart[tmp][0] != 0)
	{
		parts[partslen] = allpart[tmp][0];
		tmp = allpart[tmp][1];
		partslen++;
	}
	return max;
}




int main()
{
	//ddddddddddddddddd, 1, 2, 3, 4,  5,  6,  7,  8,  9, 10
	int price[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 90 };//i米钢材的价格,0号标价未用
	//price[16] = 10000;
	int len = 20;
	int max = 0, max1 = 0;
	int parts[1024], parts1[1024];
	int partlen = 0, partlen1 = 0;
	//max1 = dymaxprice(7, price, 10);
	max = dymaxprice3(127, price, 10, parts, partlen);
	max1 = dymaxprice4(127, price, 10, parts1, partlen1);
	for (size_t i = 0; i < partlen; i++)
	{
		printf("%d\t", parts[i]);
	}
	printf("\n");
	for (size_t i = 0; i < partlen1; i++)
	{
		printf("%d\t", parts1[i]);
	}
	printf("\n");
	return 0;
}
