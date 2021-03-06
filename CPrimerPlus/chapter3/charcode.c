/* charcode.c-显示字符的代码编号 */
#include <stdio.h>
/*
 * C Primer Plus 程序3.5。
 */
int main(void)
{
    char ch;

    printf("Please enter a character.\n");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n", ch, ch);

    return 0;
}