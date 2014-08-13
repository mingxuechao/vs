#include <stdio.h>
#include <stdlib.h>
int vector_left_mov(int *arr, int len, int n)
{
	int *tmp = (int *)malloc(sizeof(int)*n); 
	if (!tmp)
	{
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		tmp[i] = arr[i];
	}
	if (len < n || len <= 0 || n < 0 || arr == NULL)
	{
		return -1;
	}
	if (n == len || n == 0)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < len; j = j + n)
		{

			if ((j + n)>=len)
			{
				arr[j] = tmp[(j+n)%len];
				break;
			}
			arr[j] = arr[(j + n)];
		}
	}
	delete tmp;
	return 0;
}

int main(void)
{
	int result;
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	result = vector_left_mov(array, 10, 4);
	if (result)
	{
		perror("sth has wrong!\n");
	}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d",array[i]);
	}
}