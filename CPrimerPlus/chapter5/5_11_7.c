/*
 * 需要设计一个square函数，得到一个double值，return这个值的平方数并打印
 * 在main函数中调用它可以起到求平方的作用
 */
#include <stdio.h>
double print_square(double);
int main(void)
{
    double num; // 用来存放用户输入的数

    printf("Enter a double type number: ");
    scanf("%lf", &num);
    print_square(num);

    return 0;
}

double print_square(double number)
{
    printf("%.2lf squared is equal to %.2lf.\n", number, number * number);

    return number * number;
}