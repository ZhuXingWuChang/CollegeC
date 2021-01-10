/*
累加 
*/
#include <stdio.h>
void main(void)
{
	int sum = 0, n, i;
	scanf("%d", &n); //这里的&是取n的地址
	for (i = 1; i <= n; i++)
		sum += i;
	printf("1到%d的累加为%d", n, sum);
}
