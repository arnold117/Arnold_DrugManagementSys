#include"la03.h"

//�������ҩƷ
void showall()
{
	struct drug* head = NULL, * p = NULL;

	//�����ļ�
		head = load(DIR);
		//˵�����
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>ShowALL\n");
		Sleep(100);
		printf("-----------Result---------\n");
		Sleep(100);

		//ѭ�����
		for (p = head; p != NULL; p = p->next)
		{
			printf("Name:%s Type:%s Usage:%s Amount:%d\n", p->name, p->type, p->usage, p->amount);
			Sleep(100);
		}
}