/*1.编写程序，输出1到n之间所有数的平方之和。其中n从键盘输入，比如n=4，则输出和为30。（说明，30=1^2+2^2+3^2+4^2）（10分)*/
#include <stdio.h>
int pf(int t);
void main(void)
{
	int sum = 0, n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		sum += pf(i);
	printf("sum=%d", sum);
}
int pf(int t)
{
	t *= t;
	return t;
}
