/*
�ۼ� 
*/
#include <stdio.h>
void main(void)
{
	int sum = 0, n, i;
	scanf("%d", &n); //�����&��ȡn�ĵ�ַ
	for (i = 1; i <= n; i++)
		sum += i;
	printf("1��%d���ۼ�Ϊ%d", n, sum);
}
