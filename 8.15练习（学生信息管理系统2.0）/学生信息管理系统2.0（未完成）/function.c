#include "function.h"

//主菜单
void Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                   学生信息管理系统                  |\n");
	printf("                                |                1.查询           2.排序              |\n");
	printf("                                |                3.添加           4.删除              |\n");
	printf("                                |                5.修改           6.性别分类          |\n");
	printf("                                |                        0.退出                       |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//查询菜单
void Chack_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                       查询方式                      |\n");
	printf("                                |                    1.按姓名查询                     |\n");
	printf("                                |                    2.按学号查询                     |\n");
	printf("                                |                    3.查询所有信息                   |\n");
	printf("                                |                    0.返回                           |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//排序菜单
void Sort_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                       排序方式                      |\n");
	printf("                                |                    1.按入学成绩升序                 |\n");
	printf("                                |                    2.按入学成绩降序                 |\n");
	printf("                                |                    3.按姓名升序                     |\n");
	printf("                                |                    4.按姓名降序                     |\n");
	printf("                                |                    0.返回                           |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//删除菜单
void Del_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                       删除方式                      |\n");
	printf("                                |                    1.学生姓名                       |\n");
	printf("                                |                    2.学生学号                       |\n");
	printf("                                |                    0.返回                           |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//修改菜单
void Change_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                         修改方式                    |\n");
	printf("                                |                    1.学号      2.姓名               |\n");
	printf("                                |                    3.性别      4.籍贯               |\n");
	printf("                                |                    5.出生年月  6.电话               |\n");
	printf("                                |                    7.入学成绩  0.返回               |\n");
	printf("                                |-----------------------------------------------------|\n");
}



//初始化
void Origin(STU* stu)
{
	stu->quantity = stu->total = 0;
	stu->stum = NULL;
}

void Expansion(STU* stu)
{
	if (stu->quantity == stu->total)
	{
		int newtotal = stu->total == 0 ? 4 : stu->total * 2;
		StuM* tmp = (StuM*)realloc(stu->stum, newtotal * sizeof(StuM));
		if (tmp == NULL)
		{
			printf("扩容失败.\n");
			exit(0);
		}
		stu->total = newtotal;
		stu->stum = tmp;
	}
}

void FileRead(STU* stu)
{
	FILE* fp = fopen("JK62107.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}

	//读取数据
	fgets(stu->title, 100, fp);
	while (!feof(fp))
	{
		Expansion(stu);
		fscanf(fp, "%s %s %s %s %s %s %d",
			stu->stum[stu->quantity].num, stu->stum[stu->quantity].name, stu->stum[stu->quantity].sex,
			stu->stum[stu->quantity].year, stu->stum[stu->quantity].address, stu->stum[stu->quantity].tel, &stu->stum[stu->quantity].grades);
		stu->quantity++;
	}
	fclose(fp);
}

void FileWrite(STU* stu)
{
	SortNum(stu);

	FILE* fp = fopen("JK62107.txt", "w");
	fputs(stu->title, fp);
	for (int i = 0; i < stu->quantity; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s %d", stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex,
			stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel, stu->stum[i].grades);
		if (i != stu->quantity - 1)
			fprintf(fp, "\n");
	}

	fclose(fp);
	printf("信息更新成功\n");
}

//查询功能
void ChackFunction(STU* stu) 
{
	while (1)
	{
		int button;
		Chack_Menu();
		printf("选择要执行的功能:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			system("cls");
			printf("已返回\n");
			return;
			break;

		case Chack_Name:
			ChackName(stu);
			Return();
			break;

		case Chack_Num:
			ChackNum(stu);
			Return();
			break;

		case Chack_All:
			ChackAll(stu);
			Return();
			break;

		default:
			system("cls");
			printf("选择错误，请重新选择\n");
		}
	}
}

char* ChackName(STU* stu)
{
	int i, flag;
	int first;
	char find_name[10] = {0};
	first = flag = 0;

	printf("请输入要查找的学生姓名:");
	scanf("%s", find_name);

	printf("\n\n%s", stu->title);
	for (i = 0; i < stu->quantity; i++)
	{
		if (strcmp(find_name, stu->stum[i].name) == 0)
		{
			flag = 1;
			printf("%s %s %s %s %s %s %d\n",
				stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
				stu->stum[i].grades);

			StuM tmp = stu->stum[i];
			stu->stum[i] = stu->stum[first];
			stu->stum[first] = tmp;
			first++;
		}
	}
	if (!flag)
	{
		printf("\033[1A找不到当前学生信息                                                                      \n");
		return NULL;
	}

	return find_name;
}

char* ChackNum(STU* stu)
{
	int i, flag = 0;
	char find_num[10] = { 0 };
	printf("请输入要查找的学生学号:");
	scanf("%s", find_num);

	printf("\n\n%s", stu->title);
	for (i = 0; i < stu->quantity; i++)
	{
		if (strcmp(find_num, stu->stum[i].num) == 0)
		{
			flag = 1;
			printf("%s %s %s %s %s %s %d\n",
				stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
				stu->stum[i].grades);
			StuM tmp = stu->stum[i];
			stu->stum[i] = stu->stum[0];
			stu->stum[0] = tmp;
			break;
		}
	}
	if (!flag)
	{
		printf("\033[1A找不到当前学生信息                                                                      \n");
		return find_num;
	}
	return NULL;
}

void ChackAll(STU* stu)
{
	SortNum(stu);
	int i = 0;
	printf("%s", stu->title);
	while (i < stu->quantity)
	{
		printf("%s\t %s   %-5s\t%s\t%-9s %10s %13d\n",
			stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
			stu->stum[i].grades);
		i++;
	}
}

//排序功能
void SortFunction(STU* stu)
{
	while (1)
	{
		int button;
		Sort_Menu();
		printf("选择要执行的功能:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			system("cls");
			printf("已返回\n");
			return;
			break;

		case Sort_Grades_Up:
			SortGradesUp(stu);
			Return();
			break;

		case Sort_Grades_Down:
			SortGradesDown(stu);
			Return();
			break;

		case Sort_Name_Up:
			SortNameUp(stu);
			Return();
			break;

		case Sort_Name_Down:
			SortNameDown(stu);
			Return();
			break;

		default:
			system("cls");
			printf("选择错误，请重新选择\n");
		}
	}
}

void SortGradesUp(STU* stu)
{
	for (int i = 0; i < stu->quantity; i++)
	{
		int min = i;
		for (int j = i; j < stu->quantity; j++)
		{
			if (stu->stum[j].grades < stu->stum[min].grades)
			{
				min = j;
			}
		}
		StuM tmp = stu->stum[i];
		stu->stum[i] = stu->stum[min];
		stu->stum[min] = tmp;
	}
	printf("排序结果：\n");
	ChackAll(stu);
}

void SortGradesDown(STU* stu)
{
	for (int i = 0; i < stu->quantity; i++)
	{
		int max = i;
		for (int j = i; j < stu->quantity; j++)
		{
			if (stu->stum[j].grades > stu->stum[max].grades)
			{
				max = j;
			}
		}
		StuM tmp = stu->stum[i];
		stu->stum[i] = stu->stum[max];
		stu->stum[max] = tmp;
	}
	printf("排序结果：\n");
	ChackAll(stu);
}

void SortNameUp(STU* stu)
{
	for (int i = 0; i < stu->quantity; i++)
	{
		int min = i;
		for (int j = i; j < stu->quantity; j++)
		{
			if (strcmp(stu->stum[min].name, stu->stum[j].name) > 0)
			{
				min = j;
			}
		}
		StuM tmp = stu->stum[i];
		stu->stum[i] = stu->stum[min];
		stu->stum[min] = tmp;
	}
	printf("排序结果：\n");
	ChackAll(stu);
}

void SortNameDown(STU* stu)
{
	for (int i = 0; i < stu->quantity; i++)
	{
		int max = i;
		for (int j = i; j < stu->quantity; j++)
		{
			if (strcmp(stu->stum[max].name, stu->stum[j].name) < 0)
			{
				max = j;
			}
		}
		StuM tmp = stu->stum[i];
		stu->stum[i] = stu->stum[max];
		stu->stum[max] = tmp;
	}
	printf("排序结果：\n");
	ChackAll(stu);
}

void SortNum(STU* stu)
{
	for (int i = 0; i < stu->quantity; i++)
	{
		int min = i;
		for (int j = i; j < stu->quantity; j++)
		{
			if (strcmp(stu->stum[min].num, stu->stum[j].num) > 0)
			{
				min = j;
			}
		}
		StuM tmp = stu->stum[i];
		stu->stum[i] = stu->stum[min];
		stu->stum[min] = tmp;
	}
}

//增添功能
void AddFunction(STU* stu)
{
	char* num = ChackNum(stu);

	if (num)
	{
		Expansion(stu);
		strcpy(stu->stum[stu->quantity].num, num);
		printf("\033[1A 增添学号为%s的学生信息，依次输入以下信息(用空格隔开)：\n", stu->stum[stu->quantity].num);
		printf("姓名 性别 出生年月 籍贯 电话 入学成绩\n");
		scanf("%s %s %s %s %s %d", stu->stum[stu->quantity].name, stu->stum[stu->quantity].sex, stu->stum[stu->quantity].year,
			stu->stum[stu->quantity].address, stu->stum[stu->quantity].tel, &stu->stum[stu->quantity].grades);
		stu->quantity++;
		FileWrite(stu);
	}

	Return();
}

//删除功能
void DelFunction(STU* stu)
{
	while (1)
	{
		int button;
		Del_Menu();
		printf("选择要执行的功能:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			system("cls");
			printf("已返回\n");
			return;
			break;

		case Del_Name:
			DelName(stu);
			Return();
			break;

		case Del_Num:
			DelNum(stu);
			Return();
			break;

		default:
			system("cls");
			printf("选择错误，请重新选择\n");
		}
	}
}

void DelName(STU* stu)
{
	if (ChackName(stu))
	{
		printf("\n\n请选择要删除的学生信息：");
		int n = 0;
		scanf("%d", &n);
		printf("%s", stu->title);
		printf("%s %s %s %s %s %s %d\n",
			stu->stum[n - 1].num, stu->stum[n - 1].name, stu->stum[n - 1].sex, stu->stum[n - 1].year,
			stu->stum[n - 1].address, stu->stum[n - 1].tel, stu->stum[n - 1].grades);
		printf("是否确认删除y\\n");
		getchar();
		char x = getchar();
		if (x == 'y')
		{
			stu->stum[n - 1] = stu->stum[stu->quantity - 1];
			stu->quantity--;
			FileWrite(stu);
		}
		else
		{
			printf("删除失败\n");
		}
	}
}

void DelNum(STU* stu)
{
	if (!ChackNum(stu))
	{
		printf("是否确认删除y\\n：");
		getchar();
		char x = getchar();
		if (x == 'y')
		{
			stu->stum[0] = stu->stum[stu->quantity - 1];
			stu->quantity--;
			FileWrite(stu);
		}
		else
		{
			printf("删除失败\n");
		}
	}
}

//修改功能
void ChangeFunction(STU* stu)
{
	if (!ChackNum(stu))
	{
		printf("是否要修改信息y\\n：");
		getchar();
		char x = getchar();
		if (x == 'y')
		{
			int n = 1;
			system("cls");
			do
			{
				printf("%s", stu->title);
				printf("%s %s %s %s %s %s %d\n",
					stu->stum[0].num, stu->stum[0].name, stu->stum[0].sex, stu->stum[0].year, stu->stum[0].address, stu->stum[0].tel,
					stu->stum[0].grades);

				Change_Menu();
				printf("请选择要修改的信息：");

				scanf("%d", &n);
				switch (n)
				{
				case 0:
					printf("已返回\n");
					break;

				case 1:
					printf("学号：");
					scanf("%s", stu->stum[0].num);
					system("cls");
					printf("修改成功\n");
					break;

				case 2:
					printf("姓名：");
					scanf("%s", stu->stum[0].name);
					system("cls");
					printf("修改成功\n");
					break;

				case 3:
					printf("性别：");
					scanf("%s", stu->stum[0].sex);
					system("cls");
					printf("修改成功\n");
					break;

				case 4:
					printf("籍贯：");
					scanf("%s", stu->stum[0].address);
					system("cls");
					printf("修改成功\n");
					break;

				case 5:
					printf("出生年月：");
					scanf("%s", stu->stum[0].year);
					system("cls");
					printf("修改成功\n");
					break;

				case 6:
					printf("电话：");
					scanf("%s", stu->stum[0].tel);
					system("cls");
					printf("修改成功\n");
					break;

				case 7 :
					printf("入学成绩：");
					scanf("%d", &stu->stum[0].grades);
					system("cls");
					printf("修改成功\n");
					break;

				default:
					system("cls");
					printf("选择错误，请重新选择。");
				}
			} while(n);
		}
	}
}

//性别分类
void SexSortFunction(STU* stu)
{
	SortNum(stu);
	for (int i = 0; i < stu->quantity; i++)
	{
		//if (strcmp(stu->stum[i].sex, "男") == 0)//将男女分开排序
		//	swap++;
		//else
		//{
		//	int j;//临时循环变量
		//	for (j = i + 1; j < total; j++)
		//		if (strcmp(stu[j].sex, "男") == 0)
		//		{
		//			STU tmp = stu[i];
		//			stu[i] = stu[j];
		//			stu[j] = tmp;
		//			swap++;
		//			break;
		//		}
		//}
	}
}

//返回
void Return()
{
	printf("\n任意键返回\n");
	_getch();
	system("cls");
}