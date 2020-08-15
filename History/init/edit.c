#include"la03.h"

//修改菜单
void edit_menu()
{
	struct drug* head = NULL, *temp = NULL;
	char name[30];
	int i;

	//读取文件

		head = load(DIR);
		//说明及提示语句
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Edit\n");
		Sleep(100);
		printf("Please enter name of Drug you want to Edit:");
		fflush(stdin);
		scanf("%s", name);
		//搜索返回值为 NULL ，项目不存在，跳转管理员菜单
		if (search(head, name) == NULL)
		{
			printf("ITEM DON'T EXSIT!\n");
			system("pause");
			menu_a();
		}
		//搜索返回值为项目对应节点指针，进行操作
		else
		{
			temp = search(head, name);
			//提示及说明语句
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

			//选择功能
			switch (i)
			{
				//跳转药品名修改界面
				case 1:
					head = edit_name(head, temp);
					break;
				//跳转类别修改界面
				case 2:
					head = edit_type(head, temp);
					break;
				//跳转用法修改界面
				case 3:
					head = edit_usage(head, temp);
					break;
				//跳转数量修改界面
				case 4:
					head = edit_amount(head, temp);
					break;
				case 5:
					exit(6);
				default:
					break;
			}

			//保存到文件
			save(head, DIR);
		}
}

//修改名称。删除原节点，插入临时节点
struct drug* edit_name(struct drug* head, struct drug* temp)
{ 
	int ok;
	char name[30];
	char type[10];
	char usage[20];
	int amount;

	printf("Please enter Name to replace %s:\n", temp->name);
	//将原信息复制到临时变量上
	strcpy(name, temp->name);
	strcpy(type, temp->type);
	strcpy(usage, temp->usage);
	amount = temp->amount;
	//删除原节点
	head = del(head, temp->name, &ok);
	fflush(stdin);
	scanf("%s", name);
	//插入临时节点
	head = add(head, name, type, usage, amount);

	return head;
}

//修改类型
struct drug* edit_type(struct drug* head, struct drug* temp)
{
	printf("Western Medicine(WM) or Traditionnal Chinese Medicine(TCM)?\n");
	Sleep(100);
	printf("Please enter Type to replace %s:\n", temp->type);
	fflush(stdin);
	scanf("%s", temp->type);

	return head;
}

//修改用法
struct drug* edit_usage(struct drug* head, struct drug* temp)
{
	printf("External(EX), Internal(IN) or Injection(IJ)?\n");
	Sleep(100);
	printf("Please enter Usage to replace %s:\n", temp->usage);
	fflush(stdin);
	scanf("%s", temp->usage);

	return head;
}

//修改数量
struct drug* edit_amount(struct drug* head, struct drug* temp)
{
	printf("Please enter Amount to replace %d:\n", temp->amount);
	fflush(stdin);
	scanf("%d", &temp->amount);

	return head;
}