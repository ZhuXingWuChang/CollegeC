/*
 * 读取输入，当输入不是#的时候
 *      如果前一个字符是e并且后一个字符是i：计数加一
 * 输出计数
 */
#include <stdio.h>
int main(void)
{
    char ch_current = '\0';
    char ch_before = '\0';
    short count = 0;

    printf("Enter anything (# to quit):\n");
    while ((ch_current = getchar()) != '#')
    {
        if (ch_before == 'e' && ch_current == 'i')
            count++;
        ch_before = ch_current;
    }

    if (count <= 1)
        printf("\"ei\" appears %d time.\n", count);
    else
        printf("\"ei\" appear %d times.\n", count);

    return 0;
}