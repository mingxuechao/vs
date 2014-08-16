#include <stdio.h>
#include <stdlib.h>

int Calc(char *s, int i, int *next)
{

	if (s[i] >= '0' && s[i] <= '9')
	{
		*next = i + 1;
		return s[i] - '0';
	}
	else
	{
		int n;
		int a = Calc(s, i + 1, &n);
		int b = Calc(s, n, next);
		switch (s[i])
		{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			break;
		}
	}

}

void main()
{
	int s;
	printf("%d\n", Calc("+2*+345", 0, &s));
}
