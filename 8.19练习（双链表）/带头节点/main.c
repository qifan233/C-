#include "Clist.h"

void main()
{
	S* list = NULL;
	list = Origin(list);

	/*PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);*/

	PushFront(list, 1);
	PushFront(list, 2);
	PushFront(list, 3);
	PushFront(list, 4);

	/*PopBack(list);
	PopBack(list);
	PopBack(list);
	PopBack(list);
	PopBack(list);*/

	/*PopFront(list);
	PopFront(list);
	PopFront(list);
	PopFront(list);
	PopFront(list);*/

	/*S* pos = list->next;
	pos = Chack(list, pos, 2);
	Insert(list, pos, 10);*/
	/*do
	{
		pos = Chack(list, pos, 1);
		if (pos)
		{
			printf("%d\n", pos->data);
		}
		else
		{
			break;
		}
		pos = pos->next;
	} while (pos != list);*/

	//Prin(list);
	list = Destroy(list);
	printf("%p\n", list);
}