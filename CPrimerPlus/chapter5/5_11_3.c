/* 
 * 首先，需要一个day存放输入的天数
 * 并且需要一个week在后面用于存放周数
 * 然后，利用while循环不断输出对应的周数+天数
 * 循环的判断条件应该用一个flag来判断
 * 跳出循环
 */
#include <stdio.h>
const short STEP = 10;
const short D_PER_W = 7; // 天/周
int main(void)
{
    int day = 0;
    unsigned short week = 0;
    unsigned short count = 1;

    printf("*****************************************\n");
    printf("%u. Enter a number of days:", count++);
    scanf("%d", &day);
    while (day > 0)
    {
        week = day / D_PER_W;
        day %= D_PER_W;
        printf("    It's %u week(s) and %u day(s).\n", week, day);

        printf("%u. Enter a number of days:", count++);
        scanf("%d", &day);
    }
    printf("Exit!");
    printf("\n*****************************************\n");

    return 0;
}