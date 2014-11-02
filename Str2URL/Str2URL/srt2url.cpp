#include <stdio.h>
#include <string.h>
char *str2url(char *str)
{
	char *end1, *end2;
	int blank = 0;
	int len = strlen(str);
	int lenaf = 0;
	for (int i = 0; i < len; i++)
	{
		if (*(str + i) == ' ')
		{
			blank++;
		}
	}
	lenaf = len + blank * 2;
	while (len != lenaf)
	{
		if (*(str+len) != ' ')
		{
			*(str + lenaf--) = *(str + len--);
		}
		else
		{
			len--;
			*(str + lenaf--) = '0'; *(str + lenaf--) = '2'; *(str + lenaf--) = '%';
		}
	}
	return str;
}
int main()
{
	char  str[1024] = " hello word! Are you ready!";
	str2url(str);
	printf("%s\n",str);
	return 0;
}