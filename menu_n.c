#include"la03.h"

//��ͨ�û�����
void menu_n()
{
	int i;

	//�ж��ļ��������
	load_menu();

	//�˵�����
	do
	{
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Nomal\n");
		Sleep(100);
		printf("1:> Search Drug.\n");
		Sleep(100);
		printf("2:> Show Drug List.\n");
		Sleep(100);
		printf("0:> Exit.\n");
		printf("Please enter:");
		fflush(stdin);
		scanf("%d", &i);

		//ѡ����
		switch (i)
		{
			//��ת����������
			case 1:
			{
				search_menu();
				system("pause");
				break;
			}
			//ִ��ȫ�����
			case 2:
			{
				showall();
				system("pause");
				break;
			}
			//�˳�����
			case 0:
			{
				exit(3);
			}
			default:
				break;
		}
	} while (1);//���������һֱѭ��

}