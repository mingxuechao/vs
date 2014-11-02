#include "std.h"
int parttion(int *data, int low, int high)
{
	int key = data[low];
	while (low < high)
	{
		while (low < high && data[high] >= key) high--;
		data[low] = data[high];
		while (low < high && data[low] <= key) low++;
		data[high] = data[low];
	}
	data[low] = key;
	return low;
}
void quick_sort(int *data, int low, int high)
{
	if (low < high)
	{
		int parti_key = parttion(data, low, high);
		quick_sort(data, 0, parti_key - 1);
		quick_sort(data, parti_key + 1, high);
	}
}
/*
int main()
{
	int a[] = { 5, 6, 5, 9, 2, 82, 35, 11, 354, 8 };
	quick_sort(a, 0, 9);
	return 0;
}
*/