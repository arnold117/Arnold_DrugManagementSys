#include"la03.h"

//����Ա�˵�
void menu_a()
{
	int i;

	//�ж��ļ��������
	load_menu();

	//�˵�����
	do
	{
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Administrator\n");
		Sleep(100);
		printf("1:> Show Drug List\n");
		Sleep(100);
		printf("2:> Add New drug.\n");
		Sleep(100);
		printf("3:> Delete Drug.\n");
		Sleep(100);
		printf("4:> Edit Drug info.\n");
		Sleep(100);
		printf("5:> Search Drug.\n");
		Sleep(100);
		printf("0:> Exit.\n");
		Sleep(100);
		printf("Please enter:");
		fflush(stdin);
		scanf("%d", &i);

		//ѡ����
		switch (i)
		{
			//��ʾҩƷ�б�
			case 1:
				showall();
				system("pause");
				break;
			//��ת��������ӽ���
			case 2:
				add_menu();
				system("pause");
				break;
			//��ת��ɾ������
			case 3:
				del_menu();
				system("pause");
				break;
			//��ת���޸Ĳ˵�
			case 4:
				edit_menu();
				system("pause");
				break;
			//��ת����������
			case 5:
				search_menu();
				system("pause");
				break;
			//�˳�����
			case 0:
				exit(4);
			default:
				break;
		}
	} while (1);//���������һֱѭ��
}