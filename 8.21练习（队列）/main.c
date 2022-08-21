#include "Queue.h"

void Prin(QNode* q)
{
	QNode* cur = q;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void main()
{
	QNode* queue = NULL;
	//queue = Origin(queue);

	queue = PushBack(queue, 1);
	queue = PushBack(queue, 2);

	/*queue = PopFront(queue);
	queue = PopFront(queue);*/

	queue = PushBack(queue, 3);
	queue = PushBack(queue, 6);

	printf("%d\n", QueueFront(queue));
	printf("%d\n", QueueBack(queue));
	printf("%d\n", QueueSize(queue));
	
	/*if (QueueEmpty(queue))
	{
		printf("Empty\n");
	}
	else
	{
		printf("Full\n");
	}*/

	Prin(queue);
	queue = Destroy(queue);
	printf("%p\n", queue);
}