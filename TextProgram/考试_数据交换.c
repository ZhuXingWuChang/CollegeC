/*
���ݽ��� 
*/
#include <stdio.h>
void main(void)
{
	int a, b, t;

	printf("��aһ��ֵ:");
	scanf("%d", &a);

	printf("��bһ��ֵ:");
	scanf("%d", &b);

	printf("����ǰ:a=%d,b=%d\n", a, b);
	t = a;
	a = b;
	b = t;
	printf("������:a=%d,b=%d\n", a, b);
}
