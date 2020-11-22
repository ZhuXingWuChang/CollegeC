/*
编写程序：
1）编写函数，函数fun的功能是依次取出字符串中所有大写字母，形成新的字符串，并取代原字符串；（10）分
2）在主函数中输入一行字符串，并调用fun函数，最后输出新的字符串。（5分） 
*/
#include<stdio.h>
#include<string.h>
void fun(char s[],int n);
void main(void)
{
	char s[80];
	printf("输入字符串:");
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
