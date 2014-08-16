#include <stdio.h>
#include <stdlib.h>

void main_2()
{
	int garry[4] = { 1, 2 };
	char *ptr = (char *)malloc(30);
	void *pv = malloc(10);
	printf("%d,%d,%d,%d", sizeof(garry), sizeof(ptr), sizeof(*ptr), sizeof(pv));
}