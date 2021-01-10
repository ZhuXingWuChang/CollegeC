/*
数据交换 
*/
#include <stdio.h>
void main(void)
{
	int a, b, t;

	printf("给a一个值:");
	scanf("%d", &a);

	printf("给b一个值:");
	scanf("%d", &b);

	printf("交换前:a=%d,b=%d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("交换后:a=%d,b=%d\n", a, b);
}
