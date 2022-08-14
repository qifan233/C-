#include"test.h"

void menu()//菜单功能
{
	char a = 0;//一级菜单功能选择
	do
	{
		menu0();//首页菜单
		printf("选择执行的功能序号：");
		a= _getch();

		switch (a)
		{
		case '0'://退出
			system("cls");//清楚屏幕内容
			printf("已退出学生信息管理系统。\n");
			break;

		case '1'://查询功能
		{
			char b = 0;//二级菜单功能选择
			system("cls");

			do
			{
				menu1();//查询菜单
				printf("请选择查询的方式: ");
				b = _getch();

				switch (b)
				{
				case '0'://返回首页
					system("cls");
					printf("已返回首页\n");
					break;

				case '1':
					ChackName();//按学生姓名查询
					system("cls");
					prinStu();//输出学生信息
					SortNum();//按学号分类
					Return();//返回
					break;

				case '2':
					ChackNum();//按学生学号查询
					system("cls");
					prinStu();//输出学生信息
					Return();//返回
					break;

				case '3':
					AllChack();//显示所有学生信息
					break;

				default:
					system("cls");
					printf("选择错误，请重新选择\n");
				}
			} while (b != '0');
		}
			break;

		case '2'://排序功能
		{
			char b = 0;//二级菜单功能选择
			system("cls");

			do
			{
				menu2();//排序菜单
				printf("请选择排序的方式；");
				b = _getch();

				switch (b)
				{
				case '0'://返回首页
					system("cls");
					printf("已返回首页。\n");
					break;

				case '1'://按学生姓名排序
				{
					char c = 0;//三级菜单选择
					system("cls");

					do
					{
						menu4();//姓名排序菜单
						printf("请选择排序类型：");
						c = _getch();

						switch (c)
						{
						case '0'://返回上一页
							system("cls");
							printf("已返回\n");
							break;

						case '1':
							system("cls");
							printf("已按学生姓名升序排列。\n\n");
							SortNameUp();//按学生姓名升序
							prin();//输出所有学生信息
							Return();//返回
							break;

						case '2':
							system("cls");
							printf("已按学生姓名降序排列。\n\n");
							SortNameDown();//按学生姓名降序
							prin();//输出所有学生信息
							Return();//返回
							break;

						default:
							system("cls");
							printf("选择错误，请重新选择。\n");
						}
					} while (c != '0');
				}
				break;

				case '2'://按学生入学成绩排序
				{
					char c = 0;//三级菜单功能选择
					system("cls");
					do
					{
						menu4();//入学成绩排序菜单
						printf("请选择排序类型：");
						c = _getch();

						switch (c)
						{
						case '0'://返回上一页
							system("cls");
							printf("已返回\n");
							break;

						case '1':
							SortGradesUp();//按学生入学成绩升序
							system("cls");
							printf("已按学生入学成绩升序排列。\n\n");
							prin();//输出所有学生信息
							Return();//信息
							break;

						case '2':
							SortGradesDown();//按学生入学成绩降序
							system("cls");
							printf("已按学生入学成绩降序排列。\n\n");
							prin();//输出所有学生信息
							Return();//返回
							break;

						default:
							system("cls");
							printf("选择错误，请重新选择。\n");
						}
					} while (c != '0');
				}
				break;

				default:
					system("cls");
					printf("选择错误，请重新选择。\n");
				}
			} while (b != '0');
		}
			break;

		case '3':
			AddStu();//增添学生信息
			break;

		case '4':
		{
			char b = 0;//二级菜单功能选择
			system("cls");

			do
			{
				menu3();//输出菜单
				printf("请选择删除的方式：");
				b = _getch();

				switch (b)
				{
				case '0'://返回
					system("cls");
					printf("已返回首页：\n");
					break;

				case '1':
					DeleteStu();//按学生姓名删除
					break;

				case '2':
					DeleteNum();//按学生学号删除
					break;

				default:
					system("cls");
					printf("选择错误，请重新选择\n");
				}
			} while (b != '0');
		}
			break;

		case '5':
			ChangeStu();//修改学生信息
			break;

		case '6':
		{
			char b = 0;//二级菜单功能选择
			SortSex();//按学生性别分类
			system("cls");
			printf("分类成功\n");

			do
			{
				menu6();//删除菜单
				printf("请选择要查看的信息：");
				b = _getch();

				switch (b)
				{
				case '0'://返回
					system("cls");
					printf("已返回。\n");
					break;

				case '1'://输出男学生信息
					PrintMale();
					break;
				case '2'://输出女学生信息
					PrintFemale();
					break;

				default:
					system("cls");
					printf("选择错误，请重新选择\n");
				}
			}while(b != '0');
		}
			break;

		default:
			system("cls");
			printf("选择错误，请重新选择。\n");
		}
	} while (a != '0');
}

void main()
{
	Fopen();//打开文件并输入文件内容
	menu();//显示菜单功能
}