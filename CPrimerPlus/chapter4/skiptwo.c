// skiptwo.c -- 跳过输入中的前两个整数
#include <stdio.h>
/*
 * C Primer Plus 程序4.17。
 */
int main(void)
{
    int n;

    printf("Please enter three integers:\n");
    scanf("%*d %*d %d", &n);
    printf("The last integer was %d\n", n);

    return 0;
}