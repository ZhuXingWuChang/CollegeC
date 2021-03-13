/*
 * 通过修改程序5.13来达到计算赚钱的目的
 * 用一个int work_days来存放用户赚钱的天数
 * 并且每天赚的钱数就等于work_days
 * 再用一个int sum来存放赚了多少钱
 */
#include <stdio.h>
int main(void)
{
    int work_days = 0; // 声明&初始化
    int count, sum;

    count = 0; // 表达式语句
    sum = 0;   //  表达式语句

    printf("How many days do you want to work?\n");
    scanf("%d", &work_days);
    while (count++ < work_days) // 迭代语句
        sum += count;
    printf("sum = %d\n", sum);

    return 0;
}