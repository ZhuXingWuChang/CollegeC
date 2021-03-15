/*
 * 用两个double变量来存储用户的输入
 * 在循环条件中判断，如果用户输入非数字，退出循环
 * 在循环体中，执行运算操作
 */
#include <stdio.h>
int main(void)
{
    double num1, num2;

    printf("********************************\n");
    printf("Enter two unequal numbers: ");
    while (2 == scanf("%lf%lf", &num1, &num2) && num1 != num2)
    {
        double number = (num1 - num2) / (num1 * num2);
        printf("(a-b) / (a*b) = %lf\n", number);
        printf("Enter two unequal numbers: ");
    }
    printf("Your entering is error!");
    printf("********************************\n");

    return 0;
}