/*
 * 用一个int friend存储朋友的数量
 * 定义一个常量邓巴数，当朋友数量超过这个数的时候，跳出循环
 * 循环中负责对朋友数进行迭代
 */
#include <stdio.h>
#define DUNBAR_NUMBER 150
int main(void)
{
    int friend = 5;
    int week;

    while (friend <= DUNBAR_NUMBER)
    {
        friend --;
        friend *= 2;
    }
    printf("After %d weeks, you have a lot of friends.\n", week);

    return 0;
}