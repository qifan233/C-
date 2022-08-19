#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct List
{
	struct List* prev;
	int data;
	struct List* next;
}S;

S* Expansion(int x);

S* PushBack(S* s, int x);
S* PushFront(S* s, int x);
S* PopBack(S* s);
S* PopFront(S* s);
S* Chack(S* s, S* pos, int x);
S* Insert(S* s, S* pos, int x);
S* Delete(S* s, S* pos);
void Print(S* s);

S* Destroy(S* s);