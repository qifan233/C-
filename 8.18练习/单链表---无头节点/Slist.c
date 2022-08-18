#include "Slist.h"

S* Origin(S* list)
{
	list = (S*)malloc(sizeof(S));

	if (list == NULL)
	{
		printf("malloc flase\n");
		exit(0);
	}
	list->next = NULL;

	return list;
}

S* Expansion(int x)
{
	S* newnode = (S*)malloc(sizeof(S));

	if (newnode == NULL)
	{
		printf("malloc false\n");
		exit(0);
	}
	newnode->next = NULL;
	newnode->data = x;

	return newnode;
}

void PushBack(S* list, int x)
{
	S* cur = list;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->next = Expansion(x);
}

void PushFront(S* list, int x)
{
	/*S* cur = list->next;

	list->next = Expansion(x);
	list->next->next = cur;*/

	PushEvery(list, x);
}

void PushEvery(S* pos, int x)
{
	S* cur = pos->next;
	pos->next = Expansion(x);

	pos->next->next = cur;
}

void PopBack(S* list)
{
	assert(list->next != NULL);

	S* cur = list->next;
	S* pre = list->next;

	while (cur->next != NULL)
	{
		pre = cur;
		cur = cur->next;
	}

	free(cur);
	pre->next = NULL;
}

void PopFront(S* list)
{
	assert(list->next != NULL);
	S* cur = list->next->next;

	free(list->next);
	list->next = cur;
}

void PopEvery(S* list, S* pos)
{
	S* cur = pos->next;
	S* pre = list;

	while (pre->next != pos)
	{
		pre = pre->next;
	}

	free(pos);
	pre->next = cur;
}

S* Chack(S* list, int x)
{
	while (list)
	{
		if (list->data == x)
			return list;
		list = list->next;
	}

	return NULL;
}

void Prin(S* list)
{
	assert(list != NULL);

	S* cur = list->next;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}