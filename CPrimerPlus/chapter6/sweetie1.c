// sweetie1.c -- 一个计数循环
#include <stdio.h>
/*
 * C Primer Plus 程序6.10。
 */
int main(void)
{
    const int NUMBER = 22;
    int count = 1;

    while (count <= NUMBER)
    {
        printf("Be my Valentine!\n");
        count++;
    }

    return 0;
}