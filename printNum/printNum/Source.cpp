#include <stdio.h>
#include <stdlib.h>
void printnum(int num)
{
	switch (num)
	{
	case 1:
		printf("一");
		break;
	case 2:
		printf("二");
		break;
	case 3:
		printf("三");
		break;
	case 4:
		printf("四");
		break;
	case 5:
		printf("五");
		break;
	case 6:
		printf("六");
		break;
	case 7:
		printf("七");
		break;
	case 8:
		printf("八");
		break;
	case 9:
		printf("九");
		break;
	}
}
void printlesskilo(int num)
{
	int k = num / 1000;
	int h = num / 100 - k * 10;
	int t = num / 10 - h * 10 - k * 100;
	int b = num % 10;
	if (k != 0)
	{
		printnum(k);
		printf("千");
	}
	if (h != 0)
	{
		printnum(h);
		printf("百");
	}
	else if ((t || b) && k)
	{
		printf("零");
	}
	if (t != 0)
	{
		printnum(t);
		printf("十");
	}
	else if ((h != 0) && (b != 0))
	{
		printf("零");
	}
	if (b != 0)
	{
		printnum(b);
	}
}

void num2ch(int num)
{
	int yi = num / 100000000;
	int wan = (num % 100000000) / 10000;
	int qian = num % 10000;
	if (yi)
	{
		printlesskilo(yi);
		printf("亿");
	}
	if (wan)
	{
		printlesskilo(wan);
		printf("万");
	}
	else if ((yi != 0) && (qian != 0))
	{
		printf("零");
	}
	if (qian)
	{
		printlesskilo(qian);
	}
}
int main()
{
	num2ch(101100010);
	return 0;
}
