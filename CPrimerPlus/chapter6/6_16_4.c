/*
 * 外层循环i控制行，内层循环控制列j
 * 注意行数=列数，所以j<=i
 */
#include <stdio.h>
const int ROW = 6;
int main(void)
{
    char ch = 'A';

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c", ch++);
        }
        printf("\n");
    }

    return 0;
}