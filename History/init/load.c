#include"la03.h"

//进入的判断界面
void load_menu()
{
	struct drug* head = NULL;
	char temp[2];

	//文件存在，输出提示语句
	if (load(DIR) != NULL)
	{
		printf("File Loaded!\n");
	}
	//文件不存在
	else
	{
		printf("FILE DON'T EXIST!\n");
		Sleep(100);
		printf("Do you want to create file NOW?(y/n)\n");
		fflush(stdin);
		scanf("%s", temp);

		//是，新建文件
		if (strcmp("Y\0", temp) == 0 || strcmp("y\0", temp) == 0)
		{
			fopen(DIR, "w");
			printf("FILE CREATED!\n");
		}
		//否，退出程序
		else
		{
			printf("NO FILE LOADED!\n");
			Sleep(100);
			printf("Program Terminated!\n");
			exit(5);
		}
	}
}

//加载文件
struct drug* load(const char* filename)
{
	FILE* fp = fopen(filename, "r");

	//文件不存在，返回 NULL
	if (fp == NULL)
	{
		return NULL;
	}

	//文件存在，依次录入链表，返回头节点 head
	struct drug buf, * head = NULL;

	while (fscanf(fp, "%s %s %s %d", buf.name, buf.type, buf.usage, &buf.amount) > 0)
	{
		head = add(head, buf.name, buf.type, buf.usage, buf.amount);
	}

	return head;
}