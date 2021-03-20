/*
 * 显示一个菜单，让用户选择输入类别
 * 1.单身 2.户主 3.已婚，共有 4.已婚，离异
 * 用户输入收入，当用户输入的类别和税金都合法时
 *      如果小于等于税金上限：按照对应标准计算税金
 *      否则：按照另一对应标准计算税金
 *      输出用户税金
 *      再次提示用户输入收入
 * 显示结束信息
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LIMIT1 17850.0
#define LIMIT2 23900.0
#define LIMIT3 29750.0
#define LIMIT4 14875.0
#define RATE_A 0.15
#define RATE_B 0.28
void print_menu(void);
int main(void)
{
    double salary = 0.0; // 用来存放用户输入的工资
    short select = 0;    // 用来存放用户输入的选择
    bool flag = false;   // 判断选择是否有效
    double limit = 0.0;  // 当salary达到limit时，应该收税
    double tax = 0.0;    // 存放税

    print_menu();
    flag = scanf("%d", &select);
    if (1 == select)
        limit = LIMIT1;
    else if (2 == select)
        limit = LIMIT2;
    else if (3 == select)
        limit = LIMIT3;
    else if (4 == select)
        limit = LIMIT4;

    printf("Enter your salary in year: ");
    while (flag && scanf("%lf", &salary) == 1)
    {
        if (salary < limit)
            tax = salary * RATE_A;
        else
            tax = limit * RATE_A + (salary - limit) * RATE_B;
        printf("You should pay $%.2lf in tax.\n", tax);
        printf("Enter your salary in year: ");
    }
    printf("Done");

    return 0;
}

void print_menu(void)
{
    char message[255] = {"Enter the number for your current state (q to quit):"};
    for (int i = 0; i < strlen(message); i++)
        printf("*");
    printf("\n");
    printf("%s\n", message);
    printf("1) single           2)  head of a household\n");
    printf("3) married, have a house with your wife\n");
    printf("4) married, and divorced\n");
    for (int i = 0; i < strlen(message); i++)
        printf("*");
    printf("\n");

    return;
}