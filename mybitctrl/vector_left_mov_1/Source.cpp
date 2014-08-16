#include <stdio.h>
#include <stdlib.h>
#include "Bit_ctrl.h"
int vertor_left_mov(int *arr, int len, int n)
{
	int tmp = arr[0];
	char *Flg = (char *)malloc(sizeof(char)*BIT_N_SLOTS(len));
	BIT_INIT(Flg, BIT_N_SLOTS(12));
	delete Flg;
	return 0;
}

int main()
{
	int i = BIT_N_SLOTS(266);
	char BIT[BIT_N_SLOTS(266)];
	BIT_INIT(BIT,266);
	BIT_SET(BIT, 11);
	i = BIT_VALUE(BIT, 11);
	printf("%d",i);
	BIT_CLEAN(BIT, 11);
	i = BIT_VALUE(BIT, 11);
	printf("%d", i);
}