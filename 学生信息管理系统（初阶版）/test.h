#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define X 40

typedef struct stduent//学生信息
{
	char num[10];//学号
	char name[10];//姓名
	char sex[5];//性别
	char year[20];//出生年月
	char address[20];//籍贯
	char tel[20];//电话
	int grades;//入学成绩
}STU;

int total;//记录总学生数
int i;//循环体变量
int Flag;//判断学生信息是否存在
int swap;//交换次数
int f;//初始记录学生位置
char num[10];//记录学号
char title[100];//标题
STU stu[X];//存放学生信息的结构体数组

void menu0();//首页菜单
void menu1();//查询菜单
void menu2();//排序菜单
void menu3();//删除菜单
void menu4();//升降序菜单
void menu5();//修改菜单
void menu6();//输出菜单
void menu7();//增添菜单

void Fopen();//打开文件并读取文件内容
void write();//重写文件
void Return();//返回函数
void prin();//输出文本内容
void prinStu();//输出某一学生信息

void ChackName();//按学生姓名查询
void ChackNum();//按学生学号查询
void AllChack();//显示所有学生信息

void SortNameUp();//按学生姓名升序排列
void SortNameDown();//按学生姓名降序排列
void SortGradesUp();//按学生入学成绩升序排列
void SortGradesDown();//按学生入学成绩降序排列
void SortNum();//按学生学号升序排序

void AddStu();//增添学生信息

void DeleteStu();//按学生姓名删除学生信息
void DeleteNum();//按学生学号删除学生信息

void ChangeStu();//修改学生信息

void SortSex();//按性别分类学生信息
void PrintMale();//输出男学生信息
void PrintFemale();//输出女学生信息