/*
4.��д����
1����д����������fun�Ĺ�����������ʵ�������е�Ԫ�ء���10�֣�
2�����������е��ô�fun���������������֮������Ԫ�ء���5�֣�
���磬����Ԫ��Ϊ1 5 6 8 9������������Ԫ��Ϊ9 8 6 5 1��
*/
#include <stdio.h>
void fun(int a[], int l);
void main(void)
{
	int shuzu[5] = {1, 5, 6, 8, 9};
	int x;
	fun(shuzu, 5);
	for (x = 0; x < 5; x++)
		printf("%-d ", shuzu[x]);
}
void fun(int a[], int l)
{
	int i, j, t;
	for (i = 0, j = l - i - 1; i < (l / 2); i++, j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
}
