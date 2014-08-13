#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int DataType;

int QuickSort(DataType *arr, int len)
{
	int tmp;
	int tmp1;
	int i, j;
	if (arr == NULL){ return -1; }
	if (len <= 1)
	{
		return 0;
	}
	tmp = arr[0];
	i = 1;
	j = len - 1;
	while (i < j)
	{
		while (i < j && arr[i] <= tmp){ i++; }
		while (i < j && arr[j] >= tmp){ j--; }
		if (i < j)
		{
			tmp1 = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp1;
		}
	}
	if (arr[i] > arr[0])
	{
		i--;
	}

	arr[0] = arr[i];
	arr[i] = tmp;

	QuickSort(arr, i);
	QuickSort(arr + i + 1, len - i -1);
	return 0;
}
int main()
{
	int size = 100;
	int *a = (int *)malloc(sizeof(int)* size);
	//time_t start, end;
	double start, end;
	double cost;
	if (a == nullptr)
	{
		return -1;
	}
	for (int i = 0; i < size; i++)
	{

		a[i] = rand() % size;
	}
	//time(&start);
	start = clock();
	QuickSort(a, size);
	//time(&end);
	end = clock();
	//cost = difftime(end, start);
	cost = end - start;
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\t",a[i]);
	}
	printf("%f\n", cost);
	return 0;
}