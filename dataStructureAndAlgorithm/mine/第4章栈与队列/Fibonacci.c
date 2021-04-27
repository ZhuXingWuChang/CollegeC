#include <stdio.h>
#define SIZE 40

int Fbi(int i)
{
    if (i < 2)
        return i == 0 ? 0 : 1;
    return Fbi(i - 1) + Fbi(i - 2);
}

int main(void)
{
    // 使用迭代实现斐波那契数列
    int fibonacciArray[SIZE] = {0, 1};
    printf("%d ", fibonacciArray[0]);
    printf("%d ", fibonacciArray[1]);
    for (int i = 2; i < SIZE; i++)
    {
        fibonacciArray[i] = fibonacciArray[i - 1] + fibonacciArray[i - 2];
        printf("%d ", fibonacciArray[i]);
    }
    printf("\n");

    // 使用递归实现斐波那契数列
    for (int i = 0; i < SIZE; i++)
        printf("%d ", Fbi(i));
    return 0;
}