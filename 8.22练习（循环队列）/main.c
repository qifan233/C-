#include "Cqueue.h"

void main()
{
	QNode* queue = NULL;
	queue = Origin(queue, 5);

	QNode* top = queue;
	QNode* tail = queue;


	PushBack(&top, &tail, 1);
	PushBack(&top, &tail, 2);
	PushBack(&top, &tail, 3);
	PushBack(&top, &tail, 4);
	PushBack(&top, &tail, 4);
	//PushBack(&top, &tail, 4);

	PopFront(&top, &tail);
	PopFront(&top, &tail);
	PopFront(&top, &tail);
	PopFront(&top, &tail);
	PopFront(&top, &tail);
	//PopFront(&top, &tail);

	if (!QueueEmpty(top, tail))
	{
		printf("%d\n", QueueBack(top, tail));
		printf("%d\n", QueueFront(top, tail));
	}
	else
	{
		printf("This queue has not data\n");
	}
	printf("%d\n", QueueSize(top, tail));

	Prin(top, tail);

	queue = Destroy(queue);
	printf("%p\n", queue);
}