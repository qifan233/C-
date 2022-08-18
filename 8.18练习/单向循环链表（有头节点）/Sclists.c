#include "Sclist.h"


//带头节点
S* Origin(S* list)
{
	list = (S*)malloc(sizeof(S));

	if (list == NULL)
	{
		printf("malloc flase\n");
		exit(0);
	}
	list->next = list;

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
	S* cur = list->next;

	while (cur->next != list->next)
	{
		cur = cur->next;
	}

	cur->next = Expansion(x);
	cur->next->next = list->next;
}

void PushFront(S* list, int x)
{
	S* cur = list->next;
	S* tail = list->next;
	while (tail->next != list->next)
	{
		tail = tail->next;
	}

	list->next = Expansion(x);
	list->next->next = cur;
	tail->next = list->next;
}

void PushEvery(S* list, S* pos, int x)
{
	S* tail = list->next;
	while (tail->next != list->next)
	{
		tail = tail->next;
	}
	if (tail == pos)
	{
		PushBack(list, x);
	}
	else
	{
		S* cur = pos->next;
		pos->next = Expansion(x);

		pos->next->next = cur;
	}
}

void PopBack(S* list)
{
	assert(list->next != NULL);

	S* cur = list->next;

	if (cur->next != list->next)
	{
		S* pre = list->next;
		while (cur->next != list->next)
		{
			pre = cur;
			cur = cur->next;
		}

		free(cur);
		pre->next = list->next;
	}
	else
	{
		free(cur);
		list->next = list;
	}
}

void PopFront(S* list)
{
	assert(list->next != NULL);
	S* cur = list->next;
	if (cur->next != list->next)
	{
		S* next = cur->next;
		S* tail = list->next;
		while (tail->next != list->next)
		{
			tail = tail->next;
		}

		free(cur);
		list->next = next;
		tail->next = list->next;
	}
	else
	{
		free(list->next);
		list->next = list;
	}
}

void PopEvery(S* list, S* pos)
{
	assert(list);
	if (pos == list->next)
	{
		PopFront(list);
	}
	else
	{
		S* cur = pos->next;
		S* pre = list->next;

		while (pre->next != pos)
		{
			pre = pre->next;
		}

		free(pos);
		pre->next = cur;
	}
}

S* Chack(S* list, S* pos, int x)
{
	S* cur = pos;
	while (cur->next != list)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	if (cur->data == x)
		return cur;
	else
		return NULL;
}

void Prin(S* list)
{
	assert(list != NULL);

	if (list->next != list)
	{
		S* cur = list->next;
		while (cur->next != list->next)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("%d->NULL\n", cur->data);
	}
	else
	{
		printf("NULL\n");
	}

	/*S* cur = list->next;
	while (cur->next != list)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");*/
}

S* Destroy(S* list)
{
	S* cur = list->next;
	S* tail = list->next;
	while (tail->next != list->next)
	{
		tail = tail->next;
	}

	while (cur->next != list->next)
	{
		S* next = cur->next;
		free(cur);
		cur = next;
		tail->next = next;
		list->next = next;
	}
	free(list->next);
	list->next = list;
	free(list);
	return NULL;
}