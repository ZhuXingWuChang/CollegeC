// pound.c -- 定义一个带参数的函数
#include <stdio.h>
/*
 * C Primer Plus 程序5.15。
 * 打印指定数量的编号符号（井号）。
 */
void pound(int n); // ANSI函数声明原型
int main(void)
{
    int times = 5;
    char ch = '!'; // ASCII码是33
    float f = 6.0f;

    pound(times); // int类型的参数
    pound(ch);    // 和pound((int)ch);相同
    pound(f);     // 和pound((int)f);相同

    return 0;
}

void pound(int n)
{
    while (n-- > 0)
        printf("#");
    printf("\n");
}