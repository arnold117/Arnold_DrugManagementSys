#ifndef _LA03_H_

#define _LA03_H_

//��Ҫ��ͷ�ļ�
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>

// ����ҩƷ�ṹ��
struct drug
{
	char name[30], type[10], usage[20];
	int amount;
	struct drug* next;
};

//ʹ�õĺ�������
void menu();
void login();
void menu_n();
void menu_a();
void load_menu();
struct drug* load(const char* filename);
void showall();
void search_menu();
struct drug* search(struct drug* head, const char* name);
void add_menu();
struct drug* add(struct drug* head, char* name, char* type, char* usage, int amount);
void del_menu();
struct drug* del(struct drug* head, const char* name);
void edit_menu();
struct drug* edit_name(struct drug* head, struct drug* temp);
struct drug* edit_type(struct drug* head, struct drug* temp);
struct drug* edit_usage(struct drug* head, struct drug* temp);
struct drug* edit_amount(struct drug* head, struct drug* temp);
void save(struct drug* head, const char* filename);

//�ļ���ַ
#define DIR "D:\\databin2.txt"

#endif // !_LA03_H_

