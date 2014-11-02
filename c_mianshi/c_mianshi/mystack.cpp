#include "mystack.h"
bool InitStack(mystack *S)
{
	S->base = (int *)malloc(STACK_INIT_SIZE *sizeof(int));
	if (S->base == NULL)
		return false;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return true;
}
bool Push(mystack *S, int e)
{
	if (S == NULL)
		return false;
	assert((S->base != NULL) && (S->top != NULL));
	if (S->top - S->base >= S->stacksize)
	{
		S->base = (int *)realloc(S->base, (S->stacksize + ADD) * sizeof(int));
		if (!S->base)
			exit(0);
		S->top = S->base + S->stacksize;
		S->stacksize += ADD;

	}
	*(S->top++) = e;
	return true;
}
bool Pop(mystack *S, int *e)
{
	if ((*S).top == (*S).base)
		return false;
	*e = *--(*S).top;
	return true;
}
int max(mystack *S)
{
	int tmp;
	tmp = *(S->base);
	int *index = S->base;
	index = index + 1;
	while (index != S->top)
	{
		if (tmp < (*index))
			tmp = *index;
		index++;
	}
	return tmp;
}
void delstack(mystack *S)
{
	for (size_t i = 0; i < S->stacksize; i++)
	{
		free(S->base + i);
	}
}