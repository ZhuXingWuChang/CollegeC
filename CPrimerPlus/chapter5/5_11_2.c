/* 
 * 首先，需要一个integer存放输入的整数
 * 然后，进行一次循环，输出integer到integer+10之间的所有数
 */
#include <stdio.h>
const short STEP = 10;
int main(void)
{
    int integer = 0;
    _Bool flag = 0;

    printf("*****************************************\n");
    printf("Enter an integer number:");
    flag = scanf("%d", &integer);
    for (int i = integer; flag && i <= integer + STEP; i++)
    {
        printf("%d  ", i);
    }
    printf("\n*****************************************\n");

    return 0;
}