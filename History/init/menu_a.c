#include"la03.h"

//管理员菜单
void menu_a()
{
	int i;

	//判断文件存在与否
	load_menu();

	//菜单界面
	do
	{
		printf("=============================================================================\n");
		Sleep(100);
		printf("Arnold's Drug Management System:>Administrator\n");
		Sleep(100);
		printf("1:> Show Drug List\n");
		Sleep(100);
		printf("2:> Add New drug.\n");
		Sleep(100);
		printf("3:> Delete Drug.\n");
		Sleep(100);
		printf("4:> Edit Drug info.\n");
		Sleep(100);
		printf("5:> Search Drug.\n");
		Sleep(100);
		printf("0:> Exit.\n");
		Sleep(100);
		printf("Please enter:");
		fflush(stdin);
		scanf("%d", &i);

		//选择功能
		switch (i)
		{
			//显示药品列表
			case 1:
				showall();
				system("pause");
				break;
			//跳转至插入添加界面
			case 2:
				add_menu();
				system("pause");
				break;
			//跳转至删除界面
			case 3:
				del_menu();
				system("pause");
				break;
			//跳转至修改菜单
			case 4:
				edit_menu();
				system("pause");
				break;
			//跳转至搜索界面
			case 5:
				search_menu();
				system("pause");
				break;
			//退出程序
			case 0:
				exit(4);
			default:
				break;
		}
	} while (1);//无特殊情况一直循环
}