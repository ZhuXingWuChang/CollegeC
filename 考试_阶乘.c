/*
�׳� 
*/
#include<stdio.h>
void main(void)
{
	int n,i;
	scanf("%d",&n);
	int sum=1;	//ע��������1
	for(i=1; i<=n; i++)
		sum*=i;
	printf("%d!=%d",n,sum);
}
