#include <stdio.h>
#include <stdlib.h>


int GetMidMax(int d[], int start, int end, int mid, int &mid_start, int &mid_end)
{
	int leftmax, rightmax;
	int sum = 0;
	leftmax = INT_MIN;
	rightmax = INT_MIN;
	for (int i = mid; i >= start; i--)
	{
		sum = sum + d[i];
		if (sum > leftmax)
		{
			leftmax = sum;
			mid_start = i;
		}
	}
	sum = 0;
	for (int i = mid + 1; i <= end; i++)
	{
		sum = sum + d[i];
		if (sum > rightmax)
		{
			rightmax = sum;
			mid_end = i;
		}
	}
	return leftmax + rightmax;
}
int GetMaxSubArray(int d[], int start, int end, int &sub_start, int &sub_end)
{
	int left_substart, left_subend, right_substart, right_subend, mid_start, mid_end;
	int left_max, right_max, mid_max,max;
	int mid = (start + end) / 2;
	if (start < end)
	{
		left_max = GetMaxSubArray(d, 0, mid, left_substart, left_subend);
		right_max = GetMaxSubArray(d, mid + 1, end, right_substart, right_subend);
		mid_max = GetMidMax(d, 0, end, mid, mid_start, mid_end);
		if ((left_max >= right_max) && (left_max >= mid_max))
		{
			sub_start = left_substart;
			sub_end = left_subend;
			max = left_max;
		}
		else if (right_max >= mid_max)
		{
			sub_start = right_substart;
			sub_end = right_subend;
			max = right_max;
		}
		else
		{
			sub_start = mid_start;
			sub_end = mid_end;
			max = mid_max;
		}
	}
	else
	{
		sub_end = start;
		sub_start = start;
		max = d[start];
	}
	return max;
}
/*
int main()
{
	int d[] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	int start, end, max;
	max = GetMaxSubArray(d, 0, 15, start, end);
	return 0;
	} */