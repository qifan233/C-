#include "function.h"

void Function(STU* stu)
{
	while (1)
	{
		int button;
		Menu();
		printf("��ѡ��Ҫִ�еĹ���:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			printf("���˳�ѧ����Ϣ����ϵͳ\n");
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
			printf("ѡ�����������ѡ��\n");
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