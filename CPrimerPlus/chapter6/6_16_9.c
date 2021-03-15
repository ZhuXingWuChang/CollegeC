/*
 * 用两个double变量来存储用户的输入
 * 在循环条件中判断，如果用户输入非数字，退出循环
 * 在循环体中，调用calculate函数
 * calculate函数返回计算的结果
 */
#include <stdio.h>
double calculate(double, double);
int main(void)
{
    double num1, num2;

    printf("********************************\n");
    printf("Enter two unequal numbers: ");
    while (2 == scanf("%lf%lf", &num1, &num2) && num1 != num2)
    {
        printf("(a-b) / (a*b) = %lf\n", calculate(num1, num2));
        printf("Enter two unequal numbers: ");
    }
    printf("Your entering is error!\n");
    printf("********************************\n");

    return 0;
}
double calculate(double num1, double num2)
{
    double number = (num1 - num2) / (num1 * num2);

    return number;
}