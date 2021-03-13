/*
 * 需要一个外层循环，控制行数
 * 需要一个内层循环，控制列数
 */
#include <stdio.h>
const int ROW = 6;
int main(void)
{
    char ch = '$';

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j <= ROW; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}