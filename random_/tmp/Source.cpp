#define _CRT_SECURE_NO_WARNINGS

int rand_0_1();//以固定概率返回1 或 0 
int Rand()//以相同的概率返回0 ，1
{
	int i1 = rand_0_1();
	int i2 = rand_0_1();
	if (i1 == 1 && i2 == 0)
	{
		return 1;
	}
	else if (i1 == 0 && i2 == 1)
	{
		return 0;
	}
	else
	{
		return Rand();
	}
	return -1;
}

