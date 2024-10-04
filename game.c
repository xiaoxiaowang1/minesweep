#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= row; i++)
    {
        for (j = 0; j <= col; j++)
        {
            board[i][j] = set;
        }
    }
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    printf("----------扫雷游戏------------\n");
    for (j = 0; j < COLS - 1; j++)
    {
        printf("%d ",j);
    }
    printf("\n");
    for (i = 1; i < ROWS - 1; i++)
    {
        printf("%d ",i);
        for (j = 1; j < COLS - 1; j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
    printf("----------扫雷游戏------------\n");
}

void PutLei(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int i = rand() % row + 1;
        int j = rand() % col +1;
        if (board[i][j] == '0')
        {
            board[i][j] = '1';
            count--;
        }
    }
}

// void SearchLei(char board[ROWS][COLS], char show[ROWS][COLS],int x,int y,int row,int col)
// {
//     int sum = 0;
//     for (int i = x-1;i <= x+1;i++)
//     {
//         for (int j = y-1; j <= y + 1; j++)
//         {
//             if (board[i][j] == '1')
//             {
//                 sum++;
//             }
//         }
//     }
//     if (sum == 0)
//     {
//         show[x][y] = ' ';
//         if(x-1 > 1 && y-1 > 1 && x+1 < row && y+1 <col)
//         {
//             SearchLei(board,show,x-1,y-1,row,col);
//             SearchLei(board,show,x-1,y+1,row,col);
//             SearchLei(board,show,x-1,y,row,col);
//             SearchLei(board,show,x+1,y-1,row,col);
//             SearchLei(board,show,x+1,y+1,row,col);
//             SearchLei(board,show,x+1,y,row,col);
//             SearchLei(board,show,x,y-1,row,col);
//             SearchLei(board,show,x,y+1,row,col);
//         }else if (x-1 == 1 && y-1 == 1)
//         {
//             SearchLei(board,show,x+1,y,row,col);
//             SearchLei(board,show,x,y+1,row,col);
//             SearchLei(board,show,x+1,y+1,row,col);
//         }
//         else if (x-1 == 1 && y+1 == col)
//         {
//             SearchLei(board,show,x-1,y,row,col);
//             SearchLei(board,show,x+1,y-1,row,col);
//             SearchLei(board,show,x+1,y,row,col);
//         }else if (x+1 == row && y-1 == 1)
//         {
//             SearchLei(board,show,x-1,y+1,row,col);
//             SearchLei(board,show,x,y+1,row,col);
//             SearchLei(board,show,x-1,y,row,col);
//         }else if (x+1 == row && y+1 == col)
//         {
//             SearchLei(board,show,x,y-1,row,col);
//             SearchLei(board,show,x-1,y-1,row,col);
//             SearchLei(board,show,x-1,y,row,col);
//         }else if (x-1 == 1 && y-1 != 1 && y+1 !=col)
//         {
//             SearchLei(board,show,x+1,y-1,row,col);
//             SearchLei(board,show,x+1,y+1,row,col);
//             SearchLei(board,show,x+1,y,row,col);
//             SearchLei(board,show,x,y-1,row,col);
//             SearchLei(board,show,x,y+1,row,col);
//         }else if (x+1 == row && y-1 != 1 && y+1 !=col)
//         {
//             SearchLei(board,show,x-1,y-1,row,col);
//             SearchLei(board,show,x-1,y+1,row,col);
//             SearchLei(board,show,x-1,y,row,col);
//             SearchLei(board,show,x,y-1,row,col);
//             SearchLei(board,show,x,y+1,row,col);
//         }else if (y-1 == 1 && x-1 != 1 && x+1 !=row)
//         {
//             SearchLei(board,show,x-1,y+1,row,col);
//             SearchLei(board,show,x-1,y,row,col);
//             SearchLei(board,show,x+1,y+1,row,col);
//             SearchLei(board,show,x+1,y,row,col);
//             SearchLei(board,show,x,y+1,row,col);
//         }else if (y+1 == col && x-1 != 1 && x+1 !=row)
//         {
//             SearchLei(board,show,x-1,y-1,row,col);
//             SearchLei(board,show,x-1,y,row,col);
//             SearchLei(board,show,x+1,y-1,row,col);
//             SearchLei(board,show,x+1,y,row,col);
//             SearchLei(board,show,x,y-1,row,col);
//         }
//     }
//     else
//     {
//         show[x][y] = sum + '0';
//     }
// }

void SearchLei(char board[ROWS][COLS], char show[ROWS][COLS],int x,int y,int row,int col)
{
    int sum = 0;
    if (x >= 1 && x <= row && y >= 1 && y <= col)
    {
        for (int i = x-1;i <= x+1;i++)
        {
            for (int j = y-1; j <= y + 1; j++)
            {
                if (board[i][j] == '1')
                {
                    sum++;
                }
            }
        }
        if (sum == 0)
        {
            show[x][y] = ' ';
            if (show[x-1][y-1] == '*')
            {
                SearchLei(board,show,x-1,y-1,row,col);
            }
            if (show[x-1][y+1] == '*')
            {
                SearchLei(board,show,x-1,y+1,row,col);
            }
            if (show[x-1][y] == '*')
            {
                SearchLei(board,show,x-1,y,row,col);
            }
            if (show[x+1][y-1] == '*')
            {
                SearchLei(board,show,x+1,y-1,row,col);
            }
            if (show[x+1][y+1] == '*')
            {
                SearchLei(board,show,x+1,y+1,row,col);
            }
            if (show[x+1][y] == '*')
            {
                SearchLei(board,show,x+1,y,row,col);
            }
            if (show[x][y-1] == '*')
            {
                SearchLei(board,show,x,y-1,row,col);
            }
            if (show[x][y+1] == '*')
            {
                SearchLei(board,show,x,y+1,row,col);
            }
        }
        else
        {
            show[x][y] = sum + '0';
        }
    }
}


char NumberLei(char board[ROWS][COLS], char show[ROWS][COLS],int row,int col)
{
    printf("请选择->");
    int x = 0;
    int y = 0;
    char ret = '0';
    scanf("%d %d",&x,&y);
    if (x >= 1 && x <= row && y >= 1 && y <= col)
    {
        int i = 0;
        int j = 0;
        if (board[x][y] == '1')
        {
            ret = 'c';
            return ret;
        }
        else
        {
            // int sum = 0;
            // for (i = x-1;i <= x+1;i++)
            // {
            //     for (j = y-1; j <= y + 1; j++)
            //     {
            //         if (board[i][j] == '1')
            //         {
            //             sum++;
            //         }
            //     }
            // }
            // show[x][y] = sum + '0';
            // ret = '0';
            // return ret;

            //大面积展开
            SearchLei(board,show,x,y,row,col);
            ret = '0';
            return ret;
        }
    }
    else
    {
        printf("坐标非法，请重新选择！\n");
        ret = '1';
        return ret;
    }
}