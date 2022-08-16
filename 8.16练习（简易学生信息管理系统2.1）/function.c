#include "function.h"

//���˵�
void Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                   ѧ����Ϣ����ϵͳ                  |\n");
	printf("                                |                1.��ѯ           2.����              |\n");
	printf("                                |                3.���           4.ɾ��              |\n");
	printf("                                |                5.�޸�           6.�Ա����          |\n");
	printf("                                |                        0.�˳�                       |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//��ѯ�˵�
void Chack_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                       ��ѯ��ʽ                      |\n");
	printf("                                |                    1.��������ѯ                     |\n");
	printf("                                |                    2.��ѧ�Ų�ѯ                     |\n");
	printf("                                |                    3.��ѯ������Ϣ                   |\n");
	printf("                                |                    0.����                           |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//����˵�
void Sort_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                       ����ʽ                      |\n");
	printf("                                |                    1.����ѧ�ɼ�����                 |\n");
	printf("                                |                    2.����ѧ�ɼ�����                 |\n");
	printf("                                |                    3.����������                     |\n");
	printf("                                |                    4.����������                     |\n");
	printf("                                |                    0.����                           |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//ɾ���˵�
void Del_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                       ɾ����ʽ                      |\n");
	printf("                                |                    1.ѧ������                       |\n");
	printf("                                |                    2.ѧ��ѧ��                       |\n");
	printf("                                |                    0.����                           |\n");
	printf("                                |-----------------------------------------------------|\n");
}

//�޸Ĳ˵�
void Change_Menu()
{
	printf("                                |-----------------------------------------------------|\n");
	printf("                                |                         �޸ķ�ʽ                    |\n");
	printf("                                |                    1.ѧ��      2.����               |\n");
	printf("                                |                    3.�Ա�      4.����               |\n");
	printf("                                |                    5.��������  6.�绰               |\n");
	printf("                                |                    7.��ѧ�ɼ�  0.����               |\n");
	printf("                                |-----------------------------------------------------|\n");
}



//��ʼ��
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
			printf("����ʧ��.\n");
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
		printf("�ļ���ʧ��\n");
		exit(0);
	}

	//��ȡ����
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
	printf("��Ϣ���³ɹ�\n");
}



//��ѯ����
void ChackFunction(STU* stu) 
{
	while (1)
	{
		int button;
		Chack_Menu();
		printf("ѡ��Ҫִ�еĹ���:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			system("cls");
			printf("�ѷ���\n");
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
			printf("ѡ�����������ѡ��\n");
		}
	}
}

void ChackName(STU* stu)
{
	//�汾һ
	/*int i, flag;
	int first;
	char find_name[10] = {0};
	first = flag = 0;

	printf("������Ҫ���ҵ�ѧ������:");
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
		printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
		return NULL;
	}

	return find_name;*/

	//�汾2
	char find_name[20] = { 0 };
	int i = 0;	  //���ҵ���ʼλ��
	int flag = 0; //�ж���Ϣ�Ƿ����
	printf("������Ҫ���ҵ�ѧ������:");
	scanf("%s", find_name);

	printf("%s", stu->title);
	//��������
	while (i < stu->quantity)
	{
		i = Chack1(stu, find_name, i, stu->quantity, &flag, ((char*)stu->stum->name) - (char*)(stu->stum));
		if (flag && i < stu->quantity)
		{
			printf("%s %s %s %s %s %s %d\n",
				stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
				stu->stum[i].grades);
		}
		else if (!flag && i == stu->quantity)
		{
			printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
		}
		i++;
	}
	//Return();
}

bool ChackNum(STU* stu)
{
	//�汾һ
	/*int i, flag = 0;
	char find_num[10] = { 0 };
	printf("������Ҫ���ҵ�ѧ��ѧ��:");
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
		printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
		return find_num;
	}
	return NULL;*/

	//�汾��
	char find_num[10] = { 0 };
	int i = 0;	  //���ҵ���ʼλ��
	int flag = 0; //�ж���Ϣ�Ƿ����
	printf("������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%s", find_num);

	printf("%s", stu->title);

	i = Chack1(stu, find_num, i, stu->quantity, &flag, ((char*)stu->stum->num) - (char*)(stu->stum));
	if (flag)
	{
		printf("%s %s %s %s %s %s %d\n",
			stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
			stu->stum[i].grades);
		return true;
	}
	else
	{
		printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
		return false;
	}
	//Return();
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

//         ���ҵ�ַ  ��������   ������ʼ��  ��ֹ��   �ж���Ϣ�Ƿ����
int Chack1(STU* stu, char* ptr, int first, int last, int* flag, int offset)
{
	for (; first < last; (first)++)
	{
		if (strcmp(ptr, (char*) & stu->stum[first] + offset) == 0)
		{
			*flag = 1;
			return first;
		}
	}
	return first;
}
/*���ҸĽ���*/
//void chack1(STU* stu)
//{
//	char find_name[10] = {0};
//	int i = 0;	  //���ҵ���ʼλ��
//	int flag = 0; //�ж���Ϣ�Ƿ����
//	printf("������Ҫ���ҵ�ѧ������:");
//	scanf("%s", find_name);
//
//	printf("%s", stu->title);
//	//��������
//	while (i < stu->quantity)
//	{
//		i = Chack1(stu, find_name, i, stu->quantity, &flag, ((char*)stu->stum->name) - (char*)(stu->stum));
//		if (flag && i < stu->quantity)
//		{
//			printf("%s %s %s %s %s %s %d\n",
//				stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
//				stu->stum[i].grades);
//		}
//		else if(!flag && i == stu->quantity)
//		{
//			printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
//		}
//		i++;
//	}
//	Return();
//}

//������
void SortFunction(STU* stu)
{
	while (1)
	{
		int button;
		Sort_Menu();
		printf("ѡ��Ҫִ�еĹ���:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			system("cls");
			printf("�ѷ���\n");
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
			printf("ѡ�����������ѡ��\n");
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
	printf("��������\n");
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
	printf("��������\n");
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
	printf("��������\n");
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
	printf("��������\n");
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

//������
void AddFunction(STU* stu)
{
	//�汾һ
	/*char* num = ChackNum(stu);*/
	//�汾��
	char find_num[20] = { 0 };
	int flag = 0; //�ж���Ϣ�Ƿ����
	printf("������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%s", find_num);
	int i = Chack1(stu, find_num, 0, stu->quantity, &flag, (char*)(stu->stum->num) - (char*)(stu->stum));

	if (!flag)
	{
		Add1(stu, find_num);
	}
	else
	{
		printf("��ǰѧ����Ϣ�Ѵ���\n");
		printf("%s", stu->title);
		printf("%s %s %s %s %s %s %d\n",
			stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
			stu->stum[i].grades);
	}
}

void Add1(STU* stu, char* num)
{
	Expansion(stu);
	strcpy(stu->stum[stu->quantity].num,num);
	printf("\033[1A ����ѧ��Ϊ%s��ѧ����Ϣ����������������Ϣ(�ÿո����)��\n", stu->stum[stu->quantity].num);
	printf("ѧ�� ���� �Ա� �������� ���� �绰 ��ѧ�ɼ�\n");
	printf("%s ", num);
	scanf("%s %s %s %s %s %d", stu->stum[stu->quantity].name, stu->stum[stu->quantity].sex, stu->stum[stu->quantity].year,
		stu->stum[stu->quantity].address, stu->stum[stu->quantity].tel, &stu->stum[stu->quantity].grades);
	stu->quantity++;
	FileWrite(stu);
}

//ɾ������
void DelFunction(STU* stu)
{
	while (1)
	{
		int button;
		Del_Menu();
		printf("ѡ��Ҫִ�еĹ���:");
		scanf("%d", &button);

		switch (button)
		{
		case Exit:
			system("cls");
			printf("�ѷ���\n");
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
			printf("ѡ�����������ѡ��\n");
		}
	}
}

void DelName(STU* stu)
{
	//�汾һ
	/*if (ChackName(stu))
	{
		printf("\n\n��ѡ��Ҫɾ����ѧ����Ϣ��");
		int n = 0;
		scanf("%d", &n);
		printf("%s", stu->title);
		printf("%s %s %s %s %s %s %d\n",
			stu->stum[n - 1].num, stu->stum[n - 1].name, stu->stum[n - 1].sex, stu->stum[n - 1].year,
			stu->stum[n - 1].address, stu->stum[n - 1].tel, stu->stum[n - 1].grades);
		printf("�Ƿ�ȷ��ɾ��y\\n");
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
			printf("ɾ��ʧ��\n");
		}
	}*/

	//�汾��
	char find_name[20] = { 0 };
	int flag = 0; //�ж���Ϣ�Ƿ����
	int i = 0;
	int first = 0;
	printf("������Ҫ���ҵ�ѧ������:");
	scanf("%s", find_name);

	while (i < stu->quantity)
	{
		i = Chack1(stu, find_name, i, stu->quantity, &flag, ((char*)stu->stum->name) - (char*)(stu->stum));
		if (flag && i < stu->quantity)
		{
			printf("%s %s %s %s %s %s %d\n",
				stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
				stu->stum[i].grades);

			StuM tmp = stu->stum[i];
			stu->stum[i] = stu->stum[first];
			stu->stum[first] = tmp;
			first++;
		}
		else if (!flag && i == stu->quantity)
		{
			printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
			return;
		}
		i++;
	}

	printf("\n\n��ѡ��Ҫɾ���ڼ���ѧ����Ϣ��");
	int n = 0;
	scanf("%d", &n);
	printf("%s", stu->title);
	printf("%s %s %s %s %s %s %d\n",
		stu->stum[n - 1].num, stu->stum[n - 1].name, stu->stum[n - 1].sex, stu->stum[n - 1].year,
		stu->stum[n - 1].address, stu->stum[n - 1].tel, stu->stum[n - 1].grades);
	printf("�Ƿ�ȷ��ɾ��y\\n  ");
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
		printf("ɾ��ʧ��\n");
	}
}

void DelNum(STU* stu)
{
	//�汾һ
	/*if (!ChackNum(stu))
	{
		printf("�Ƿ�ȷ��ɾ��y\\n��");
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
			printf("ɾ��ʧ��\n");
		}
	}*/

	//�汾��
	char find_num[10] = { 0 };
	int i = 0;	  //���ҵ���ʼλ��
	int flag = 0; //�ж���Ϣ�Ƿ����
	printf("������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%s", find_num);

	printf("%s", stu->title);

	i = Chack1(stu, find_num, i, stu->quantity, &flag, ((char*)stu->stum->num) - (char*)(stu->stum));
	if (flag)
	{
		printf("%s %s %s %s %s %s %d\n",
			stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
			stu->stum[i].grades);
		StuM tmp = stu->stum[i];
		stu->stum[i] = stu->stum[0];
		stu->stum[0] = tmp;
	}
	else
	{
		printf("\033[1A�Ҳ�����ǰѧ����Ϣ                                                                      \n");
		return;
	}

	printf("�Ƿ�ȷ��ɾ��y\\n�� ");
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
		printf("ɾ��ʧ��\n");
	}
}

//�޸Ĺ���
void ChangeFunction(STU* stu)
{
	if (ChackNum(stu))
	{
		printf("�Ƿ�Ҫ�޸���Ϣy\\n��");
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
				printf("��ѡ��Ҫ�޸ĵ���Ϣ��");

				scanf("%d", &n);
				switch (n)
				{
				case 0:
					printf("�ѷ���\n");
					break;

				case 1:
					printf("ѧ�ţ�");
					scanf("%s", stu->stum[0].num);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				case 2:
					printf("������");
					scanf("%s", stu->stum[0].name);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				case 3:
					printf("�Ա�");
					scanf("%s", stu->stum[0].sex);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				case 4:
					printf("���᣺");
					scanf("%s", stu->stum[0].address);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				case 5:
					printf("�������£�");
					scanf("%s", stu->stum[0].year);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				case 6:
					printf("�绰��");
					scanf("%s", stu->stum[0].tel);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				case 7 :
					printf("��ѧ�ɼ���");
					scanf("%d", &stu->stum[0].grades);
					system("cls");
					printf("�޸ĳɹ�\n");
					break;

				default:
					system("cls");
					printf("ѡ�����������ѡ��");
				}
			} while(n);

			FileWrite(stu);
		}
	}
}

//�Ա����
void SexSortFunction(STU* stu)
{
	SortNum(stu);
	int malenum = 0;
	for (int i = 0, cur = 0; i < stu->quantity;)
	{
		if (strcmp(stu->stum[i].sex, "��") == 0)
		{
			i++;
			cur++;
			malenum++;
		}
		else
		{
			i++;
			for (; i < stu->quantity;)
			{
				if (strcmp(stu->stum[i].sex, "��") != 0)
				{
					i++;
				}
				else
				{
					//������Ů��λ��
					StuM tmp = stu->stum[i];
					stu->stum[i] = stu->stum[cur];
					stu->stum[cur] = tmp;
					i = ++cur;
					malenum++;
					break;
				}
			}
		}
	}

	//д����������
	FILE* fp = fopen("male.txt", "w");
	fputs(stu->title, fp);
	for (int i = 0; i < malenum; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s %d",
			stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
			stu->stum[i].grades);
		if (i != malenum - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);

	//д��Ů������
	fp = fopen("female.txt", "w");
	fputs(stu->title, fp);
	for (int i = malenum; i < stu->quantity; i++)
	{
		fprintf(fp, "%s %s %s %s %s %s %d",
			stu->stum[i].num, stu->stum[i].name, stu->stum[i].sex, stu->stum[i].year, stu->stum[i].address, stu->stum[i].tel,
			stu->stum[i].grades);
		if (i != stu->quantity - 1)
			fprintf(fp, "\n");
	}
	fclose(fp);

	printf("����ɹ��������ļ��ڲ鿴\n");

	Return();
}

//����
void Return()
{
	printf("\n���������\n");
	_getch();
	system("cls");
}

//���ٿռ�
void Destroy(STU* stu)
{
	free(stu->stum);
	stu->stum = NULL;
}