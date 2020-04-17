#include"la03.h"

//��������
void search_menu()
{
	struct drug* head = NULL, * temp = NULL;
	char name[30];

	//�����ļ�
		head = load(DIR);
		//��ʾ��˵�����
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Search\n");
		Sleep(100);
		printf("Please enter name of Drug you want to Search:");
		fflush(stdin);
		scanf("%s", name);

		//����ֵΪ NULL ����Ŀ�����ڣ������ʾ���
		if (search(head, name) == NULL)
		{
			printf("ITEM NOT EXIST!");
		}
		//����ֵΪ��Ŀ��Ӧ�ڵ�ָ�룬��������Ϣ
		else
		{
			temp = search(head, name);
			printf("Name:%s Type:%s Usage:%s Amount:%d\n", temp->name, temp->type, temp->usage, temp->amount);
		}
}

// �����ڵ㣬�ҵ����ظýڵ�ָ�룬û���ҵ����ؿ�
struct drug* search(struct drug* head, const char* name)
{
	for (struct drug* cur = head; cur != NULL; cur = cur->next)
	{
		if (strcmp(name, cur->name) == 0)
		{
			return cur;
		}
	}

	return NULL;
}