/* prntval.c -- printf()的返回值 */
#include <stdio.h>
/*
 * C Primer Plus 程序4.13。
 */
int main(void)
{
    int bph2o = 212;
    int rv; // 用一个变量来记录printf()函数的返回值

    rv = printf("%d F is water's boiling point.\n", bph2o);
    printf("The printf() function printed %d characters.\n", rv);

    return 0;
}