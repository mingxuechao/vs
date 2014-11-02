#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _PrintNumStrResc(int n, char *numstr, int index)
{
	if (n == index)
	{
		//printf("%s\n", numstr);
		static FILE *fp = fopen("./test.txt", "w+");
		fwrite(numstr, 1, strlen(numstr), fp);
		fwrite(numstr, 1, strlen("\n"), fp);
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		numstr[index] = (char)(i + '0');
		_PrintNumStrResc(n, numstr, index + 1);
	}
}
void PrintNumStr(int n)
{
	if (n <= 0)
	{
		return;
	}
	char * numlist = (char *)malloc(sizeof(char)* (n + 1));
	numlist[n] = '\0';
	_PrintNumStrResc(n, numlist, 0);
	delete numlist;
	return;
}/*
int main()
{
	PrintNumStr(8);
	return 0;
	}  */