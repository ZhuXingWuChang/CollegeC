// zeno.c -- 求序列的和
#include <stdio.h>
/*
 * C Primer Plus 程序6.14。
 */
int main(void)
{
    int t_ct;                // 项计数
    double time, power_of_2; // time保存2的n次幂的求和（总用时）, power_of_2保存2的n次幂（每一段的用时）
    int limit;

    printf("Enter the number of terms you want: ");
    scanf("%d", &limit);
    for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
    {
        time += 1.0 / power_of_2;
        printf("time = %f when terms = %d.\n", time, t_ct);
    }

    return 0;
}