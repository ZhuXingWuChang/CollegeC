// scores_in.c -- 使用循环处理数组
#include <stdio.h>
#define SIZE 10
#define PAR 72
/*
 * 对程序6.19做的修改，模块化这3个for循环，使其更加紧凑。
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
    {
        scanf("%d", &score[index]);
        sum += score[index];
        average = sum / SIZE;
    }
    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That's a handicap of %.0f.\n", average - PAR);

    return 0;
}