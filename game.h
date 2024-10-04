#ifndef _GAME_H__
#define _GAME_H__
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EASY_COUNT 10

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS],int row,int col, char set);

void DisplayBoard(char board[ROWS][COLS],int row,int col);

void PutLei(char board[ROWS][COLS],int row,int col);

void SearchLei(char board[ROWS][COLS], char show[ROWS][COLS],int x,int y,int row,int col);

char NumberLei(char board[ROWS][COLS],char show[ROWS][COLS], int row, int col);


#endif
