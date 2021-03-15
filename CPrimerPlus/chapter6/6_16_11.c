/*
 * 需要一个int数组存储用户输入的8个整数
 * 用户采用循环进行输入
 * 然后使用sizeof获取数组长度
 * 并对这个数组进行一个倒序遍历输出
 */
#include <stdio.h>
#include <stdbool.h>
#define SIZE 8
int main(void)
{
    int integer[SIZE];
    bool flag = false;

    printf("Enter eight integer numbers: ");
    for (int i = 0; i < SIZE && 1 == scanf("%d", &integer[i]); i++)
        // 上面 i < SIZE 和 scanf这两个判断的先后有讲究，如果scanf在前
        // 那么在i达到8（即已经输入了8个）的时候，还需要再输入一次（即输入第九个数）
        // 才会结束循环，那样会导致用户多输入一个无用的数
        if (flag == i)
            flag = true;
    if (flag == false)
    {
        printf("Your entering is error!");
        return 0;
    }

    for (int i = SIZE - 1; i >= 0; i--)
        printf("%d  ", integer[i]);

    return 0;
}