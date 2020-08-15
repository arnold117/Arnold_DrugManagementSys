#include"la03.h"

//第一菜单
void menu()
{
	int i;

	//版权页
	printf("Arnold's Drug Managment System[version: 38]\n");
	printf("(c) 2019 Arnold Chow. All Rights Reserved\n\n\n");
	Sleep(100);
	//菜单界面
	printf("=============================================================================\n");
	Sleep(100);
	printf("1:> Administrator.\n");
	Sleep(100);
	printf("2:> Nomal User.\n");
	Sleep(100);
	printf("0:> Exit.\n");
	Sleep(100);
	printf("Please enter:");
	fflush(stdin);
	scanf("%d", &i);

	//选择功能
	switch (i)
	{
		//去往管理员登录界面
		case 1:
			login();
			break;
		//去往普通用户界面
		case 2:
			menu_n();
			break;
		//退出程序		
		case 0:
			exit(1);
		default:
			break;
	}
}