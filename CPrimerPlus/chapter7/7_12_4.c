/*
 * 读取输入，当不是#的时候
 *      如果是句号：输出感叹号，替换数加一
 *      又如果是一个感叹号：输出两个感叹号，替换数加一
 *      否则：正常输出
 * 输出替换次数
 */
#include <stdio.h>
int main(void)
{
    char ch;
    int count = 0;

    printf("Enter anything (# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        if ('.' == ch)
        {
            printf("!");
            count++;
        }
        else if ('!' == ch)
        {
            printf("!!");
            count++;
        }
        else
            printf("%c", ch);
    }
    printf("\nI made %d substitutions.\n", count);

    return 0;
}