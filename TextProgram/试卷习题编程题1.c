/*1.编写程序，打印1-100之间所有的奇数，要求每行输出5个数。（10分）*/
#include <stdio.h>
void main(void)
{
	int num;
	int count = 0;
	for (num = 1; num < 100; num++)
		if (num % 2 != 0)
		{
			printf("%-3d", num);
			count++;
			if (count % 5 == 0)
				printf("\n");
		}
}
