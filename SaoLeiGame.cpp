#define _CRT_SECRET_NO_WARNINGS 1 
#include "SaoLei.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Display(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
}


void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<(row*col-EASY_COUNT))
	{
		printf("�������Ų������:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����Ϸ�
			//1.�ȵ��ף���ը��
			if (mine[x][y] == '1')
			{
				printf("���ź�����ʧ����!\n");
				Display(mine, row, col);
				printf("��ͼ1�����׵�λ��!\n");
				break;
			}
			//2.�����׵����
			else
			{
				//������Χ�ж��ٸ���
				int count = GetMineCount(mine,x,y);
				show[x][y] = count + '0';
				//Spread(mine,show, x, y);
				Display(show, row, col);
				win++;
			}

		}
		else
		{
			//����Ƿ�
			printf("����������������������!\n");
		}
	}
	if (win == (row*col - EASY_COUNT))
	{
		printf("��ϲ�㣬��Ӯ��!\n");
		Display(mine, row, col);
		printf("��ͼ1�����׵�λ��!\n");
	}
	Sleep(3000);
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

//void Spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
//{
//	if (mine[x - 1][y] != '1'&&
//		mine[x - 1][y - 1] != '1'&&
//		mine[x][y - 1] != '1'&&
//		mine[x + 1][y - 1] != '1'&&
//		mine[x + 1][y] != '1'&&
//		mine[x + 1][y + 1] != '1'&&
//		mine[x][y + 1] != '1'&&
//		mine[x - 1][y + 1] != '1')
//	{
//		show[x][y] = ' ';
//	}
//}