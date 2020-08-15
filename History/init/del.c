#include"la03.h"

//ɾ������
void del_menu()
{
	struct drug* head = NULL;
	char name[30];
	int ok;
	
	//�����ļ�
	head = load(DIR);
	//��ʾ��˵�����
	printf("Please enter name of Drug you want to Delete:");
	fflush(stdin);
	scanf("%s", name);
	head = del(head, name, &ok);

	//ok = 1��ɾ���ɹ�
	if (ok)
	{
		;
	}
	//ok = 0, ɾ��ʧ�ܣ�˵����Ŀ�����ڣ������ʾ���
	else
	{
		printf("FILE DON'T EXIST!\n");
	}

	//���浽�ļ�
	save(head, DIR);
}

struct drug* del(struct drug* head, const char* name, int *isok)
{
	// cur ΪҪɾ���Ľڵ�
	struct drug* cur = head, * prev = NULL;

	// �ҵ���ɾ���ڵ� cur ��ǰһ���ڵ� prev
	for (; cur != NULL; cur = cur->next)
	{
		if (strcmp(name, cur->name) == 0)
		{
			break;
		}

		prev = cur;
	}

	//��Ŀ�����ڣ�ɾ��ʧ�ܣ�����ͷָ��
	if (cur == NULL)
	{
		*isok = 0;
		return head;
	}

	// ��һ�������Ҫɾ�����ǵ�һ���ڵ㣬�����µ�ͷָ��
	if (prev == NULL)
	{
		struct drug* new_head = cur->next;
		free(cur);
		return new_head;
	}
	// �ڶ��������Ҫɾ���Ľڵ�λ���м��β��
	else
	{
		prev->next = cur->next;
		free(cur);
	}

	//�����������˵���ɹ�ɾ��
	*isok = 1;

	return head;
}