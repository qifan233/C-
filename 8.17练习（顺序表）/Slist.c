#include "Slist.h"

S* Origin(S* s)
{
	s = (S*)malloc(sizeof(S));
	if (s == NULL)
	{
		printf("malloc false\n");
		exit(0);
	}
	(s)->data = NULL;
	(s)->capacity = (s)->total = 0;

	return s;
}

void Expansion(S* s)
{
	int newspace = s->total == 0 ? 4 : s->total * 2;
	int* tmp = (int*)realloc(s->data, newspace * sizeof(int));
	if (tmp == NULL)
	{
		printf("expansion false\n");
		exit(0);
	}
	s->total = newspace;
	s->data = tmp;
}

void PushBack(S* s, int x)
{
	if (s->capacity == s->total)
	{
		Expansion(s);
	}
	s->data[s->capacity] = x;
	s->capacity++;
}

void PushFront(S* s, int x)
{
	if (s->capacity == s->total)
	{
		Expansion(s);
	}
	EveryInsert(s, 0, x);
}

void PopBack(S* s)
{
	assert(s->capacity);

	s->capacity--;
}

void PopFront(S* s)
{
	EveryDelete(s, 0);
}

int Chack(S* s, int x, int pos)
{
	int i;
	for (i = pos; i < s->capacity; i++)
	{
		if (s->data[i] == x)
			return i;
	}
	return i;
}


void Change(S* s, int pos, int y)
{
	//想法一：将值为x修改为y.
	/*int pos;
	pos = Chack(s, x, 0);
	s->data[pos] = y;*/
	
	//想法二：将位置为x的值修改为y.
	if (pos < s->capacity)
	{
		s->data[pos] = y;
	}
}

void EveryInsert(S* s, int pos, int y)
{
	if (s->capacity == s->total)
	{
		Expansion(s);
	}

	for (int i = s->capacity; i >= pos; i--)
	{
		s->data[i + 1] = s->data[i];
	}
	s->data[pos] = y;
	s->capacity++;
}

void EveryDelete(S* s, int pos)
{
	assert(s->capacity);

	for (int i = pos; i < s->capacity - 1; i++)
	{
		s->data[i] = s->data[i + 1];
	}

	s->capacity--;
}

void Prin(S* s)
{
	for (int i = 0; i < s->capacity; i++)
	{
		printf("%d ", s->data[i]);
	}
	printf("\n");
}

S* Destroy(S* s)
{
	free(s->data);
	s->data = NULL;
	free(s);
	return NULL;
}