#include"la03.h"

//搜索界面
void search_menu()
{
	struct drug* head = NULL, * temp = NULL;
	char name[30];

	//加载文件
		head = load(DIR);
		//提示及说明语句
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Search\n");
		Sleep(100);
		printf("Please enter name of Drug you want to Search:");
		fflush(stdin);
		scanf("%s", name);

		//返回值为 NULL ，项目不存在，输出提示语句
		if (search(head, name) == NULL)
		{
			printf("ITEM NOT EXIST!");
		}
		//返回值为项目对应节点指针，输出相关信息
		else
		{
			temp = search(head, name);
			printf("Name:%s Type:%s Usage:%s Amount:%d\n", temp->name, temp->type, temp->usage, temp->amount);
		}
}

// 搜索节点，找到返回该节点指针，没有找到返回空
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