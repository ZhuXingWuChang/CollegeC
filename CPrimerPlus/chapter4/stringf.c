/* stringf.c -- 字符串格式 */
#include <stdio.h>
#define BLURB "Authentic imitation!"
/*
 * C Primer Plus 程序4.10。
 */
int main(void)
{
    printf("[%2s]\n", BLURB);
    printf("[%24s]\n", BLURB);
    printf("[%24.5s]\n", BLURB);
    printf("[%-24.5s]\n", BLURB);

    return 0;
}