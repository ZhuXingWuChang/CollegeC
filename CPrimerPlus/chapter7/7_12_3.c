/*
 * 读取整数，当读到的不是0
 *      如果用户输入的是奇数：奇数加一，奇数和增加
 *      否则：偶数加一，偶数和增加
 * 偶数求平均值
 * 奇数求平均值
 * 打印偶数个数，偶数平均值，奇数个数，奇数平均值
 */
#include <stdio.h>
int main(void)
{
    int num;
    short odd_ct = 0;
    short even_ct = 0;
    long odd_sum = 0;
    long even_sum = 0;
    double odd_average;
    double even_average;

    printf("Enter a number (0 to quit): ");
    while (scanf("%d", &num) == 1 && num != 0)
    {
        if (num % 2 != 0)
        {
            odd_ct++;
            odd_sum += num;
        }
        else
        {
            even_ct++;
            even_sum += num;
        }
        printf("Enter a number (0 to quit): ");
    }
    odd_average = (double)odd_sum / odd_ct;
    even_average = (double)even_sum / even_ct;
    printf("Odd number:  count = %-4d, sum = %-7d, average = %-.2lf.\n", odd_ct, odd_sum, odd_average);
    printf("Even number: count = %-4d, sum = %-7d, average = %-.2lf.\n", even_ct, even_sum, even_average);

    return 0;
}