/*
 * 用double fahrenheit保存用户输入的华氏度
 * 用double celsius来保存计算得到的摄氏度
 * 用double kelvin来保存计算得到的开氏度
 * celsius = 5.0 / 9.0 * (fahrenheit - 32.0)
 * kelvin = celsius + 273.16
 * Temperatures函数需要一个double类型的fahrenheit，然后自动计算出celsius和kelvin并按两位精度打印
 * Temperatures函数中用const创建系数，在main函数中用一个循环让用户重复输入温度
 * 当用户输入q（或其它非数字时），结束
 */
#include <stdio.h>
void Temperatures(double);
int main(void)
{
    double fahrenheit = 0.0;

    printf("Enter a fahrenheit ('q' to quit): ");
    while (1 == scanf("%lf", &fahrenheit))
    {
        Temperatures(fahrenheit);
        printf("Enter a fahrenheit ('q' to quit): ");
    }
    printf("Done\n");

    return 0;
}

void Temperatures(double fahrenheit)
{
    const double COEFFICIENT = 5.0 / 9.0; // 系数
    const double CONSTANT_C = 32.0;       // 摄氏度常数
    const double CONSTANT_K = 273.16;     // 开氏度常数

    double celsius = COEFFICIENT * (fahrenheit - CONSTANT_C);
    double kelvin = celsius + CONSTANT_K;

    printf("fahrenheit = %.2lfF, celsius = %.2lfC, kelvin = %.2lfK\n", fahrenheit, celsius, kelvin);
}