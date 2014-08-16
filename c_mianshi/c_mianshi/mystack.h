#ifndef _MYSTACK
#define _MYSTACK
#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define STACK_INIT_SIZE  100
#define ADD  20

typedef struct Stack

{
	int *base;
	int *top;
	int stacksize;
} mystack;
bool InitStack(mystack *S);
bool Push(mystack *S, int e);
bool Pop(mystack *S, int *e);
int max(mystack *S);
void delstack(mystack *S);
#endif