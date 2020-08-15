#include"la03.h"

//删除界面
void del_menu()
{
	struct drug* head = NULL;
	char name[30];
	int ok;
	
	//加载文件
	head = load(DIR);
	//提示及说明语句
	printf("Please enter name of Drug you want to Delete:");
	fflush(stdin);
	scanf("%s", name);
	head = del(head, name, &ok);

	//ok = 1，删除成功
	if (ok)
	{
		;
	}
	//ok = 0, 删除失败，说明项目不存在，输出提示语句
	else
	{
		printf("FILE DON'T EXIST!\n");
	}

	//保存到文件
	save(head, DIR);
}

struct drug* del(struct drug* head, const char* name, int *isok)
{
	// cur 为要删除的节点
	struct drug* cur = head, * prev = NULL;

	// 找到待删除节点 cur 和前一个节点 prev
	for (; cur != NULL; cur = cur->next)
	{
		if (strcmp(name, cur->name) == 0)
		{
			break;
		}

		prev = cur;
	}

	//项目不存在，删除失败，返回头指针
	if (cur == NULL)
	{
		*isok = 0;
		return head;
	}

	// 第一种情况，要删除的是第一个节点，返回新的头指针
	if (prev == NULL)
	{
		struct drug* new_head = cur->next;
		free(cur);
		return new_head;
	}
	// 第二种情况，要删除的节点位于中间或尾部
	else
	{
		prev->next = cur->next;
		free(cur);
	}

	//上述两种情况说明成功删除
	*isok = 1;

	return head;
}