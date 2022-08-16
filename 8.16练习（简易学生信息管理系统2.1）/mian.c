#include "function.h"

void Function(STU* stu)
{
	while (1)
	{
		int button;
		Menu();
		printf("请选择要执行的功能:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			printf("已退出学生信息管理系统\n");
			return;
			break;

		case Chack:
			system("cls");
			ChackFunction(stu);
			break;

		case Sort:
			system("cls");
			SortFunction(stu);
			break;

		case Add:
			AddFunction(stu);
			Return();
			break;

		case Del:
			system("cls");
			DelFunction(stu);
			break;

		case Change:
			ChangeFunction(stu);
			Return();
			break;

		case SexSort:
			SexSortFunction(stu);
			break;

		default:
			system("cls");
			printf("选择错误，请重新选择。\n");
		}
	}
}

void main()
{
	STU stu;
	Origin(&stu);
	FileRead(&stu);
	Function(&stu);
	//chack1(&stu);
	//ChackNum(&stu);
	Destroy(&stu);
}