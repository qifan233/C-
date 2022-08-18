#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Slist
{
	int data;
	struct Slist* next;
}S;

S* Origin(S* list);
S* Expansion(int x);
void Prin(S*);

S* PushBack(S* list, int x);
S* PushFront(S* list, int x);
S* PopBack(S* list);
S* PopFront(S* list);
S* PushEvery(S* pos, int x);
S* PopEvery(S* list, S* pos);
S* Chack(S* list, int x);
S* Destroy(S* list);