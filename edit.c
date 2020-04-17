#include"la03.h"

//�޸Ĳ˵�
void edit_menu()
{
	struct drug* head = NULL, *temp = NULL;
	char name[30];
	int i;

	//��ȡ�ļ�

		head = load(DIR);
		//˵������ʾ���
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Edit\n");
		Sleep(100);
		printf("Please enter name of Drug you want to Edit:");
		fflush(stdin);
		scanf("%s", name);
		//��������ֵΪ NULL ����Ŀ�����ڣ���ת����Ա�˵�
		if (search(head, name) == NULL)
		{
			printf("ITEM DON'T EXSIT!\n");
			system("pause");
			menu_a();
		}
		//��������ֵΪ��Ŀ��Ӧ�ڵ�ָ�룬���в���
		else
		{
			temp = search(head, name);
			//��ʾ��˵�����
			printf("Arnold's Drug Management System\\Edit\\%s:>\n", temp->name);
			Sleep(100);
			printf("1:> Edit Drug Name\n");
			Sleep(100);
			printf("2:> Edit Drug Type\n");
			Sleep(100);
			printf("3:> Edit Drug Usage\n");
			Sleep(100);
			printf("4:> Edit Drug Amount\n");
			Sleep(100);
			printf("0:> Return to Menu\n");
			Sleep(100);
			printf("Please enter:");
			fflush(stdin);
			scanf("%d", &i);

			//ѡ����
			switch (i)
			{
				//��תҩƷ���޸Ľ���
				case 1:
					head = edit_name(head, temp);
					break;
				//��ת����޸Ľ���
				case 2:
					head = edit_type(head, temp);
					break;
				//��ת�÷��޸Ľ���
				case 3:
					head = edit_usage(head, temp);
					break;
				//��ת�����޸Ľ���
				case 4:
					head = edit_amount(head, temp);
					break;
				case 5:
					exit(6);
				default:
					break;
			}

			//���浽�ļ�
			save(head, DIR);
		}
}

//�޸����ơ�ɾ��ԭ�ڵ㣬������ʱ�ڵ�
struct drug* edit_name(struct drug* head, struct drug* temp)
{ 
	int ok;
	char name[30];
	char type[10];
	char usage[20];
	int amount;

	printf("Please enter Name to replace %s:\n", temp->name);
	//��ԭ��Ϣ���Ƶ���ʱ������
	strcpy(name, temp->name);
	strcpy(type, temp->type);
	strcpy(usage, temp->usage);
	amount = temp->amount;
	//ɾ��ԭ�ڵ�
	head = del(head, temp->name, &ok);
	fflush(stdin);
	scanf("%s", name);
	//������ʱ�ڵ�
	head = add(head, name, type, usage, amount);

	return head;
}

//�޸�����
struct drug* edit_type(struct drug* head, struct drug* temp)
{
	printf("Western Medicine(WM) or Traditionnal Chinese Medicine(TCM)?\n");
	Sleep(100);
	printf("Please enter Type to replace %s:\n", temp->type);
	fflush(stdin);
	scanf("%s", temp->type);

	return head;
}

//�޸��÷�
struct drug* edit_usage(struct drug* head, struct drug* temp)
{
	printf("External(EX), Internal(IN) or Injection(IJ)?\n");
	Sleep(100);
	printf("Please enter Usage to replace %s:\n", temp->usage);
	fflush(stdin);
	scanf("%s", temp->usage);

	return head;
}

//�޸�����
struct drug* edit_amount(struct drug* head, struct drug* temp)
{
	printf("Please enter Amount to replace %d:\n", temp->amount);
	fflush(stdin);
	scanf("%d", &temp->amount);

	return head;
}