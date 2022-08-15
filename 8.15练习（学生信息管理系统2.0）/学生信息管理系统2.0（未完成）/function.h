#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//����ѡ��
enum Function
{
	//���˵�
	Exit,
	Chack,
	Sort,
	Add,
	Del,
	Change,
	SexSort,

	//��ѯ��ť
	Chack_Name = 1,
	Chack_Num,
	Chack_All,

	//����ť
	Sort_Grades_Up = 1,
	Sort_Grades_Down,
	Sort_Name_Up,
	Sort_Name_Down,

	//ɾ����ť
	Del_Name = 1,
	Del_Num,
};

//ѧ����Ϣ
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

//���ݲ���
void FileRead(STU*);
void FileWrite(STU*);
void Origin(STU*);
void Expansion(STU*);

void Return();

//���˵�
void Menu();

//��ѯ
void ChackFunction(STU*);
void Chack_Menu();
char* ChackName(STU*);
char* ChackNum(STU*);
void ChackAll(STU*);

//����
void SortFunction(STU*);
void Sort_Menu();
void SortGradesUp(STU*);
void SortGradesDown(STU*);
void SortNameUp(STU*);
void SortNameDown(STU*);
void SortNum(STU*);


//���
void AddFunction(STU*);

//ɾ��
void DelFunction(STU*);
void Del_Menu();
void DelName(STU*);
void DelNum(STU*);


//�޸�
void ChangeFunction(STU*);
void Change_Menu();

//�Ա����
void SexSortFunction(STU*);