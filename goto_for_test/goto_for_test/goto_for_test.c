#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("echo in for i = %d.\n", i);
		test_goto_entry();
		if (i % 2)
		{
			goto test_go;
		}
	}
test_go:
	{
		printf("echo in goto i = %d.\n", i);
	}
	return 0;
}