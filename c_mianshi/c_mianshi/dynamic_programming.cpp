#include "std.h"
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
	}else
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
	int *dyprice = (int *)malloc((len+1) * sizeof(int));
	int max = 0;
	int dypricelen = 0;
	for (int i = 0; i <= len; i++)
	{
		dyprice[i] = 0;
	}
	max = getmaxsplit(len, price, pricelen, dyprice, dypricelen);
	return max;
}
int main()
{
	//ddddddddddddddddd, 1, 2, 3, 4,  5,  6,  7,  8,  9, 10
	int price[11] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 90 };//i米钢材的价格,0号标价未用
	//price[16] = 10000;
	int len = 20;
	int max = 0,max1 = 0;
	max1 = maxprice(10, price, 10);
	max = dymaxprice(10, price, 10);
	return 0;
}
