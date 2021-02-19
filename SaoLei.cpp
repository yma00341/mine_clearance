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
		printf("请输入您的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("已退出!\n");
			break;
		default:
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (input);
}

void game()
{
	//雷的信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };

	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	
	//打印棋盘
	Display(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//Display(mine, ROW, COL);

	//扫雷
	FindMine(mine, show, ROW, COL);
	
	system("cls");
}