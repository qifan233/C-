#include "Clist.h"

S* Origin(S* s)
{
	s = (S*)malloc(sizeof(S));
	if (s == NULL)
	{
		printf("malloc false\n");
		exit(0);
	}
	s->next = s;
	s->prev = s;

	return s;
}

S* Expansion(int x)
{
	S* newnode = (S*)malloc(sizeof(S));
	if (newnode == NULL)
	{
		printf("malloc false\n");
		exit(0);
	}
	newnode->data = x;

	return newnode;
}

void PushBack(S* s, int x)
{
	Insert(s, s->prev, x);
	/*S* tail = s->prev;
	S* new = Expansion(x);

	tail->next = new;
	new->prev = tail;
	new->next = s;
	s->prev = new;*/
}

void PushFront(S* s, int x)
{
	Insert(s, s, x);
	/*S* next = s->next;
	S* new = Expansion(x);

	s->next = new;
	new->prev = s;
	new->next = next;
	next->prev = new;*/
}

void PopBack(S* s)
{
	assert(s->next != s);
	Delete(s, s->prev);

	/*S* tail = s->prev;
	S* cur = tail->prev;

	free(tail);
	cur->next = s;
	s->prev = cur;*/
}

void PopFront(S* s)
{
	assert(s->next != s);
	Delete(s, s->next);

	/*S* next = s->next->next;
	free(s->next);
	s->next = next;
	next->prev = s;*/
}

S* Chack(S* list, S* pos, int x)
{
	assert(pos->next != pos);

	S* cur = pos;
	do
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	} while (cur != list);

	return NULL;
}

void Insert(S* list, S* pos, int x)
{
	S* next = pos->next;

	S* new = Expansion(x);
	pos->next = new;
	new->prev = pos;
	new->next = next;
	next->prev = new;
}

void Delete(S* list, S* pos)
{
	assert(pos->next != pos);
	S* prev = pos->prev;
	S* next = pos->next;

	free(pos);
	prev->next = next;
	next->prev = prev;
}

void Prin(S* s)
{
	S* cur = s->next;
	while (cur != s)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

S* Destroy(S* s)
{
	S* cur = s->next;
	while (cur != s)
	{
		S* prev = cur->prev;
		S* next = cur->next;

		free(cur);
		prev->next = next;
		next->prev = prev;
		cur = next;
	}
	free(cur);
	return NULL;
}