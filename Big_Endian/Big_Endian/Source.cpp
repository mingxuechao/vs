/*
	Big_Endian  高位字节存放在内存的低地址。
	*/

#include <stdio.h>

int Is_Little_Endian()
{
	int i = 1;
	char *cptr = (char *)&i;
	return (int)(*cptr);
}

int main()
{
	int tmp = Is_Little_Endian();
	if (tmp)
	{
		printf("litten_endian\n");
	}
	else
	{
		printf("big_endian\n");
	}
	return 0;
}