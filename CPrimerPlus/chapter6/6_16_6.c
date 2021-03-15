/*
 * 定义一个int min_number存放用户输入的下限
 * 定义一个int max_number存放用户输入的上限
 * 使用for循环打印表格
 */
#include <stdio.h>
int main(void)
{
    int min_num, max_num;

    printf("Enter two numbers: ");
    scanf("%d%d", &min_num, &max_num);

    for (int i = min_num; i <= max_num; i++)
    {
        printf("%-12d|  %-12d|  %-12d\n", i, i * i, i * i * i);
    }

    return 0;
}