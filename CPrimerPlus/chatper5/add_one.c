// add_one.c -- 递增：前缀和后缀
#include <stdio.h>
/*
 * C Primer Plus 程序5.10。
 */
int main(void)
{
    int ultra = 0, super = 0;

    while (super < 5)
    {
        super++;
        ++ultra;
        printf("super = %d, ultra = %d \n", super, ultra);
    }

    return 0;
}