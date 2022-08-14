#include "test.h"

void menu0()//��ҳ�˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    ѧ����Ϣ����ϵͳ    *********\n");
	printf("               *********    1.��ѯѧ����Ϣ      *********\n");
	printf("               *********    2.ѧ����Ϣ����      *********\n");
	printf("               *********    3.���ѧ����Ϣ      *********\n");
	printf("               *********    4.ɾ��ѧ����Ϣ      *********\n");
	printf("               *********    5.�޸�ѧ����Ϣ      *********\n");
	printf("               *********    6.���Ա����ѧ��    *********\n");
	printf("               *********    0.�˳�              *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}
void menu1()//��ѯ�˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    1.��������ѯ       **********\n");
	printf("               *********    2.��ѧ�Ų�ѯ       **********\n");
	printf("               *********    3.ȫ��ѧ����Ϣ     **********\n");
	printf("               *********    0.������ҳ         **********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}
void menu2()//����˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    1.��ѧ����������     ********\n");
	printf("               *********    2.����ѧ�ɼ�����     ********\n");
	printf("               *********    0.������ҳ           ********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}
void menu3()//ɾ���˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********    1.������ɾ��          *******\n");
	printf("               *********    2.��ѧ��ɾ��          *******\n");
	printf("               *********    0.������ҳ            *******\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu4()//������˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n"); 
	printf("               *********       1.����           *********\n");
	printf("               *********       2.����           *********\n");
	printf("               *********       0.����           *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu5()//�޸Ĳ˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               ******     1. ѧ��       2.����     ******\n"); 
	printf("               ******     3. �Ա�       4.�������� ******\n");
	printf("               ******     5. ����       6. �绰    ******\n");
	printf("               ******     7. ��ѧ�ɼ�   0. ����    ******\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu6()//����˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********         1.����         *********\n");
	printf("               *********         2.Ů��         *********\n");
	printf("               *********         0.����         *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void menu7()//����˵�
{
	printf("               ******************************************\n");
	printf("               ******************************************\n");
	printf("               *********      1.������ѧ����Ϣ  *********\n");
	printf("               *********      2.����ѧ����Ϣ    *********\n");
	printf("               *********      0.����            *********\n");
	printf("               ******************************************\n");
	printf("               ******************************************\n");
}

void Fopen()//���ļ�����ȡ�ļ�����
{
	FILE* fp = fopen("JK0703.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
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

void write()//��д�ļ�
{
	FILE* fp = fopen("JK0703.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
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
	printf("ѧ����Ϣ�Ѹ��¡�\n");
}

void Return()//����
{
	char r;//�йط��غͲ�������ʱ����
	printf("\n�����������\n");
	r = _getch();
	system("cls");
}

void prin()//�������ѧ����Ϣ
{
	printf("\n%s", title);
	for (i = 0; i < total; i++)
	{
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
			stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
	}
}


void prinStu()//���Ҳ���ӡĳһѧ����Ϣ
{
	if (Flag == 1)//���һ��ѧ����Ϣ
	{
		printf("\n%s", title);
		printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\n\n",
			stu[swap - 1].num, stu[swap - 1].name, stu[swap - 1].sex, stu[swap - 1].year, stu[swap - 1].address, stu[swap - 1].tel, stu[swap - 1].grades);
	}
	else if (Flag > 1)//������ѧ����Ϣ
	{
		printf("\n%s", title);
		for (i = f; i < swap; i++)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%d\n",
				stu[i].num, stu[i].name, stu[i].sex, stu[i].year, stu[i].address, stu[i].tel, stu[i].grades);
		}
	}
	else
		printf("�Ҳ�����ѧ����Ϣ��\n");
}

void ChackName()//��ѧ��������ѯ
{
	char name[10] = {0};
	i = Flag = swap = f = 0;//������ʼ��
	system("cls");
	printf("������ѧ��������");
	scanf("%s", name);

	for (i = 0; i < total; i++)//ѭ������ѧ����Ϣ
	{
		if (strcmp(name, stu[i].name) == 0)
		{
			STU Tmp = stu[swap];
			stu[swap] = stu[i];
			stu[i] = Tmp;
			Flag++;//�ж�ѧ������
			swap++;//�������������ѧ����
		}
	}
}

void ChackNum()//��ѧ��ѧ�Ų�ѯ
{
	i = Flag = swap = 0;//������ʼ��
	system("cls");
	printf("������ѧ��ѧ�ţ�");
	scanf("%s", num);

	for (i = 0; i < total; i++)//ѭ������ѧ����Ϣ
	{
		if (strcmp(num, stu[i].num) == 0)
		{
			Flag = 1;//ȷ�����һ��ѧ������Ϣ
			swap = i + 1;//��ѧ����Ϣ��ȷ���ҵ�
			break;
		}
	}
}

void AllChack()//��ʾ����ѧ����Ϣ
{
	SortNum();//��ѧ������
	system("cls");
	printf("ȫ��ѧ����Ϣ����\n\n");
	prin();//�������ѧ����Ϣ
	Return();//����
}

void SortNameUp()//��ѧ��������������
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//��ʱѭ������
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

void SortNameDown()//��ѧ��������������
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//��ʱѭ������
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

void SortGradesUp()//��ѧ����ѧ�ɼ�����
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//��ʱѭ������
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

void SortGradesDown()//��ѧ����ѧ�ɼ�����
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//��ʱѭ������
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

void SortNum()//��ѧ��ѧ����������
{
	for (i = 0; i < total; i++)
	{
		int j = 0;//��ʱѭ������
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

void AddStu()//�����µ�ѧ����Ϣ
{
	char b = 0;//�����˵�����ѡ��
	i = 0;
	printf("����ѧ����Ϣ��\n");
	ChackNum();//��ѧ��ѧ�Ų�ѯ���ж��Ƿ�Ϊ�µ�ѧ����
	if (Flag)
	{
		printf("��ѧ����Ϣ�Ѵ��ڡ�\n");
		Return();//����
	}
	else
	{
		printf("¼���µ�ѧ����Ϣ��\n");
		printf("������");
		scanf("%s", stu[total].name);
		printf("�Ա�");
		scanf("%s", stu[total].sex);
		printf("�������£�");
		scanf("%s", stu[total].year);
		printf("���᣺");
		scanf("%s", stu[total].address);
		printf("�绰���룺");
		scanf("%s", stu[total].tel);
		printf("��ѧ�ɼ���");
		scanf("%d", &stu[total].grades);
		strcpy(stu[total].num, num);
		total++;
		SortNum();//��ѧ������
		write();//���ļ���д
		do
		{
			menu7();//����˵�
			printf("ѡ��Ҫ�鿴����Ϣ\n");
			b = _getch();
			switch (b)
			{
			case '0'://����
				system("cls");
				printf("�ѷ���\n");
				break;
			case '1'://������ѧ����Ϣ
				for (i = 0; i < total; i++)
				{
					if (strcmp(stu[i].num, num) == 0)
					{
						Flag = 1;//ȷ�����һ��ѧ����Ϣ
						swap = i + 1;//�ҵ���ȷ��ѧ����Ϣ���ڵ�λ��
						system("cls");
						prinStu();//���ѧ����Ϣ
						Return();//����
						break;
					}
				}
				break;
			case '2'://����ѧ����Ϣ
				system("cls");
				prin();//�������ѧ����Ϣ
				Return();//����
				break;
			default:
				system("cls");
				printf("ѡ�����������ѡ��\n");
			}
		} while (b != '0');
	}
}

void DeleteStu()//��ѧ������ɾ��ѧ����Ϣ
{
	char n = 0;//ȷ�ϵڼ���ѧ��
	char d = 0;//ɾ��
	char r = 0;//�����򷵻ص���ʱ����
	int swap1 = 0;//��ʱ��¼��ȡ����ѧ������
	f = 0;
	printf("ɾ��ѧ����Ϣ��\n");
	ChackName();//��ѧ��������ѯ���ж��Ƿ�Ϊ�µ�ѧ����
	do
	{
		while (1)
		{
			prinStu();//�������������ѧ����Ϣ
			if (Flag)
			{
				swap1 = swap;//������ȡ����ѧ������
				printf("\n���ҵ�%d��ѧ����Ϣ,Ҫɾ���ڼ���ѧ����ѧ����Ϣ��\n", swap);
				n = _getch() - 48;
				if (n > 0 && n <= swap)//�ж��Ƿ���ȷѡ��
					break;//�˳��ڲ�ѭ��
				else
				{
					system("cls");
					printf("ɾ����Ϣ����������ѡ��\n");
				}
			}
			else
			{
				Return();//����
				system("cls");
				break;//�˳��ڲ�ѭ��
			}
		}
		if (!Flag)
			break;//�˳����ѭ��
		system("cls");
		Flag = 1;//ȷ�����һ��ѧ����Ϣ
		swap = n;//ָ��Ҫ�����ѧ����Ϣλ��
		prinStu();//���ѧ����Ϣ
		printf("��yȷ��ɾ��,���������ء�\n");
		d = _getch();
		system("cls");
		if (d == 'y')//ִ��ɾ��
		{
			stu[n - 1] = stu[total - 1];//�����һ��ѧ����Ϣ������ֱ�Ӹ��ǵ���Ҫ��ѧ����Ϣ��λ����
			total--;
			SortNum();//��ѧ������
			write();//��д�ļ�
			printf("��1�鿴ȫ��ѧ����Ϣ��������������\n");
			r = _getch();
			if (r == '1')
			{
				prin();//�������ѧ����Ϣ
				Return();//����
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

void DeleteNum()//��ѧ��ѧ��ɾ��ѧ����Ϣ
{
	char d = 0;//ɾ��
	swap = 0;//��ʼ������
	printf("ɾ��ѧ����Ϣ��\n");
	ChackNum();//��ѧ��ѧ�Ų�ѯ���ж��Ƿ�Ϊ�µ�ѧ����
	prinStu();//���ѧ����Ϣ
	if (Flag)
	{
		printf("��yȷ��ɾ�������������ء�\n");
		d = _getch();
		if (d == 'y')
		{
			stu[swap - 1] = stu[total - 1];//�����һ��ѧ����Ϣ������ֱ�Ӹ��ǵ���Ҫ��ѧ����Ϣ��λ����
			total--;
			SortNum();//��ѧ������
			write();//��д�ļ�
			printf("��1�鿴����ѧ����Ϣ�����������ء�\n");
			d = _getch();
			if (d == '1')
			{
				prin();//�������ѧ����Ϣ
				Return();//����
			}
		}
	}
	else
		Return();//����
	system("cls");
}

void ChangeStu()//�޸�ѧ����Ϣ
{
	printf("�޸�ѧ����Ϣ��\n");
	ChackNum();//��ѧ�Ų���
	prinStu();//���ѧ����Ϣ
	if (Flag)
	{
		char b = 0;//�����˵�����ѡ��
		system("cls");
		do
		{
			prinStu();//���ѧ����Ϣ
			menu5();//�޸Ĳ˵�
			printf("��ѡ��Ҫ�޸ĵ���Ϣ\n");
			b = _getch();
			switch (b)
			{
			case '0'://����
				system("cls");
				printf("�ѷ��ء�\n");
				break;
			case '1'://�޸�ѧ��
				printf("ѧ�ţ�");
				scanf("%s", stu[swap - 1].num);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			case '2'://�޸�����
				printf("������");
				scanf("%s", stu[swap - 1].name);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			case '3'://�޸��Ա�
				printf("�Ա�");
				scanf("%s", stu[swap - 1].sex);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			case '4'://�޸ĳ�������
				printf("�������£�");
				scanf("%s", stu[swap - 1].year);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			case '5'://�޸ļ���
				printf("���᣺");
				scanf("%s", stu[swap - 1].address);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			case '6'://�޸ĵ绰
				printf("�绰��");
				scanf("%s", stu[swap - 1].tel);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			case '7'://�޸���ѧ�ɼ�
				printf("��ѧ�ɼ���");
				scanf("%d", &stu[swap - 1].grades);
				system("cls");
				printf("�޸ĳɹ���\n");
				break;
			default:
				system("cls");
				printf("ѡ�����������ѡ��\n");
			}
		} while (b != '0');
		SortNum();//��ѧ������
		write();//��д�ļ�
	}
	else
		Return();//����
}

void SortSex()//���Ա����ѧ����Ϣ
{
	swap = 0;//��ʼ������
	SortNum();//��ѧ��ѧ����������
	for (i = 0; i < total; i++)
	{
		if (strcmp(stu[i].sex, "��") == 0)//����Ů�ֿ�����
			swap++;
		else
		{
			int j;//��ʱѭ������
			for (j = i + 1; j < total; j++)
				if (strcmp(stu[j].sex, "��") == 0)
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
		printf("�ļ���ʧ�ܡ�\n");
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
		printf("�ļ���ʧ�ܡ�\n");
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

void PrintMale()//�����ѧ����Ϣ
{
	Flag = 2;//ȷ������������ѧ����Ϣ
	f = 0;//�ӵ�һ��ѧ����Ϣ��ʼ���
	system("cls");
	printf("��ǰѧ����Ϣ��\n\n");
	prinStu();//���ѧ����Ϣ
	Return();
}

void PrintFemale()//���Ůѧ����Ϣ
{
	system("cls");
	printf("��ǰѧ����Ϣ��\n\n");
	f = swap;//�ӵ�swap��ѧ����Ϣ��ʼ���
	swap = total;//��������һ��ѧ����λ��
	prinStu();//���ѧ����Ϣ
	Return();//����
}