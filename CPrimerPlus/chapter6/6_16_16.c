/*
 * 需要两个常数存放利息，一个常数simple interest存放单利息
 * 另一个常数compound interest存放复合利息
 * 用Daphne's money储存Daphne的钱
 * 用Deirdre's money初春Deirdre的钱
 * 并且在一个while循环中判断，当Deirdre's money>=Daphne's money时
 * 退出循环
 */
#include <stdio.h>
#define SIMPLE_INSTEREST 0.1
#define COMPOUND_INSTEREST 0.05
int main(void)
{
    double da_money = 100.0; // Daphne的钱
    double de_money = 100.0; // Deirdre的钱
    int count = 0;

    while (da_money >= de_money)
    {
        da_money += 100.0 * SIMPLE_INSTEREST;
        de_money += de_money * COMPOUND_INSTEREST;
        count++;
    }
    printf("%d years, Deirdre is winner.\n", count);

    return 0;
}