/*
 * 倒序打印输入的内容，只要用户不输入[Enter]，便不会停止读入
 * 
 * 用一个char数组存放用户输入的内容
 * 使用一个while循环来读入用户的输入
 * 循环条件中，当判断用户输入了回车时，结束循环
 */
#include <stdio.h>
int main(void)
{
    char string[256]; // 255是一行的最大长度
    int index = -1;   // 这样先执行index++，让它进入合法的下标范围

    printf("Enter a string ([Enter] to quit):\n");
    do // 因为getchar要按下回车才读取，所以不使用
    {
        index++;
        scanf("%c", &string[index]);
    } while ('\n' != string[index]);

    printf("Your entering is:\n%s", string);

    return 0;
}