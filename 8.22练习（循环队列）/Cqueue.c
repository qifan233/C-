#include "Cqueue.h"

QNode* Origin(QNode* q, int x)
{
	int i = 0;

	q = (QNode*)malloc(sizeof(QNode));
	if (q == NULL)
	{
		exit(0);
	}

	QNode* cur = q;

	while (i < x)
	{
		QNode* new = (QNode*)malloc(sizeof(QNode));
		if (new == NULL)
		{
			exit(0);
		}
		cur->next = new;
		cur = cur->next;
		i++;
	}
	cur->next = q;

	return q;
}

QNode* Destroy(QNode* q)
{
	QNode* cur = q->next;
	while (cur != q)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	free(q);
	return NULL;
}

void PushBack(QNode** top, QNode** tail, int x)
{
	/*if (tail->next == top)
	{
		printf("This queue is full\n");
	}
	else
	{
		tail->data = x;
		tail = tail->next;
	}*/
	assert((*tail)->next != *top);

	(*tail)->data = x;
	(*tail) = (*tail)->next;
}

void PopFront(QNode** top, QNode** tail)
{
	/*if (top == tail)
	{
		printf("This queue is empty\n");
	}*/
	assert(*top != *tail);

	*top = (*top)->next;
}

int QueueFront(QNode* top, QNode* tail)
{
	//assert(top != tail);
	return top->data;
}

int QueueBack(QNode* top, QNode* tail)
{
	//assert(top != tail);

	QNode* prev = top;
	while (prev->next != tail)
	{
		prev = prev->next;
	}
	return prev->data;
}

int QueueSize(QNode* top, QNode* tail)
{
	int i = 0;
	while (top != tail)
	{
		i++;
		top = top->next;
	}

	return i;
}

bool QueueEmpty(QNode* top, QNode* tail)
{
	if (top == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Prin(QNode* top, QNode* tail)
{
	QNode* cur = top;
	while (cur != tail)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}