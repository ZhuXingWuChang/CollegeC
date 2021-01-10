/*
闰年 
能够(1)被4整除但是不被100整除 
	(2)能被400整除
	的年份叫做闰年 
*/
#include <stdio.h>
void main(void)
{
	int year;
	printf("请输入一个年份:");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("是闰年"); //上面是== 不是=
	else
		printf("不是闰年");
}
