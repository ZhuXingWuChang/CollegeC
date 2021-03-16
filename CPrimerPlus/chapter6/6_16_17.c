/*
 * 用常量定义年利率
 * 用常量定义取出的10万美元
 * 用一个double变量存储100万美元
 * 在while循环中的判断条件里判断double变量是否为0
 * 循环中执行操作e
 */
#include <stdio.h>
const double ANNUAL_INSTEREST_RATE = 0.08; // 定义年利率为8%
const double TEN_DOLLARS = 10.0;           // 取出的十万美元
int main(void)
{
    double balance = 100.0; // 初始一百万美元
    short year = 0;

    while (balance > 0.0)
    {
        balance *= (1 + ANNUAL_INSTEREST_RATE);
        balance -= TEN_DOLLARS;
        year++;
    }
    printf("After %d years, you have no money.\n", year);

    return 0;
}