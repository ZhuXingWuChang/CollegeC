/*1.��д�������1��n֮����������ƽ��֮�͡�����n�Ӽ������룬����n=4���������Ϊ30����˵����30=1^2+2^2+3^2+4^2����10��)*/
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
