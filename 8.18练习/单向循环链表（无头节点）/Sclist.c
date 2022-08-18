#include "Sclist.h"

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
		list->next = list;
	}
	else
	{
		S* cur = list;
		while (cur->next != list)
		{
			cur = cur->next;
		}
		cur->next = Expansion(x);
		cur->next->next = list;
	}

	return list;
}

S* PushFront(S* list, int x)
{
	if (list == NULL)
	{
		list = Expansion(x);
		list->next = list;
	}
	else
	{
		S* cur = list;
		S* tail = list;
		while (tail->next != list)
		{
			tail = tail->next;
		}
		list = Expansion(x);
		list->next = cur;
		tail->next = list;
	}

	return list;
}

//当前位置往后插
S* PushEvery(S* list, S* pos, int x)
{
	S* cur = pos->next;
	pos->next = Expansion(x);
	pos->next->next = cur;
	return list;
}

S* PopBack(S* list)
{
	assert(list);

	if (list->next != list)
	{
		S* cur = list;
		S* pre = cur;

		while (cur->next != list)
		{
			pre = cur;
			cur = cur->next;
		}

		pre->next = cur->next;
		free(cur);
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

	if (list->next != list)
	{
		S* cur = list->next;
		S* tail = list;
		while (tail->next != list)
		{
			tail = tail->next;
		}
		free(list);
		list = cur;
		tail->next = list;
		
		return list;
	}
	else
	{
		free(list);
		return NULL;
	}
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

		pre->next = pos->next;
		free(pos);
	}
	else
	{
		list = PopFront(list);
	}

	return list;
}

S* Chack(S* list, S* pos, int x)
{
	S* cur = pos;
	while (cur->next != list)
	{
		if (cur->data != x)
		{
			cur = cur->next;
		}
		else
		{
			return cur;
		}
	}
	if (cur->data == x)
	{
		return cur;
	}

	return NULL;
}

void Prin(S* list)
{
	if (list)
	{
		S* cur = list;
		while (cur->next != list)
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
}

S* Destroy(S* list)
{
	S* tail = list;
	while (tail->next != list)
	{
		tail = tail->next;
	}

	while (list->next != list)
	{
		S* cur = list->next;
		free(list);
		list = cur;
		tail->next = list;
	}

	free(list);
	return NULL;
}