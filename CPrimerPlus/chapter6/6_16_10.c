/*
 * 需要两个int变量存放用户输入的上限整数和下限整数
 * 循环条件用scanf来判断，当用户输入的上限<=下限，或输入违法时，结束循环
 * 循环体内，用一个for循环算出上限到下限之间所有整数的平方和
 * 最后输出求和的结果
 */
#include <stdio.h>
int main(void)
{
    int upper, lower;

    printf("Enter lower and upper integer limits: ");
    while (2 == scanf("%d%d", &lower, &upper) && upper > lower)
    {
        int sum = 0;
        for (int i = upper; i >= lower; i--)
            sum += i * i;
        printf("The sum of the squares from %d to %d is %d\n", lower * lower, upper * upper, sum);
        printf("Enter next set of limits: ");
    }
    printf("Done\n");

    return 0;
}