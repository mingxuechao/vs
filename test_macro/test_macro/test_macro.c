#include <stdio.h>
#include <stdlib.h>

#define Macro1	1
#define Macro2	#TEST
#define TEST #Macro2

int main()
{
	printf("%s",TEST);
}