// golf.c -- 高尔夫锦标赛记分卡
#include <stdio.h>
/*
 * C Primer Plus 程序5.3。
 */
int main(void)
{
    int jane, tarzan, cheeta;

    cheeta = tarzan = jane = 68;
    printf("               cheeta   tarzan     jane\n");
    printf("First round core %4d %8d %8d\n", cheeta, tarzan, jane);

    return 0;
}