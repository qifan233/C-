#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//功能选择
enum Function
{
	//主菜单
	Exit,
	Chack,
	Sort,
	Add,
	Del,
	Change,
	SexSort,

	//查询按钮
	Chack_Name = 1,
	Chack_Num,
	Chack_All,

	//排序按钮
	Sort_Grades_Up = 1,
	Sort_Grades_Down,
	Sort_Name_Up,
	Sort_Name_Down,

	//删除按钮
	Del_Name = 1,
	Del_Num,
};

//学生信息
typedef struct StuMessage
{
	char num[10];
	char name[20];
	char sex[5];
	char year[11];
	char address[30];
	char tel[12];
	int grades;
}StuM;

typedef struct Student
{
	StuM* stum;
	int total;
	int quantity;
	char title[100];
}STU;

//数据操作
void FileRead(STU*);
void FileWrite(STU*);
void Origin(STU*);
void Expansion(STU*);

void Return();

//主菜单
void Menu();

//查询
void ChackFunction(STU*);
void Chack_Menu();
char* ChackName(STU*);
char* ChackNum(STU*);
void ChackAll(STU*);

//排序
void SortFunction(STU*);
void Sort_Menu();
void SortGradesUp(STU*);
void SortGradesDown(STU*);
void SortNameUp(STU*);
void SortNameDown(STU*);
void SortNum(STU*);


//添加
void AddFunction(STU*);

//删除
void DelFunction(STU*);
void Del_Menu();
void DelName(STU*);
void DelNum(STU*);


//修改
void ChangeFunction(STU*);
void Change_Menu();

//性别分类
void SexSortFunction(STU*);