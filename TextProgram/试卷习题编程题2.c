/*编写程序，求1+2/1+4/3+6/5+...+2n/2n-1，从键盘输入n的值，计算前n项之和。（10分）*/
#include <stdio.h>
void main(void)
{
	int n, t;
	double a, b, sum = 1.0;
	scanf("%d", &t);
	t--;
	for (n = 1; n <= t; n++)
	{
		a = 2 * n;
		b = 2 * n - 1;
		sum += a / b;
	}
	printf("%lf", sum);
}
