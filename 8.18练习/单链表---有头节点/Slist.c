#include "Slist.h"

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

	return newnode;
}

S* PushBack(S* list, int x)
{
	if (list == NULL)
	{
		list = Expansion(x);
	}
	else
	{
		S* cur = list;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = Expansion(x);
	}

	return list;
}

S* PushFront(S* list, int x)
{
	if (list == NULL)
	{
		list = Expansion(x);
	}
	else
	{
		S* cur = list;
		list = Expansion(x);
		list->next = cur;
	}

	return list;
}

//当前位置往后插
S* PushEvery(S* pos, int x)
{
	S* cur = pos->next;
	pos->next = Expansion(x);
	pos->next->next = cur;
	return pos;
}

S* PopBack(S* list)
{
	assert(list);

	if (list->next)
	{
		S* cur = list;
		S* pre = cur;

		while (cur->next)
		{
			pre = cur;
			cur = cur->next;
		}

		free(cur);
		pre->next = NULL;
		return list;
	}
	else
	{
		free(list);
		return NULL;
	}
}

S* PopFront(S* list)
{
	assert(list);
	S* cur = list->next;
	free(list);
	list = cur;
	return list;
}

S* PopEvery(S* list, S* pos)
{
	if (list != pos)
	{
		S* cur = list;
		S* pre = cur;

		while (cur != pos)
		{
			pre = cur;
			cur = cur->next;
		}

		pre = pos->next;
		free(pos);
	}
	else
	{
		list = pos->next;
		free(pos);
	}

	return list;
}

S* Chack(S* pos, int x)
{
	S* cur = pos;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

void Prin(S* list)
{
	S* cur = list;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

S* Destroy(S* list)
{
	while (list)
	{
		S* cur = list->next;
		free(list);
		list = cur;
	}

	return NULL;
}