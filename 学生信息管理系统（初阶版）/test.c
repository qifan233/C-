#include "test.h"

void menu0()//首页菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    学生信息管理系统    *********\n");
	printf("               *********    1.查询学生信息      *********\n");
	printf("               *********    2.学生信息排序      *********\n");
	printf("               *********    3.添加学生信息      *********\n");
	printf("               *********    4.删除学生信息      *********\n");
	printf("               *********    5.修改学生信息      *********\n");
	printf("               *********    6.按性别分类学生    *********\n");
	printf("               *********    0.退出              *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}
void menu1()//查询菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    1.按姓名查询       **********\n");
	printf("               *********    2.按学号查询       **********\n");
	printf("               *********    3.全部学生信息     **********\n");
	printf("               *********    0.返回首页         **********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}
void menu2()//排序菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    1.按学生姓名排序     ********\n");
	printf("               *********    2.按入学成绩排序     ********\n");
	printf("               *********    0.返回首页           ********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}
void menu3()//删除菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    1.按姓名删除          *******\n");
	printf("               *********    2.按学号删除          *******\n");
	printf("               *********    0.返回首页            *******\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu4()//升降序菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n"); 
	printf("               *********       1.升序           *********\n");
	printf("               *********       2.降序           *********\n");
	printf("               *********       0.返回           *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu5()//修改菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               ******     1. 学号       2.姓名     ******\n"); 
	printf("               ******     3. 性别       4.出生年月 ******\n");
	printf("               ******     5. 籍贯       6. 电话    ******\n");
	printf("               ******     7. 入学成绩   0. 返回    ******\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu6()//输出菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********         1.男生         *********\n");
	printf("               *********         2.女生         *********\n");
	printf("               *********         0.返回         *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu7()//增添菜单
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********      1.新增的学生信息  *********\n");
	printf("               *********      2.所有学生信息    *********\n");
	printf("               *********      0.返回            *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void Fopen()//打开文件并读取文件内容
{
	FILE* fp = fopen("JK0703.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	fgets(title, 100, fp);
	while (!feof(fp))
	{
		fscanf(fp, "%s %s %s %s %s %s %d",
			stu[total].num, stu[total].name, stu[total].sex, stu[total].year, stu[total].address, stu[total].tel, &stu[total].grades);
		total++;
	}
	fclose(fp);
}

void write()//重写文件
{
	FILE* fp = fopen("JK0703.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	fprintf(fp,"%s", title);
	for (i = 0; i < total; i++)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
		if (i != total - 1)
			fprintf(fp, "\n");

	}
	fclose(fp);
	system("cls");
	printf("学生信息已更新。\n");
}

void Return()//返回
{
	char r;//有关返回和操作的临时变量
	printf("\n按任意键返回\n");
	r = _getch();
	system("cls");
}

void prin()//输出所有学生信息
{
	printf("\n%s", title);
	for (i = 0; i < total; i++)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
	}
}


void prinStu()//查找并打印某一学生信息
{
	if (Flag == 1)//输出一个学生信息
	{
		printf("\n%s", title);
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\n\n",
			stu[swap - 1].num, stu[swap - 1].name, stu[swap - 1].sex, stu[swap - 1].year, stu[swap - 1].address, stu[swap - 1].tel, stu[swap - 1].grades);
	}
	else if (Flag > 1)//输出多个学生信息
	{
		printf("\n%s", title);
		for (i = f; i < swap; i++)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
				stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
		}
	}
	else
		printf("找不到该学生信息。\n");
}

void ChackName()//按学生姓名查询
{
	char name[10] = {0};
	i = Flag = swap = f = 0;//变量初始化
	system("cls");
	printf("请输入学生姓名：");
	scanf("%s", name);

	for (i = 0; i < total; i++)//循环查找学生信息
	{
		if (strcmp(name, stu[i].name) == 0)
		{
			STU Tmp = stu[swap];
			stu[swap] = stu[i];
			stu[i] = Tmp;
			Flag++;//判断学生多少
			swap++;//符合条件的最大学生数
		}
	}
}

void ChackNum()//按学生学号查询
{
	i = Flag = swap = 0;//变量初始化
	system("cls");
	printf("请输入学生学号：");
	scanf("%s", num);

	for (i = 0; i < total; i++)//循环查找学生信息
	{
		if (strcmp(num, stu[i].num) == 0)
		{
			Flag = 1;//确保输出一个学生的信息
			swap = i + 1;//将学生信息正确的找到
			break;
		}
	}
}

void AllChack()//显示所有学生信息
{
	SortNum();//按学号排序
	system("cls");
	printf("全部学生信息如下\n\n");
	prin();//输出所有学生信息
	Return();//返回
}

void SortNameUp()//按学生姓名升序排列
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//临时循环变量
		for (j = 0; j < total - 1; j++)
		{
			if (strcmp(stu[j].name, stu[j + 1].name) > 0)
			{
				STU Tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = Tmp;
			}
		}
	}
}

void SortNameDown()//按学生姓名降序排列
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//临时循环变量
		for (j = 0; j < total - 1; j++)
		{
			if (strcmp(stu[j].name, stu[j + 1].name) < 0)
			{
				STU Tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = Tmp;
			}
		}
	}
}

void SortGradesUp()//按学生入学成绩升序
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//临时循环变量
		for (j = 0; j < total - 1 - i; j++)
		{
			if (stu[j].grades > stu[j + 1].grades)
			{
				STU tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
			}
		}
	}
}

void SortGradesDown()//按学生入学成绩降序
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//临时循环变量
		for (j = 0; j < total - 1; j++)
		{
			if (stu[j].grades < stu[j + 1].grades)
			{
				STU tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
			}
		}
	}
}

void SortNum()//按学生学号升序排序
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//临时循环变量
		for (j = 0; j < total - 1 - i; j++)
		{
			if (strcmp(stu[j].num, stu[j + 1].num) > 0)
			{
				STU tmp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = tmp;
			}
		}
	}
}

void AddStu()//增添新的学生信息
{
	char b = 0;//二级菜单功能选择
	i = 0;
	printf("增添学生信息。\n");
	ChackNum();//按学生学号查询，判断是否为新的学生。
	if (Flag)
	{
		printf("该学生信息已存在。\n");
		Return();//返回
	}
	else
	{
		printf("录入新的学生信息：\n");
		printf("姓名：");
		scanf("%s", stu[total].name);
		printf("性别：");
		scanf("%s", stu[total].sex);
		printf("出生年月：");
		scanf("%s", stu[total].year);
		printf("籍贯：");
		scanf("%s", stu[total].address);
		printf("电话号码：");
		scanf("%s", stu[total].tel);
		printf("入学成绩：");
		scanf("%d", &stu[total].grades);
		strcpy(stu[total].num, num);
		total++;
		SortNum();//按学号排序
		write();//将文件重写
		do
		{
			menu7();//增添菜单
			printf("选择要查看的信息\n");
			b = _getch();
			switch (b)
			{
			case '0'://返回
				system("cls");
				printf("已返回\n");
				break;
			case '1'://新增的学生信息
				for (i = 0; i < total; i++)
				{
					if (strcmp(stu[i].num, num) == 0)
					{
						Flag = 1;//确保输出一个学生信息
						swap = i + 1;//找到正确的学生信息所在的位置
						system("cls");
						prinStu();//输出学生信息
						Return();//返回
						break;
					}
				}
				break;
			case '2'://所有学生信息
				system("cls");
				prin();//输出所有学生信息
				Return();//返回
				break;
			default:
				system("cls");
				printf("选择错误，请重新选择\n");
			}
		} while (b != '0');
	}
}

void DeleteStu()//按学生姓名删除学生信息
{
	char n = 0;//确认第几个学生
	char d = 0;//删除
	char r = 0;//操作或返回的临时变量
	int swap1 = 0;//临时记录读取到的学生个数
	f = 0;
	printf("删除学生信息。\n");
	ChackName();//按学生姓名查询，判断是否为新的学生。
	do
	{
		while (1)
		{
			prinStu();//输出符合条件的学生信息
			if (Flag)
			{
				swap1 = swap;//保留读取到的学生个数
				printf("\n已找到%d个学生信息,要删除第几个学生的学生信息。\n", swap);
				n = _getch() - 48;
				if (n > 0 && n <= swap)//判断是否正确选择
					break;//退出内层循环
				else
				{
					system("cls");
					printf("删除信息有误，请重新选择。\n");
				}
			}
			else
			{
				Return();//返回
				system("cls");
				break;//退出内层循环
			}
		}
		if (!Flag)
			break;//退出外层循环
		system("cls");
		Flag = 1;//确保输出一个学生信息
		swap = n;//指向要输出的学生信息位置
		prinStu();//输出学生信息
		printf("按y确认删除,其他键返回。\n");
		d = _getch();
		system("cls");
		if (d == 'y')//执行删除
		{
			stu[n - 1] = stu[total - 1];//将最后一个学生信息的内容直接覆盖到不要的学生信息的位置上
			total--;
			SortNum();//按学号排序
			write();//重写文件
			printf("按1查看全部学生信息，其他键继续。\n");
			r = _getch();
			if (r == '1')
			{
				prin();//输出所有学生信息
				Return();//返回
			}
		}
		else
		{
			Flag = 2;
			swap = swap1;
		}
		system("cls");
	} while (d != 'y');
}

void DeleteNum()//按学生学号删除学生信息
{
	char d = 0;//删除
	swap = 0;//初始化变量
	printf("删除学生信息。\n");
	ChackNum();//按学生学号查询，判断是否为新的学生。
	prinStu();//输出学生信息
	if (Flag)
	{
		printf("按y确认删除，其他键返回。\n");
		d = _getch();
		if (d == 'y')
		{
			stu[swap - 1] = stu[total - 1];//将最后一个学生信息的内容直接覆盖到不要的学生信息的位置上
			total--;
			SortNum();//按学号排序
			write();//重写文件
			printf("按1查看所有学生信息，其他键返回。\n");
			d = _getch();
			if (d == '1')
			{
				prin();//输出所有学生信息
				Return();//返回
			}
		}
	}
	else
		Return();//返回
	system("cls");
}

void ChangeStu()//修改学生信息
{
	printf("修改学生信息。\n");
	ChackNum();//按学号查找
	prinStu();//输出学生信息
	if (Flag)
	{
		char b = 0;//二级菜单功能选择
		system("cls");
		do
		{
			prinStu();//输出学生信息
			menu5();//修改菜单
			printf("请选择要修改的信息\n");
			b = _getch();
			switch (b)
			{
			case '0'://返回
				system("cls");
				printf("已返回。\n");
				break;
			case '1'://修改学号
				printf("学号：");
				scanf("%s", stu[swap - 1].num);
				system("cls");
				printf("修改成功。\n");
				break;
			case '2'://修改姓名
				printf("姓名：");
				scanf("%s", stu[swap - 1].name);
				system("cls");
				printf("修改成功。\n");
				break;
			case '3'://修改性别
				printf("性别：");
				scanf("%s", stu[swap - 1].sex);
				system("cls");
				printf("修改成功。\n");
				break;
			case '4'://修改出生年月
				printf("出身年月：");
				scanf("%s", stu[swap - 1].year);
				system("cls");
				printf("修改成功。\n");
				break;
			case '5'://修改籍贯
				printf("籍贯：");
				scanf("%s", stu[swap - 1].address);
				system("cls");
				printf("修改成功。\n");
				break;
			case '6'://修改电话
				printf("电话：");
				scanf("%s", stu[swap - 1].tel);
				system("cls");
				printf("修改成功。\n");
				break;
			case '7'://修改入学成绩
				printf("入学成绩：");
				scanf("%d", &stu[swap - 1].grades);
				system("cls");
				printf("修改成功。\n");
				break;
			default:
				system("cls");
				printf("选择错误，请重新选择。\n");
			}
		} while (b != '0');
		SortNum();//按学号排序
		write();//重写文件
	}
	else
		Return();//返回
}

void SortSex()//按性别分类学生信息
{
	swap = 0;//初始化变量
	SortNum();//按学生学号升序排序
	for (i = 0; i < total; i++)
	{
		if (strcmp(stu[i].sex, "男") == 0)//将男女分开排序
			swap++;
		else
		{
			int j;//临时循环变量
			for (j = i + 1; j < total; j++)
				if (strcmp(stu[j].sex, "男") == 0)
				{
					STU tmp = stu[i];
					stu[i] = stu[j];
					stu[j] = tmp;
					swap++;
					break;
				}
		}
	}

	FILE* fp = fopen("male.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败。\n");
		exit(0);
	}
	fprintf(fp, "%s", title);
	for (i = 0; i < swap; i++)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
		if (i != swap - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);

	fp = fopen("female.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败。\n");
		exit(0);
	}
	fprintf(fp, "%s", title);
	for (i = swap; i < total; i++)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
		if (i != total - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);
}

void PrintMale()//输出男学生信息
{
	Flag = 2;//确保可以输出多个学生信息
	f = 0;//从第一个学生信息开始输出
	system("cls");
	printf("当前学生信息：\n\n");
	prinStu();//输出学生信息
	Return();
}

void PrintFemale()//输出女学生信息
{
	system("cls");
	printf("当前学生信息：\n\n");
	f = swap;//从第swap个学生信息开始输出
	swap = total;//输出的最后一个学生的位置
	prinStu();//输出学生信息
	Return();//返回
}