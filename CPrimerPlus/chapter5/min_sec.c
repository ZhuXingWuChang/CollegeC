// min_sec.c -- 把秒数转换成分和秒
#include <stdio.h>
#define SEC_PER_MIN 60 // 1分钟 = 60秒
/*
 * C Primer Plus 程序5.9。
 */
int main(void)
{
    int sec, min, left; // sec:秒数  min:分钟数  left:截断掉的分钟数

    printf("Convert seconds to minutes and seconds!\n");
    printf("Enter the number of seconds (<=0 to quit):\n");
    scanf("%d", &sec);
    while (sec > 0)
    {
        min = sec / SEC_PER_MIN;  // 截断分钟数
        left = sec % SEC_PER_MIN; // 剩下的秒数
        printf("%d seconds is %d minutes, %d seconds.\n", sec,
               min, left);
        printf("Enter next value (<=0 to quit):\n");
        scanf("%d", &sec);
    }
    printf("Done!\n");

    return 0;
}