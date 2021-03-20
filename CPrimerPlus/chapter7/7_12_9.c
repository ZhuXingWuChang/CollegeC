/*
 * 用户输入正整数a
 * 如果不是正整数：显示错误信息
 * 否则：
 * 遍历2到a之间的数
 *      调用函数——如果是素数：输出这个素数
 * -------------------------------
 * 函数——如果是素数
 * 默认标记这个数是素数
 * 如果比2小：标记为不是素数
 * 否则：
 * 对2到根号num遍历
 *      如果能被整除：标记为不是素数
 * 返回标记值
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
bool is_prime(int num);
int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 0)
        printf("Please enter a positive number!\n");
    else
        for (int i = 2; i <= num; i++)
            if (is_prime(i))
                printf("%d <= %d, and %d is a prime.\n", i, num, i);

    return 0;
}

bool is_prime(int num)
{
    bool flag = true;
    if (num < 2)
        flag = false;
    else
        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0)
                flag = false;

    return flag;
}