/*
 * 用户输入
 * 当用户的输入不是#时
 *      如果一行满了8个，换行
 *      输出字符和ASCII码
 */
#include <stdio.h>
int main(void)
{
    char ch;
    short count = 0;

    printf("Enter anything (# to quit):\n");
    while ((ch = getchar()) != '#' && ch != '\n')
    {
        count++;
        if (count % 8 == 0)
            printf("\n");
        printf("%c - %3d    |    ", ch, ch);
    }
    printf("\nDone");

    return 0;
}