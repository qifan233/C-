#include "Stack.h"

void main()
{
	ST* stack = NULL;
	stack = Origin(stack);

	StackPush(stack, 1);
	StackPush(stack, 2);
	//StackPush(stack, 3);
	StackPush(stack, 4);

	/*StackPop(stack);
	StackPop(stack);
	StackPop(stack);
	StackPop(stack);
	StackPop(stack);*/
	printf("%d\n", StackTop(stack));
	printf("%d\n", StackSize(stack));

	Prin(stack);
	stack = Destroy(stack);
	printf("%p", stack);
}