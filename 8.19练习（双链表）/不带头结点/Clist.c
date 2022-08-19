#include "Clist.h"

S* Expansion(int x)
{
	S* newnode = (S*)malloc(sizeof(S));
	if (newnode == NULL)
	{
		printf("malloc false\n");
		exit(0);
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

S* PushBack(S* s, int x)
{
	if (s == NULL)
	{
		s = Expansion(x);
		s->next = s;
		s->prev = s;
	}
	else
	{
		S* tail = s->prev;
		S* new = Expansion(x);
		tail->next = new;
		new->prev = tail;
		s->prev = new;
		new->next = s;
	}

	return s;
}

S* PushFront(S* s, int x)
{
	if (s == NULL)
	{
		s = Expansion(x);
		s->next = s;
		s->prev = s;
	}
	else
	{
		S* cur = s;
		S* tail = s->prev;
		s = Expansion(x);
		cur->prev = s;
		s->next = cur;
		tail->next = s;
		s->prev = tail;
	}

	return s;
}

S* PopBack(S* s)
{
	assert(s);
	
	S* tail = s->prev;
	S* prev = tail->prev;

	if (tail == s)
	{
		free(s);
		s = NULL;
	}
	else
	{

		free(tail);
		prev->next = s;
		s->prev = prev;
	}

	return s;
}

S* PopFront(S* s)
{
	assert(s);

	S* tail = s->prev;
	S* next = s->next;

	if (tail == s)
	{
		free(s);
		next = NULL;
	}
	else
	{
		free(s);
		tail->next = next;
		next->prev = tail;
	}

	return next;
}

S* Insert(S* s, S* pos, int x)
{
	if (pos == s->prev)
	{
		PushBack(pos->next, x);
	}
	else
	{
		S* next = pos->next;
		S* new = Expansion(x);
		pos->next = new;
		new->prev = pos;
		new->next = next;
		next->prev = new;
	}

	return s;
}

S* Delete(S* s, S* pos)
{
	if (pos == s)
	{
		s = PopFront(pos);
	}
	else if(pos == s->prev)
	{
		s = PopBack(s);
	}
	else
	{
		S* prev = pos->prev;
		S* next = pos->next;

		free(pos);
		prev->next = next;
		next->prev = prev;
	}

	return s;
}

S* Chack(S* s, S* pos, int x)
{
	assert(pos);

	S* cur = pos;
	do
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	} while (cur != s);

	return NULL;
}

void Print(S* s)
{
	S* cur = s;
	do
	{
		printf("%d->", cur->data);
		cur = cur->next;
	} while (/*cur && */cur != s);
	/*if (cur)
	{
		printf("%d->", cur->data);
	}*/
	printf("NULL\n");
}

S* Destroy(S* s)
{
	do
	{
		S* prev = s->prev;
		S* next = s->next;
		free(s);
		prev->next = next;
		next->prev = prev;
		s = next;
	} while (s->next != s);
	free(s);

	return NULL;
}