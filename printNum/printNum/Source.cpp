#include <stdio.h>
#include <stdlib.h>
void printnum(int num)
{
	switch (num)
	{
	case 1:
		printf("һ");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	case 4:
		printf("��");
		break;
	case 5:
		printf("��");
		break;
	case 6:
		printf("��");
		break;
	case 7:
		printf("��");
		break;
	case 8:
		printf("��");
		break;
	case 9:
		printf("��");
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
		printf("ǧ");
	}
	if (h != 0)
	{
		printnum(h);
		printf("��");
	}
	else if ((t || b) && k)
	{
		printf("��");
	}
	if (t != 0)
	{
		printnum(t);
		printf("ʮ");
	}
	else if ((h != 0) && (b != 0))
	{
		printf("��");
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
		printf("��");
	}
	if (wan)
	{
		printlesskilo(wan);
		printf("��");
	}
	else if ((yi != 0) && (qian != 0))
	{
		printf("��");
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
