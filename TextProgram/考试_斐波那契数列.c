/*
쳲��������� 
*/
#include<stdio.h>
int fun(int x)
{
	if(x == 1) return 1;
	if(x == 2) return 1;
	return fun(x-1) + fun(x-2);
}
void main()
{
	int num;
	printf("������쳲����������еĵ�n��Ԫ��: ");
	scanf("%d",&num);
	int y = fun(num);
	printf("%d\n",y);
}
