#include"la03.h"

//插入添加界面
void add_menu()
{
	struct drug* head = NULL;
	char temp1[2];
	char name[30];
	char type[10];
	char usage[20];
	int amount;

	//加载文件
		head = load(DIR);
		//提示及说明语句
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System\\Administrator\\AddNewDrug:>\n");
		Sleep(100);
		printf("Please Enter:\n");

		//添加项目，按y继续操作
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
			//调用插入添加函数
			head = add(head, name, type, usage, amount);
			printf("Countinue?(y/n)\n");
			fflush(stdin);
			scanf("%s", temp1);

		} while (strcmp("Y\0", temp1) == 0 || strcmp("y\0", temp1) == 0);

		//保存到文件
		save(head, DIR);
}
// 向链表以 name 的字典序插入数据，返回值为链表的头节点
struct drug* add(struct drug* head, char* name, char* type, char* usage, int amount)
{
	// cur 为新增节点
	struct drug* cur = head, * prev = NULL;

	// 第一种情况，当 head == NULL 时，链表还没有创建，创建新链表
	if (cur == NULL)
	{
		head = cur = calloc(1, sizeof(struct drug));
	}
	else
	{
		// 找到待插入节点的后一个节点 cur 和前一个节点 prev
		for (; cur != NULL; cur = cur->next)
		{
			if (strcmp(name, cur->name) < 0)
			{
				break;
			}

			prev = cur;
		}

		// 第二种情况，当第一个节点比要插入节点大，待插入节点变为头节点
		if (prev == NULL)
		{
			struct drug* new_head = calloc(1, sizeof(struct drug));
			new_head->next = head;
			cur = head = new_head;
		}

		else
		{
			// 第三种情况，当要插入的节点位于中间
			if (prev != NULL && cur != NULL)
			{
				struct drug* new_node = calloc(1, sizeof(struct drug));
				prev->next = new_node;
				new_node->next = cur;
				cur = new_node;
			}
			// 第四种情况，要插入的节点为尾部，直接赋值原尾节点的next
			else
			{
				struct drug* new_tail = calloc(1, sizeof(struct drug));
				prev->next = new_tail;
				cur = new_tail;
			}
		}
	}

	// 开始赋值，填数据
	strcpy(cur->name, name);
	strcpy(cur->type, type);
	strcpy(cur->usage, usage);
	cur->amount = amount;

	return head;
}