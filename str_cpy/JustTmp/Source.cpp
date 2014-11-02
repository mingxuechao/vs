#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

char *my_strcpy(char *strdes, const char *strsrc)
{

	assert(strdes != NULL);
	assert(strsrc != NULL);
	char * address = strdes;
	while ((*strdes++ = *strsrc++) != '\0')
	{
		NULL;
	}
	return address;
}

int main()
{
	char *p = "hello world";
	char *d = NULL;
	//my_strcpy(d, p);
	strcpy(d, p);
	printf("%s\n",d);
	return 0;
}