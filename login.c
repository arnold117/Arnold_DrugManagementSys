#include"la03.h"

//����Ա��¼����
void login()
{
	char user[20];
	char pw[20];
	// count Ϊ���볢�Դ���
	int count = 0, i = 0;

	//����Ա�˻������趨
	char user1[20] = "Arnold\0";
	char pw1[20] = "114514\0";


	//��¼����
	do
	{
		//�����û���������
		printf("=============================================================================\n");
		Sleep(100);
		printf("Drugs Management System\n");
		Sleep(100);
		printf("=============================================================================\n");
		Sleep(100);
		printf("��Admin Login��\n");
		Sleep(100);
		printf("User:");
		fflush(stdin);
		scanf("%s", user);
		printf("Password:");
		fflush(stdin);

		//��������ʱ����
		while ((pw[i] = getch()) != '\r')
		{
			if (pw[i] == '\b')
			{
				printf("\b \b");
				i--;
			}
			else
			{
				printf("*");
				i++;
			}
		}

		pw[i] = '\0';
		printf("\n");

		//�ж��û����������Ƿ���ȷ����ȷ��ת����Ա����
		if (strcmp(user, user1) == 0 && strcmp(pw, pw1) == 0)
		{
			menu_a();
			break;
		}
		//��������
		else
		{
			printf("ACCESS DENIED!\n");
			count++;
			system("pause");
		}

		if (count >= 3)//���Դ����������Σ��˳�����
		{
			printf("Program terminated!\n");
			exit(2);
		}
	} while (1);//���������һֱѭ��
}
