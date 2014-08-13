#include <stdio.h>
#include <stdlib.h>

int Reverse(int *arr, int len)
{
	if (arr == NULL || len <= 0)
	{
		return -1;
	}
	int tmp;
	int i = 0;
	for (i = 0; i <= (len - 1) / 2; i++)
	{
		tmp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = tmp;
	}
	return 0;
}

int vector_left_mov(int *arr, int len, int n)
{
	if (Reverse(arr, n))
	{
		return -1;
	}
	if (Reverse(arr + n, len - n))
	{
		return -1;
	}
	if (Reverse(arr, len))
	{
		return -1;
	}
	return 0;
}
int main(void)
{
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
/*	Reverse(array, 4);
	Reverse(array + 4, 6);
	Reverse(array, 10);
	vector_left_mov(array, 10, 4);
*/	
	
	Reverse(array, 3);
	Reverse(array + 3, 4);
	Reverse(array + 7, 3);
	Reverse(array, 10);
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d", array[i]);
	}
}