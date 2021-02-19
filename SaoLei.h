#define _CRT_SECRET_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>	//rand
#include <time.h>
#include <windows.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void Display(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS],int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);
//void Spread(char mine[ROWS][COLS], char show[ROWS][COLS],int x, int y);