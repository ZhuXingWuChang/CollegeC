// wheat.c -- 指数增长
#include <stdio.h>
#define SQUARES 64 // 棋盘中的方格数
/*
 * C Primer Plus 程序5.5。
 * “学者——国王——小麦”的故事。
 */
int main(void)
{
    const double CROP = 2E16; // 世界小麦年产谷粒数
    double current, total;    // current:当前小麦谷粒数   total:目标小麦颗粒数
    int count = 1;

    printf("square      grains      total       ");
    printf("fraction of \n");
    printf("            added       grains      ");
    printf("world total\n");
    total = current = 1.0; // 从1颗谷粒开始
    printf("%4d %13.2e %12.e %12.2e\n", count, current, total, total / CROP);

    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current; // 下一个方格谷粒反对
        total = total + current; // 更新总数
        printf("%4d %13.2e %12.e %12.2e\n", count, current, total, total / CROP);
    }
    printf("That's all.\n");

    return 0;
}