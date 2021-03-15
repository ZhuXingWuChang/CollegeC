/*
 * 使用两个double类型的数组，第一个由用户循环输入
 * 第二个存放第一个数组对应元素的累积之和
 * 最后使用循环显示两个数组的内容，每个数组各占一行，且元素对应
 */
#include <stdio.h>
const int SIZE = 8;
int main(void)
{
    double input_array[SIZE];
    double sum_array[SIZE];

    printf("Enter the 1 number: ");
    for (int i = 0; i < SIZE && 1 == scanf("%d", &input_array[i]); i++)
    {
        if (2 <= i + 1)
            sum_array[i] = sum_array[i - 1] + input_array[i];
        else
            sum_array[0] = input_array[0];
        if (i < 7)
            printf("Enter the %d number: ", i + 2); // 当i=7时，i+2=9
    }

    printf("Thess arrays are:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d  ", input_array[i]);
    printf("\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d  ", sum_array[i]);

    return 0;
}