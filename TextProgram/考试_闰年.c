/*
���� 
�ܹ�(1)��4�������ǲ���100���� 
	(2)�ܱ�400����
	����ݽ������� 
*/
#include <stdio.h>
void main(void)
{
	int year;
	printf("������һ�����:");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		printf("������"); //������== ����=
	else
		printf("��������");
}
