#include"test.h"

void menu()//�˵�����
{
	char a = 0;//һ���˵�����ѡ��
	do
	{
		menu0();//��ҳ�˵�
		printf("ѡ��ִ�еĹ�����ţ�");
		a= _getch();

		switch (a)
		{
		case '0'://�˳�
			system("cls");//�����Ļ����
			printf("���˳�ѧ����Ϣ����ϵͳ��\n");
			break;

		case '1'://��ѯ����
		{
			char b = 0;//�����˵�����ѡ��
			system("cls");

			do
			{
				menu1();//��ѯ�˵�
				printf("��ѡ���ѯ�ķ�ʽ: ");
				b = _getch();

				switch (b)
				{
				case '0'://������ҳ
					system("cls");
					printf("�ѷ�����ҳ\n");
					break;

				case '1':
					ChackName();//��ѧ��������ѯ
					system("cls");
					prinStu();//���ѧ����Ϣ
					SortNum();//��ѧ�ŷ���
					Return();//����
					break;

				case '2':
					ChackNum();//��ѧ��ѧ�Ų�ѯ
					system("cls");
					prinStu();//���ѧ����Ϣ
					Return();//����
					break;

				case '3':
					AllChack();//��ʾ����ѧ����Ϣ
					break;

				default:
					system("cls");
					printf("ѡ�����������ѡ��\n");
				}
			} while (b != '0');
		}
			break;

		case '2'://������
		{
			char b = 0;//�����˵�����ѡ��
			system("cls");

			do
			{
				menu2();//����˵�
				printf("��ѡ������ķ�ʽ��");
				b = _getch();

				switch (b)
				{
				case '0'://������ҳ
					system("cls");
					printf("�ѷ�����ҳ��\n");
					break;

				case '1'://��ѧ����������
				{
					char c = 0;//�����˵�ѡ��
					system("cls");

					do
					{
						menu4();//��������˵�
						printf("��ѡ���������ͣ�");
						c = _getch();

						switch (c)
						{
						case '0'://������һҳ
							system("cls");
							printf("�ѷ���\n");
							break;

						case '1':
							system("cls");
							printf("�Ѱ�ѧ�������������С�\n\n");
							SortNameUp();//��ѧ����������
							prin();//�������ѧ����Ϣ
							Return();//����
							break;

						case '2':
							system("cls");
							printf("�Ѱ�ѧ�������������С�\n\n");
							SortNameDown();//��ѧ����������
							prin();//�������ѧ����Ϣ
							Return();//����
							break;

						default:
							system("cls");
							printf("ѡ�����������ѡ��\n");
						}
					} while (c != '0');
				}
				break;

				case '2'://��ѧ����ѧ�ɼ�����
				{
					char c = 0;//�����˵�����ѡ��
					system("cls");
					do
					{
						menu4();//��ѧ�ɼ�����˵�
						printf("��ѡ���������ͣ�");
						c = _getch();

						switch (c)
						{
						case '0'://������һҳ
							system("cls");
							printf("�ѷ���\n");
							break;

						case '1':
							SortGradesUp();//��ѧ����ѧ�ɼ�����
							system("cls");
							printf("�Ѱ�ѧ����ѧ�ɼ��������С�\n\n");
							prin();//�������ѧ����Ϣ
							Return();//��Ϣ
							break;

						case '2':
							SortGradesDown();//��ѧ����ѧ�ɼ�����
							system("cls");
							printf("�Ѱ�ѧ����ѧ�ɼ��������С�\n\n");
							prin();//�������ѧ����Ϣ
							Return();//����
							break;

						default:
							system("cls");
							printf("ѡ�����������ѡ��\n");
						}
					} while (c != '0');
				}
				break;

				default:
					system("cls");
					printf("ѡ�����������ѡ��\n");
				}
			} while (b != '0');
		}
			break;

		case '3':
			AddStu();//����ѧ����Ϣ
			break;

		case '4':
		{
			char b = 0;//�����˵�����ѡ��
			system("cls");

			do
			{
				menu3();//����˵�
				printf("��ѡ��ɾ���ķ�ʽ��");
				b = _getch();

				switch (b)
				{
				case '0'://����
					system("cls");
					printf("�ѷ�����ҳ��\n");
					break;

				case '1':
					DeleteStu();//��ѧ������ɾ��
					break;

				case '2':
					DeleteNum();//��ѧ��ѧ��ɾ��
					break;

				default:
					system("cls");
					printf("ѡ�����������ѡ��\n");
				}
			} while (b != '0');
		}
			break;

		case '5':
			ChangeStu();//�޸�ѧ����Ϣ
			break;

		case '6':
		{
			char b = 0;//�����˵�����ѡ��
			SortSex();//��ѧ���Ա����
			system("cls");
			printf("����ɹ�\n");

			do
			{
				menu6();//ɾ���˵�
				printf("��ѡ��Ҫ�鿴����Ϣ��");
				b = _getch();

				switch (b)
				{
				case '0'://����
					system("cls");
					printf("�ѷ��ء�\n");
					break;

				case '1'://�����ѧ����Ϣ
					PrintMale();
					break;
				case '2'://���Ůѧ����Ϣ
					PrintFemale();
					break;

				default:
					system("cls");
					printf("ѡ�����������ѡ��\n");
				}
			}while(b != '0');
		}
			break;

		default:
			system("cls");
			printf("ѡ�����������ѡ��\n");
		}
	} while (a != '0');
}

void main()
{
	Fopen();//���ļ��������ļ�����
	menu();//��ʾ�˵�����
}