// paint.c -- 使用条件运算符
#include <stdio.h>
#define COVERATE 350 // 每罐油漆可刷的面积（单位：平方英尺）
/*
 * C Primer Plus 程序7.8。
 */
int main(void)
{
    int sq_feet;
    int cans;

    printf("Enter number of square feet to be painted:\n");
    while (scanf("%d", &sq_feet) == 1)
    {
        cans = sq_feet / COVERATE;
        cans += ((sq_feet % COVERATE) == 0) ? 0 : 1;
        printf("You need %d %s of paint.\n", cans, cans == 1 ? "can" : "cans");
        printf("Enter next value (q to quit):\n");
    }

    return 0;
}