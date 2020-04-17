#include"la03.h"

//普通用户界面
void menu_n()
{
	int i;

	//判断文件存在与否
	load_menu();

	//菜单界面
	do
	{
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Nomal\n");
		Sleep(100);
		printf("1:> Search Drug.\n");
		Sleep(100);
		printf("2:> Show Drug List.\n");
		Sleep(100);
		printf("0:> Exit.\n");
		printf("Please enter:");
		fflush(stdin);
		scanf("%d", &i);

		//选择功能
		switch (i)
		{
			//跳转到搜索界面
			case 1:
			{
				search_menu();
				system("pause");
				break;
			}
			//执行全部输出
			case 2:
			{
				showall();
				system("pause");
				break;
			}
			//退出程序
			case 0:
			{
				exit(3);
			}
			default:
				break;
		}
	} while (1);//无特殊情况一直循环

}