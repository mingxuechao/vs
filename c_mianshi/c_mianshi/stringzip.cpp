#include <stdio.h>
#include <string.h>

void stringzip(const char* src, int len, char * des)
{
	int start = 0;
	int end = 0;
	int startdes = 0;
	int num;
	while (start < len)
	{
		if (*(src + start) == *(src + end))
		{
			start++;
		}
		else
		{
			num = start - end;
			if (num > 1)
			{
				des[startdes] = *(src + end);
				startdes++;
				des[startdes] = (char)(num + '0');
				startdes++;
			}
			else
			{
				des[startdes] = *(end + src);
				startdes++;
			}
			end = start;
		}
	}
	num = start - end;
	if (num > 1)
	{
		des[startdes] = *(src + end);
		startdes++;
		des[startdes] = (char)(num + '0');
		startdes++;
	}
	else
	{
		des[startdes] = *(end + src);
		startdes++;
	}
	des[startdes] = '\0';
}

/*
int main()
{
	//char *src = "dfsfaaabbbcccdddeeefffhhhg";
	char *src = "aaaaaaa";
	char des[1024];
	stringzip(src, strlen(src), des);
	printf("%s\n",des);
	return 0;
}
*/
