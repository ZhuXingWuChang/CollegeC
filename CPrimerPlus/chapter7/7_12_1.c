/*
 * 读取用户输入
 * 读到的字符不是#
 *      如果读到空格，空格数加一
 *      如果读到换行符，换行符数加一
 *      否则，其它字符数加一
 */
#include <stdio.h>
int main(void)
{
    char ch;
    short space_ct = 0;
    short lines_ct = 0;
    short chars_ct = 0;

    printf("Enter anything (# to quit):\n");
    while ((ch = getchar()) != '#')
    {
        if (ch == ' ')
            space_ct++;
        else if (ch == '\n')
            lines_ct++;
        else
            chars_ct++;
    }
    printf("space = %hd, lines = %hd, chars = %hd.\n", space_ct, lines_ct, chars_ct);

    return 0;
}