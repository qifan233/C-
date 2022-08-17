#include "Slist.h"

void main()
{
	S* list = NULL;
	list =  Origin(list);
	PushBack(list, 1);
	PushBack(list, 2);
	PushBack(list, 3);
	PushBack(list, 4);
	PushBack(list, 5);

	PushFront(list, 6);
	PushFront(list, 7);
	PushFront(list, 8);
	PushFront(list, 9);
	PushFront(list, 10);
	//PushBack(list, 1);

	/*PopBack(list);
	PopBack(list);
	PopBack(list);
	PopBack(list);
	PopBack(list);*/

	PopFront(list);
	PopFront(list);
	PopFront(list);
	PopFront(list);
	PopFront(list);

	//ÕÒÖØ¸´
	/*int p = 0;
	do
	{
		p = Chack(list, 1, p);
		if (p == list->capacity)
		{
			printf("Î´ÕÒµ½\n");
		}
		else
		{
			printf("%d ", p++);
		}
	} while (p != list->capacity);
	printf("\n");*/

	//int pos = Chack(list, 5, 0);
	///*Change(list, pos, 11);*/
	//EveryInsert(list, pos, 12);

	Prin(list);

	list = Destroy(list);
}