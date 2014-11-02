#include "std.h"

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int adjust_heap(int data[], int index, int len)
{
	int tmpindex = index;
	while (tmpindex < len)
	{
		int lindex = tmpindex * 2 + 1;
		int rindex = tmpindex * 2 + 2;
		if (rindex < len)
		{
			if (data[tmpindex] <= data[lindex] && data[tmpindex] <= data[rindex])
			{
				return 0;
			}
			else
			{
				if (data[lindex] >= data[rindex])
				{
					swap(data[rindex], data[tmpindex]);
					tmpindex = rindex;
				}
				else
				{
					swap(data[lindex], data[tmpindex]);
					tmpindex = lindex;
				}
			}
		}
		else
		{
			if (lindex < len)
			{
				if (data[tmpindex] > data[lindex])
				{
					swap(data[lindex], data[tmpindex]);
					tmpindex = lindex;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

int heap_sort(int data[], int len)
{
	for (int i = ((len - 1) / 2); i >= 0; i--)
	{
		adjust_heap(data, i, len);
	}
	int tmplen = len - 1;
	while(tmplen)
	{
		swap(data[tmplen], data[0]);
		adjust_heap(data, 0, tmplen);
		tmplen--;
	}
	return 0;
}

/*
int main()
{
	int data[10] = { 5, 9, 29, 8, 35, 15, 51, 56, 10, 2 };
	heap_sort(data, 10);
	return 0;
}
*/