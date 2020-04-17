#include"la03.h"

//������ӽ���
void add_menu()
{
	struct drug* head = NULL;
	char temp1[2];
	char name[30];
	char type[10];
	char usage[20];
	int amount;

	//�����ļ�
		head = load(DIR);
		//��ʾ��˵�����
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System\\Administrator\\AddNewDrug:>\n");
		Sleep(100);
		printf("Please Enter:\n");

		//�����Ŀ����y��������
		do
		{
			printf("Drug Name?\n");
			fflush(stdin);
			scanf("%s", name);
			printf("Western Medicine(WM) or Traditionnal Chinese Medicine(TCM)?\n");
			fflush(stdin);
			scanf("%s", type);
			printf("External(EX), Internal(IN) or Injection(IJ)?\n");
			fflush(stdin);
			scanf("%s", usage);
			printf("Amount?\n");
			fflush(stdin);
			scanf("%d", &amount);
			//���ò�����Ӻ���
			head = add(head, name, type, usage, amount);
			printf("Countinue?(y/n)\n");
			fflush(stdin);
			scanf("%s", temp1);

		} while (strcmp("Y\0", temp1) == 0 || strcmp("y\0", temp1) == 0);

		//���浽�ļ�
		save(head, DIR);
}
// �������� name ���ֵ���������ݣ�����ֵΪ�����ͷ�ڵ�
struct drug* add(struct drug* head, char* name, char* type, char* usage, int amount)
{
	// cur Ϊ�����ڵ�
	struct drug* cur = head, * prev = NULL;

	// ��һ��������� head == NULL ʱ������û�д���������������
	if (cur == NULL)
	{
		head = cur = calloc(1, sizeof(struct drug));
	}
	else
	{
		// �ҵ�������ڵ�ĺ�һ���ڵ� cur ��ǰһ���ڵ� prev
		for (; cur != NULL; cur = cur->next)
		{
			if (strcmp(name, cur->name) < 0)
			{
				break;
			}

			prev = cur;
		}

		// �ڶ������������һ���ڵ��Ҫ����ڵ�󣬴�����ڵ��Ϊͷ�ڵ�
		if (prev == NULL)
		{
			struct drug* new_head = calloc(1, sizeof(struct drug));
			new_head->next = head;
			cur = head = new_head;
		}

		else
		{
			// �������������Ҫ����Ľڵ�λ���м�
			if (prev != NULL && cur != NULL)
			{
				struct drug* new_node = calloc(1, sizeof(struct drug));
				prev->next = new_node;
				new_node->next = cur;
				cur = new_node;
			}
			// �����������Ҫ����Ľڵ�Ϊβ����ֱ�Ӹ�ֵԭβ�ڵ��next
			else
			{
				struct drug* new_tail = calloc(1, sizeof(struct drug));
				prev->next = new_tail;
				cur = new_tail;
			}
		}
	}

	// ��ʼ��ֵ��������
	strcpy(cur->name, name);
	strcpy(cur->type, type);
	strcpy(cur->usage, usage);
	cur->amount = amount;

	return head;
}