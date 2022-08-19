#include "Clist.h"

void main()
{
	S* list = NULL;
	list = PushBack(list, 1);
	list = PushBack(list, 2);
	list = PushBack(list, 2);
	list = PushBack(list, 4);

	/*list = PushFront(list, 1); 
	list = PushFront(list, 1); 
	list = PushFront(list, 1);
	list = PushFront(list, 1);*/

	S* pos = list;
	//pos = Chack(list, pos, 2);
	//list = Insert(list, pos, 10);
	//list = Delete(list, pos);
	do
	{
		pos = Chack(list, pos, 4);
		if (pos)
		{
			printf("%d\n", pos->data);
			pos = pos->next;
		}
		else if(pos == list)
		{
			printf("√ª’“µΩ\n");
		}
	} while (pos && pos != list);

	/*list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);
	list = PopBack(list);*/

	//list = PopFront(list);
	//list = PopFront(list);
	//list = PopFront(list);
	//list = PopFront(list);
	//list = PopFront(list);

	//Print(list);
	list = Destroy(list);
	printf("%p\n", list);
}