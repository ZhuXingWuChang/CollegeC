/*
��д����
1����д����������fun�Ĺ���������ȡ���ַ��������д�д��ĸ���γ��µ��ַ�������ȡ��ԭ�ַ�������10����
2����������������һ���ַ�����������fun�������������µ��ַ�������5�֣� 
*/
#include<stdio.h>
#include<string.h>
void fun(char s[],int n);
void main(void)
{
	char s[80];
	printf("�����ַ���:");
	scanf("%s",s);
	fun(s,strlen(s));
	printf("%s",s);
}
void fun(char s[],int n)
{
	int i,j;
	char a[80];
	for(i=0,j=0;i<n;i++)
	{
		if((s[i]>='A' && s[i]<='Z'))
			a[j++]=s[i];
	}
	a[i]='\0';
	strcpy(s,a);
}
