#include <stdio.h>
int frogjump(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	int path[512] = { 0, 1, 2 };
	if (n <= 2)
	{
		if (n == 1)
		{
			return 1;
		}
		else
		{
			return 2;
		}		
	}
	else
	{
		for (int i = 3; i <= n; i++)
		{
			path[i] = path[i - 1] + path[i - 2];
		}
	}
	return path[n];
}
/*
int main()
{
	int k = frogjump(10);
	return 0;
}
*/
