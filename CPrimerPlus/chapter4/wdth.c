/* width.c -- 字段宽度 */
#include <stdio.h>
#define PAGES 959
/*
 * C Primer Plus 程序4.7。
 */
int main(void)
{
    printf("*%d*\n", PAGES);
    printf("*%2d*\n", PAGES);
    printf("*%10d*\n", PAGES);
    printf("*%-10d*\n", PAGES);

    return 0;
}