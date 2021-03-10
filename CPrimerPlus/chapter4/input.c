// input.c -- 何时使用&
#include <stdio.h>
/*
 * C Primer Plus 程序4.15。
 */
int main(void)
{
    int age;      // 变量
    float assets; // 变量
    char pet[30]; // 字符数组，用于存储字符串

    printf("Enter your age, assets, and favorite pet.\n");
    scanf("%d %f", &age, &assets);
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);

    return 0;
}