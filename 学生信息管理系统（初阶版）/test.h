#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define X 40

typedef struct stduent//ѧ����Ϣ
{
	char num[10];//ѧ��
	char name[10];//����
	char sex[5];//�Ա�
	char year[20];//��������
	char address[20];//����
	char tel[20];//�绰
	int grades;//��ѧ�ɼ�
}STU;

int total;//��¼��ѧ����
int i;//ѭ�������
int Flag;//�ж�ѧ����Ϣ�Ƿ����
int swap;//��������
int f;//��ʼ��¼ѧ��λ��
char num[10];//��¼ѧ��
char title[100];//����
STU stu[X];//���ѧ����Ϣ�Ľṹ������

void menu0();//��ҳ�˵�
void menu1();//��ѯ�˵�
void menu2();//����˵�
void menu3();//ɾ���˵�
void menu4();//������˵�
void menu5();//�޸Ĳ˵�
void menu6();//����˵�
void menu7();//����˵�

void Fopen();//���ļ�����ȡ�ļ�����
void write();//��д�ļ�
void Return();//���غ���
void prin();//����ı�����
void prinStu();//���ĳһѧ����Ϣ

void ChackName();//��ѧ��������ѯ
void ChackNum();//��ѧ��ѧ�Ų�ѯ
void AllChack();//��ʾ����ѧ����Ϣ

void SortNameUp();//��ѧ��������������
void SortNameDown();//��ѧ��������������
void SortGradesUp();//��ѧ����ѧ�ɼ���������
void SortGradesDown();//��ѧ����ѧ�ɼ���������
void SortNum();//��ѧ��ѧ����������

void AddStu();//����ѧ����Ϣ

void DeleteStu();//��ѧ������ɾ��ѧ����Ϣ
void DeleteNum();//��ѧ��ѧ��ɾ��ѧ����Ϣ

void ChangeStu();//�޸�ѧ����Ϣ

void SortSex();//���Ա����ѧ����Ϣ
void PrintMale();//�����ѧ����Ϣ
void PrintFemale();//���Ůѧ����Ϣ