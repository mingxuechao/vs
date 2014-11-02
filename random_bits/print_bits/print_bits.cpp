#include <stdio.h>
#include <stdlib.h>

void print_bits(char *s, int len, int start = 0)
{
	if (start >= len)
	{
		s[start] = '\0';
		printf("%s", s);
		printf("\n");
	}
	else
	{
		s[start] = '0';
		print_bits(s, len, start + 1);
		s[start] = '1';
		print_bits(s, len, start + 1);

	}
}

int main()
{
	char tmp[10];
	print_bits(tmp, 3);
	return 0;
}