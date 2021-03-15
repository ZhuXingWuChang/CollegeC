/*
 * 定义一个字符数组
 * 读一个单词存入到字符数组里去
 * 求得这个数组的长度
 * 然后从数组尾部到头部进行一个遍历输出
 */
#include <stdio.h>
#include <string.h>
int main(void)
{
    char word[20];
    int length;

    printf("Enter a word: ");
    scanf("%s", word);
    length = strlen(word);

    for (int i = length - 1; i >= 0; i--)
    {
        printf("%c", word[i]);
    }

    return 0;
}