/*
�������,�������ü�����1/n������ 
*/ 
#include<stdio.h>
void main(void)
{
	int n,i;
	float sum=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		sum+=1.0/i;
	printf("������1/n��ǰ%d���Ϊ%f",n,sum);
}
