#include"la03.h"

//管理员登录界面
void login()
{
	char user[20];
	char pw[20];
	// count 为密码尝试次数
	int count = 0, i = 0;

	//管理员账户密码设定
	char user1[20] = "Arnold\0";
	char pw1[20] = "114514\0";


	//登录界面
	do
	{
		//输入用户名和密码
		printf("=============================================================================\n");
		Sleep(100);
		printf("Drugs Management System\n");
		Sleep(100);
		printf("=============================================================================\n");
		Sleep(100);
		printf("【Admin Login】\n");
		Sleep(100);
		printf("User:");
		fflush(stdin);
		scanf("%s", user);
		printf("Password:");
		fflush(stdin);

		//输入密码时隐藏
		while ((pw[i] = getch()) != '\r')
		{
			if (pw[i] == '\b')
			{
				printf("\b \b");
				i--;
			}
			else
			{
				printf("*");
				i++;
			}
		}

		pw[i] = '\0';
		printf("\n");

		//判断用户名和密码是否正确，正确跳转管理员界面
		if (strcmp(user, user1) == 0 && strcmp(pw, pw1) == 0)
		{
			menu_a();
			break;
		}
		//错误重试
		else
		{
			printf("ACCESS DENIED!\n");
			count++;
			system("pause");
		}

		if (count >= 3)//尝试次数超过三次，退出程序
		{
			printf("Program terminated!\n");
			exit(2);
		}
	} while (1);//无特殊情况一直循环
}
