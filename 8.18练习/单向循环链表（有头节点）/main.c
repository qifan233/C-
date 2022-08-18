#include "Sclist.h"

void main()
{
	S* list = NULL;
	list = Origin(list);

	PushBack(list, 1);
	PushBack(list, 1);
	PushBack(list, 3);
	PushBack(list, 1);

	/*PushFront(list, 1);*/
	//PushFront(list, 2);
	//PushFront(list, 3);
	//PushFront(list, 4);

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


	//查找重复数据
	S* cur = list->next;

	/*while (cur && cur != list->next)
	{*/
		if (cur = Chack(list->next, cur, 1))
		{
			printf("%d\n", cur->data);
			cur = cur->next;
		}
	//}

	//S* pos = Chack(list, list->next, 2);
	//if (pos)
	//{
	//	//PushEvery(list, pos, 10);
	//	PopEvery(list, pos);
	//}
	//else
	//{
	//	printf("没找到\n");
	//}

	Prin(list);
	list = Destroy(list);
	printf("%p\n", list);
}