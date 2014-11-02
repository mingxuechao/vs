#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
void getmem(char * &p, int num)
{
	p = (char *)malloc(num);
}
int main_1()
{
	char *str = NULL;
	getmem(str, 10);
	strcpy(str, "helld");
	printf(str);
	free(str);
	return 0;
}