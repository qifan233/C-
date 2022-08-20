#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Stack
{
	int data;
	struct Stack* next;
}ST;

ST* Origin(ST* s);
ST* Destroy(ST* s);
void StackPush(ST* s, int x);
void StackPop(ST* s);
int StackTop(ST* s);
int StackSize(ST* s);
bool StackEmtpy(ST* s);
void Prin(ST* s);