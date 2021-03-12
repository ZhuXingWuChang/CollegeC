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
        sum += count * count;
    printf("sum = %d\n", sum);

    return 0;
}