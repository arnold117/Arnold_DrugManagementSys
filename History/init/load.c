#include"la03.h"

//������жϽ���
void load_menu()
{
	struct drug* head = NULL;
	char temp[2];

	//�ļ����ڣ������ʾ���
	if (load(DIR) != NULL)
	{
		printf("File Loaded!\n");
	}
	//�ļ�������
	else
	{
		printf("FILE DON'T EXIST!\n");
		Sleep(100);
		printf("Do you want to create file NOW?(y/n)\n");
		fflush(stdin);
		scanf("%s", temp);

		//�ǣ��½��ļ�
		if (strcmp("Y\0", temp) == 0 || strcmp("y\0", temp) == 0)
		{
			fopen(DIR, "w");
			printf("FILE CREATED!\n");
		}
		//���˳�����
		else
		{
			printf("NO FILE LOADED!\n");
			Sleep(100);
			printf("Program Terminated!\n");
			exit(5);
		}
	}
}

//�����ļ�
struct drug* load(const char* filename)
{
	FILE* fp = fopen(filename, "r");

	//�ļ������ڣ����� NULL
	if (fp == NULL)
	{
		return NULL;
	}

	//�ļ����ڣ�����¼����������ͷ�ڵ� head
	struct drug buf, * head = NULL;

	while (fscanf(fp, "%s %s %s %d", buf.name, buf.type, buf.usage, &buf.amount) > 0)
	{
		head = add(head, buf.name, buf.type, buf.usage, buf.amount);
	}

	return head;
}