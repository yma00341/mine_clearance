#define _CRT_SECRET_NO_WARNINGS 1
#include <stdio.h>
#include "SaoLei.h"

void test();
void menu();
void game();

int main()
{
	test();
	return 0;
}

void menu()
{
	printf("********************\n");
	printf("****   1.play   ****\n");
	printf("****   0.exit   ****\n");
	printf("********************\n");
}

void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("����������ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("���˳�!\n");
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (input);
}

void game()
{
	//�׵���Ϣ�洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };

	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	
	//��ӡ����
	Display(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	//Display(mine, ROW, COL);

	//ɨ��
	FindMine(mine, show, ROW, COL);
	
	system("cls");
}