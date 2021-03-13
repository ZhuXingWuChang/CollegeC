// trouble.c -- 无用=会导致无限循环
#include <stdio.h>
/*
 * C Primer Plus 程序6.8。
 */
int main(void)
{
    long num;
    long sum = 0L;
    int status;

    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    status = scanf("%ld", &num);
    while (status = 1) // 这里是赋值表达式而不是条件表达式，使用 1 = status 的形式可以避免出错
    {
        sum += num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);

    return 0;
}