#include"la03.h"

//��һ�˵�
void menu()
{
	int i;

	//��Ȩҳ
	printf("Arnold's Drug Managment System[version: 38]\n");
	printf("(c) 2019 Arnold Chow. All Rights Reserved\n\n\n");
	Sleep(100);
	//�˵�����
	printf("=============================================================================\n");
	Sleep(100);
	printf("1:> Administrator.\n");
	Sleep(100);
	printf("2:> Nomal User.\n");
	Sleep(100);
	printf("0:> Exit.\n");
	Sleep(100);
	printf("Please enter:");
	fflush(stdin);
	scanf("%d", &i);

	//ѡ����
	switch (i)
	{
		//ȥ������Ա��¼����
		case 1:
			login();
			break;
		//ȥ����ͨ�û�����
		case 2:
			menu_n();
			break;
		//�˳�����		
		case 0:
			exit(1);
		default:
			break;
	}
}