/*
 * 需要一个int数组来存放8个平方数
 * 使用for循环设置数组的值
 * 使用do while循环显示数组的值
 */
#include <stdio.h>
#include <math.h>
const int SIZE = 8;
int main(void)
{
    int squale[SIZE];
    int count = 0;

    for (int i = 0; i < SIZE; i++)
        squale[i] = pow(2, i);

    do
    {
        printf("%d  ", squale[count]);
        count++;
    } while (count < SIZE); // 这里的判断条件不能引用块里的局部变量，所以count应该定义在块外

    return 0;
}