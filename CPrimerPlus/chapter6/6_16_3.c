/*
 * 需要一个外层循环，控制行数
 * 需要一个内层循环，控制列数
 * 因为第一行只有一列，第二行只有两列
 * 所以行数为i，那么列数j应该==i
 */
#include <stdio.h>
const int ROW = 6;
int main(void)
{
    char ch;

    for (int i = 0; i < ROW; i++)
    {
        ch = 'F';
        for (int j = 0; j <= i; j++)
        {
            printf("%c", ch--);
        }
        printf("\n");
    }

    return 0;
}