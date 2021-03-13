/*
 * 用第一个int保存用户先输入的数——模
 * 用第二个int保存用户后输入的数——被求模数
 * 在此之后，用户可以多次输入新的被求模数，并且也会得到结果
 * 用一个while循环控制，一旦用户输入非整数，跳出循环
 */
#include <stdio.h>
int main(void)
{
    int num2 = 0; // 存放模
    int num1 = 0; // 存放被求模的数

    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as second operand: ");
    scanf("%d", &num2);
    printf("Now enter the first operand: ");
    scanf("%d", &num1);
    while (num1 > 0)
    {
        printf("%d %% %d is %d\n", num1, num2, num1 % num2);
        printf("Now enter the first operand (<=0 to quit): ");
        scanf("%d", &num1);
    }
    printf("Done\n");

    return 0;
}