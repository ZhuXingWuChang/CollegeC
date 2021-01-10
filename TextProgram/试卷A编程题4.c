/*
4.编写程序：
1）编写函数，函数fun的功能是逆序存放实型数组中的元素。（10分）
2）在主函数中调用此fun函数，并输出逆序之后数组元素。（5分）
例如，数组元素为1 5 6 8 9，逆序后的数组元素为9 8 6 5 1。
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
