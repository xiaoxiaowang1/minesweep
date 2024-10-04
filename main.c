#include "game.h"
#include <stdio.h>

void menu()
{
    printf("************************\n");
    printf("******   1.扫雷   *******\n");
    printf("************************\n");
    printf("******   0.退出   *******\n");
    printf("************************\n");
}

int NumberL(char board[ROWS][COLS],int row,int col)
{
    int num = 0;
    for (int i = 1;i <= row;i++)
    {
        for (int j = 1;j <= col;j++)
        {
            if(board[i][j] == '*')
            {
                num++;
            }
        }
    }
    return num;
}

void Saolei()
{
    char mine[ROWS][COLS] = {0};
    InitBoard(mine,ROW,COL,'0');
    char show[ROWS][COLS] = {0};
    char ret = '0';

    //布置雷
    PutLei(mine,ROW,COL);
    // DisplayBoard(mine,ROW,COL);

    //可见棋盘
    InitBoard(show,ROW,COL,'*');
    DisplayBoard(show,ROW,COL);

    //布置雷附近参数
    int count = 0;
    while (1)
    {
        // DisplayBoard(mine,ROW,COL);        
        if (ret != '1')
        {
            count++;
        }
        ret = NumberLei(mine,show,ROW,COL);
        if (ret == 'c')
        {
            printf("踩到雷了！");
            break;
        }
        else if (ret == '0')
        {
            count = NumberL(show,ROW,COL);
            // printf("%d\n",count);
            if (count == EASY_COUNT)
            {
                printf("扫雷成功！");
            }
            DisplayBoard(show,ROW,COL);
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do
    {
        menu();
        printf("请选择->");
        scanf("%d",&input);
        switch(input)
        {
        case 1:
            Saolei();
            // printf("saolkei\n");
            break;
        case 0:
            printf("退出游戏！\n");
            break;
        default:
            printf("请重新选择！\n");
            break;
        }
    }while (input);
    return 0;
}