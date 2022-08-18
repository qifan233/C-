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

void PushBack(S* list, int x);
void PushFront(S* list, int x);
void PushEvery(S* list, S* pos, int x);
void PopBack(S* list);
void PopFront(S* list);
void PopEvery(S* list, S* pos);
S* Chack(S* list, S* pos, int x);
S* Destroy(S* list);