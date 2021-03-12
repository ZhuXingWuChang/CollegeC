// addemup.c -- 几种常见的语句
#include <stdio.h>
/*
 * C Primer Plus 程序5.13。
 */
int main(void)
{
    int count, sum; // 声明

    count = 0;           // 表达式语句
    sum = 0;             //  表达式语句
    while (count++ < 20) // 迭代语句
        sum += count;
    printf("sum = %d\n", sum);

    return 0;
}