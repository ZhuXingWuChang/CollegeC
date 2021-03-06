/* showf_pt.c -- 以两种方式显示float类型的值 */
#include <stdio.h>
/*
 * C Primer Plus 程序3.7。
 */
int main(void)
{
    float aboat = 32000.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5; // 貌似是long double的long导致了下面的问题

    printf("%f can be written %e\n", aboat, aboat);
    // 下一行要求编译器支持C99或其中相关的特性
    printf("And it's %a in hexadecimal, power of 2 notation\n", aboat);
    printf("%f can be written %e\n", abet, abet);
    printf("%Lf can be written %Le\n", dip, dip); // 这里有问题但是我不知道原因

    return 0;
}