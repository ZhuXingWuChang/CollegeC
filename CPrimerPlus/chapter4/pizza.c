/* pizza.c -- 在比萨饼程序中使用已定义的常量 */
#include <stdio.H>
#define PI 3.14158
/*
 * C Primer Plus 程序4.4。
 */
int main(void)
{
    float area, circum, radius;

    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your basic pizza paramters are as follows:\n");
    printf("circumference = %1.2f, area = %1.2f\n", circum, area);

    return 0;
}