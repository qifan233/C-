#include "Stack.h"

ST* Origin(ST* s)
{
	s = (ST*)malloc(sizeof(ST));
	if (s == NULL)
	{
		printf("malloc false\n");
		exit(0);
	}
	s->next = NULL;
	s->data = 0;
	return s;
}
ST* Destroy(ST* s)
{
	assert(s->next != NULL);

	ST* cur = s->next;
	while (cur != NULL)
	{
		ST* next = cur->next;
		free(cur);
		s->next = next;
		cur = next;
	}
	free(s);
	return NULL;
}
void StackPush(ST* s, int x)
{
	ST* newnode = (ST*)malloc(sizeof(ST));
	if (newnode == NULL)
	{
		printf("malloc false\n");
	}
	else
	{

		newnode->data = x;
		ST* next = s->next;
		s->next = newnode;
		newnode->next = next;
		s->data++;
	}
}

void StackPop(ST* s)
{
	assert(s->next != NULL);

	ST* next = s->next->next;
	free(s->next);
	s->next = next;
	s->data--;
}

int StackTop(ST* s)
{
	return s->next->data;
}

int StackSize(ST* s)
{
	return s->data;
}

bool StackEmtpy(ST* s)
{
	if (s->data == 0)
		return true;
	else
		return false;
}

void Prin(ST* s)
{
	ST* cur = s->next;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}