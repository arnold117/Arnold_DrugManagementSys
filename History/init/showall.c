#include"la03.h"

//输出所有药品
void showall()
{
	struct drug* head = NULL, * p = NULL;

	//加载文件
		head = load(DIR);
		//说明语句
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>ShowALL\n");
		Sleep(100);
		printf("-----------Result---------\n");
		Sleep(100);

		//循环输出
		for (p = head; p != NULL; p = p->next)
		{
			printf("Name:%s Type:%s Usage:%s Amount:%d\n", p->name, p->type, p->usage, p->amount);
			Sleep(100);
		}
}