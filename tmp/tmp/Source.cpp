#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 4
/*
void lyl(int b[N][N])
{
	int i, j;
	for (i = 0, j = 0; i<N, j<N; i++, j++)
		b[i][j] = 1;
	for (i = 0, j = N - 1; i<N, j >= 0; i++, j--)
		b[i][j] = 1;
}
int sum(int b[N][N])
{
	int i, j, sum = 0;
	for (i = 0; i<N; i++)
	for (j = 0; j<N; j++)
		sum = sum + b[i][j];
	if (N % 2 == 1)
		sum -= 2 * N - 1;
	else
		sum -= 2 * N;
	return sum;
}
int main()
{
	int a[N][N], i, j;
	for (i = 0; i<N; i++)
	for (j = 0; j<N; j++)
		scanf("%d",&a[i][j]);
	lyl(a);
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("The total of other numbers is:%d\n", sum(a));
	return 0;
}
int rand_0_1();
int Rand()
{
	int i1 = rand_0_1();
	int i2 = rand_0_1();
	if (i1 == 1 && i2 == 0)
	{
		return 1;
	}
	else if (i1 == 0 && i2 == 1)
	{
		return 0;
	}
	else
	{
		return Rand();
	}
	return -1;
}
*/
#include <math.h>
int main()
{
	printf("log24 = %d",int(log(25.0)/log(5.0)));
	return 0;
}