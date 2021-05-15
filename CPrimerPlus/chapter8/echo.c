// echo.c -- 重复输出
#include <stdio.h>
int main(void)
{
    char ch;

    while( (ch = getchar()) != '#')
        putchar(ch);

    return 0;
}