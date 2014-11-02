#include <stdio.h>
int numof_1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	return	count;
}
bool is_2_e(int n)
{
	if ((n & (n - 1)) != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
int chage_m2n(int m, int n)
{
	int xor = m^n;
	return numof_1(xor);
}
/*
int main()
{
	int test = 513;
	int test1 = 511;
	int test2 = 512;
	printf("%d :%d\n", test, numof_1(test));
	printf("%d :%d\n", test1, numof_1(test1));
	printf("%d :%d\n", test2, numof_1(test2));
	printf("changetest:\n");
	printf("%d to %d :%d\n", test, test1, chage_m2n(test1, test));
	printf("%d to %d :%d\n", test, test2, chage_m2n(test2, test));
	printf("%d to %d :%d\n", test1, test2, chage_m2n(test2, test1));
	return 0;
}
*/