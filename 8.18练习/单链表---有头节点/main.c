#include "Slist.h"

void main()
{
	S* list = NULL;
	list = PushBack(list, 1);
	list = PushBack(list, 2);
	list = PushBack(list, 3);
	list = PushBack(list, 4);

	/*list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);*/

	/*list = PopFront(list);
	list = PopFront(list);
	list = PopFront(list);
	list = PopFront(list);
	list = PopFront(list);*/

	/*list = PushFront(list, 1);
	list = PushFront(list, 2);
	list = PushFront(list, 3);
	list = PushFront(list, 4);*/


	//重复数据查找
	/*S* pos = list;
	while (pos)
	{
		if (pos = Chack(pos, 1))
		{
			printf("%d\n", pos->data);
			pos = pos->next;
		}
	}*/
	/*S* pos = list;
	pos = Chack(pos, 1);
	if (pos)
	{
		list = PopEvery(list, pos);
	}*/


	Prin(list);

	list = Destroy(list);
	printf("%p\n", list);
}