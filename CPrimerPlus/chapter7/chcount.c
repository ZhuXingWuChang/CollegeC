// chcount.c -- 使用逻辑运算符
#include <stdio.h>
#define PERIOD '.'
/*
 * C Primer Plus 程序7.6。
 */
int main(void)
{
    char ch;
    int charcount = 0;

    while ((ch = getchar()) != PERIOD)
    {
        if (ch != '"' && ch != '\'')
            charcount++;
    }
    printf("There are %d non-quote characters.\n", charcount);

    return 0;
}