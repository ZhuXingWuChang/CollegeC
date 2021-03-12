/*
 * 为了把min -> hour&min，首先，我们需要一个输入一个分钟数存在变量min里面
 * 然后对这个min进行除运算，得到一个小时数，存在变量hour里面
 * 最后，我们让min=min%60，这样余下的分钟数也会存起来。
 */
#include <stdio.h>
const int M_PER_H = 60;
int main(void)
{
    int minute = 1;
    int hour = 0;
    short count = 1;

    printf("*****************************************\n");
    printf("%d. Enter minutes (<=0 to quit):", count);
    scanf("%d", &minute);
    while (minute > 0)
    {
        printf("  %d minute(s) is", minute);
        hour = minute / M_PER_H; // 把分钟转换为小时（有截断）
        minute %= M_PER_H;       // 余出的分钟数
        printf(" %d hour(s) and %d minute(s).\n", hour, minute);

        count++;
        printf("%d. Enter a minute (<=0 to quit):", count);
        scanf("%d", &minute);
    }
    printf("*****************************************\n");

    return 0;
}