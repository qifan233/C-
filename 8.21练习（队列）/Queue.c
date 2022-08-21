#include "Queue.h"

QNode* Origin(QNode* q)
{
	q = (QNode*)malloc(sizeof(QNode));
	if (q == NULL)
	{
		exit(0);
	}
	q->next = NULL;
	q->tail = NULL;

	return q;
}

QNode* Expansion(int x)
{
	QNode* new = (QNode*)malloc(sizeof(QNode));

	if (new == NULL)
	{
		exit(0);
	}
	new->data = x;
	new->next = NULL;

	return new;
}

QNode* Destroy(QNode* q)
{
	QNode* cur = q;

	while (cur != NULL)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	
	return NULL;
}

QNode* PushBack(QNode* q, int x)
{
	if (q == NULL)
	{
		q = Expansion(x);
		q->tail = q;
	}
	else
	{
		QNode* new = Expansion(x);
		q->tail = q->tail->next = new;
	}

	return q;
}

QNode* PopFront(QNode* q)
{
	assert(q);

	QNode* next = q->next;
	if (next != NULL)
	{
		free(q);
		q = next;
	}
	else
	{
		free(q);
		q = NULL;
	}

	return q;

}

int QueueFront(QNode* q)
{
	return q->data;
}

int QueueBack(QNode* q)
{
	return q->tail->data;
}
int QueueSize(QNode* q)
{
	int size = 0;
	QNode* tail = q;
	while (tail != NULL)
	{
		size++;
		tail = tail->next;
	}

	return size;
}
bool QueueEmpty(QNode* q)
{
	if (q == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}