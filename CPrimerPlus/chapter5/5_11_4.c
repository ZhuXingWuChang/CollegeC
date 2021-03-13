/* 
 * 需要一个float类型的height存放用户输入的升高(cm)
 * 然后需要一个float inch来存放英寸值
 * 用while循环让用户反复输出，以height的正负作为循环结束的判断条件
 */
#include <stdio.h>
const float CM_PER_INCH = 2.54f;   // 每2.54厘米=1英寸     厘米/英寸
const float INCH_PER_FEET = 12.0f; // 每12英寸=1英尺       英寸/英尺
int main(void)
{
    float centimeter = 0.0f; // 厘米
    float inch = 0.0f;       // 英寸
    int feet = 0;            // 英尺

    printf("Enter a height in centimeters: ");
    scanf("%f", &centimeter);
    do
    {
        inch = centimeter / CM_PER_INCH;    // 先把厘米全部转换为英寸
        feet = inch / INCH_PER_FEET;        // 再把英寸转换为英尺
        inch = inch - feet * INCH_PER_FEET; // 转换为英寸后的余数
        printf("%.1f cm = %d feet, %.1f inches.\n", centimeter, feet, inch);
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &centimeter);
    } while (centimeter > 0);
    printf("bye");

    return 0;
}