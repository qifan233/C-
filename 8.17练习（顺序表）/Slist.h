#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Slist
{
	int* data;
	int capacity;
	int total;
}S;

S* Origin(S*);
void Expansion(S*);

void PushBack(S*, int);
void PushFront(S*, int);
void PopBack(S*);
void PopFront(S*);
int Chack(S*, int, int);
void Change(S*, int, int);
void EveryInsert(S*, int, int);
void EveryDelete(S*, int);

void Prin(S*);
S* Destroy(S*);