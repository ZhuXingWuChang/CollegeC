// cmpflt.c -- 浮点数比较
#include <math.h>
#include <stdio.h>
/*
 * C Primer Plus 程序6.5。
 */
int main(void)
{
    const double ANSWER = 3.14159;
    double response;

    printf("What is the value of pi?\n");
    scanf("%lf", &response);
    while (fabs(response - ANSWER) > 0.0001)
    {
        printf("Try again!\n");
        scanf("%lf", &response);
    }
    printf("Close enough!\n");

    return 0;
}