// scores_in.c -- 使用循环处理数组
#include <stdio.h>
#define SIZE 10
#define PAR 72
/*
 * C Primer Plus 程序6.19。
 * 使用数组读取10个高尔夫分数，
 * 使用for循环来向数组里写入数值
 * 程序打印总分、平均分、差点（平均分与标准分的差值）
 */
int main(void)
{
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d golf scores:\n", SIZE);
    for (index = 0; index < SIZE; index++)
        scanf("%d", &score[index]); // 读取10个分数
    printf("The scores read in are as follows:\n");
    for (index = 0; index < SIZE; index++)
        printf("%5d", score[index]); // 验证输入
    printf("\n");
    for (index = 0; index < SIZE; index++)
        sum += score[index];     // 求总分数
    average = (float)sum / SIZE; // 求平均分
    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That's a handicap of %.0f.\n", average - PAR);

    return 0;
}