// rowsl.c -- 使用嵌套循环
#include <stdio.h>
#define ROWS 6
#define CHARS 10
/*
 * C Primer Plus 程序6.17。
 */
int main(void)
{
    int row;
    char ch;

    for (row = 0; row < ROWS; row++)
    {
        for (ch = 'A'; ch < ('A' + CHARS); ch++)
            printf("%c", ch);
        printf("\n");
    }

    return 0;
}