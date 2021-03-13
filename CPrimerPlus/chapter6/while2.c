// while2.c -- 注意分号的位置
#include <stdio.h>
/*
 * C Primer Plus 程序6.4。
 */
int main(void)
{
    int n = 0;

    while (n++ < 3);
        printf("n is %d\n", n);
    printf("That's all this program dose\n");

    return 0;
}