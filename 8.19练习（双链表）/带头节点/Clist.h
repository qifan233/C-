#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct List
{
	int data;
	struct List* prev;
	struct List* next;
}S;

S* Origin(S* list);
S* Expansion(int x);

void PushBack(S* list, int x);
void PushFront(S* list, int x);
void PopBack(S* list);
void PopFront(S* list);
S* Chack(S* list, S* pos, int x);
void Insert(S* list, S* pos, int x);
void Delete(S* list, S* pos);
void Prin(S* list);
S* Destroy(S* list);