#include <stdio.h>
int main()
{
	int i = 0x40000000;
	int j = i << 2;
	printf("%d,%d\n",i,j);
	return 0;
}