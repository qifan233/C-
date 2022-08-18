#include "Sclist.h"

void main()
{
	S* list = NULL;
	/*list = PushBack(list, 1);
	list = PushBack(list, 2);
	list = PushBack(list, 3);
	list = PushBack(list, 4);*/

	/*list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);*/
	//list = PopBack(list);

	/*list = PopFront(list);
	list = PopFront(list);
	list = PopFront(list);
	list = PopFront(list);*/
	//list = PopFront(list);

	/*list = PushFront(list, 5);
	list = PushFront(list, 1);
	list = PushFront(list, 5);
	list = PushFront(list, 5);*/

	list = PushBack(list, 1);
	list = PushBack(list, 5);
	list = PushBack(list, 1);
	list = PushBack(list, 1);


	//重复数据查找
	S* pos = list->next;
	/*while (pos && pos != list)
	{*/
		if (pos = Chack(list, pos, 1))
		{
			printf("%d\n", pos->data);
			pos = pos->next;
		}
	//}
	if(!pos && pos == list)
	{
		printf("没找到\n");
	}
	//S* pos = list;
	//pos = Chack(list, pos, 5);
	//if (pos)
	//{
	//	//list = PushEvery(list, pos, 10);
	//	list = PopEvery(list, pos);
	//}


	Prin(list);

	list = Destroy(list);
	printf("%p\n", list);
}