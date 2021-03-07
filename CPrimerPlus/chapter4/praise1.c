/* praise1.c -- 使用不同类型的字符串 */
#include <stdio.h>
#define PRAISE "You are an extraordinary being."
/*
 * C Primer Plus 程序4.2。
 */
int main(void)
{
    char name[40];

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);

    return 0;
}