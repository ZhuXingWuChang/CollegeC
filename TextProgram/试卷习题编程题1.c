/*1.��д���򣬴�ӡ1-100֮�����е�������Ҫ��ÿ�����5��������10�֣�*/
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
