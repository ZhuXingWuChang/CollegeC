/*
 * 需要一个count来存放用户指定的循环次数
 * 需要一个sum来保存级数和
 * 在循环体中对级数进行求和
 * 求和时可让分子固定不动，每次对分母进行递增
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
    long long count;
    double numerator = 1.0;                 // 分子
    double denominator = 1.0;               // 分母
    double sum_of_positive_series = 0.0;    // 正项级数和
    double sum_of_alternating_series = 0.0; // 交错级数和
    double positive_term;                   // 正项级数项
    double alternating_term;                // 交错级数项

    printf("Enter the number of loop: ");
    if (1 != scanf("%d", &count))
        return 0;

    if (0 != count)
    {
        for (long long i = 0; i < count; i++)
        {
            denominator += i;
            positive_term = numerator / denominator;                 // 正项级数的项
            alternating_term = pow(-1.0, (double)i) * positive_term; // 交错级数的项
            // printf("%lf     %lf\n", positive_term, alternating_term);    // 调试用
            sum_of_positive_series += positive_term;       // 对正项级数求和
            sum_of_alternating_series += alternating_term; // 对交错级数求和
        }
        printf("The sum of positive term is %lf .\n", sum_of_positive_series);
        printf("The sum of alternating term is %lf .\n", sum_of_alternating_series);
    }
    printf("Done\n");

    return 0;
}