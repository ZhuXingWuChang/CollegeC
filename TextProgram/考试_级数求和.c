/*
级数求和,这里我用级数Σ1/n来举例 
*/ 
#include<stdio.h>
void main(void)
{
	int n,i;
	float sum=0;
	scanf("%d",&n);
	for(i=1; i<=n; i++)
		sum+=1.0/i;
	printf("级数Σ1/n的前%d项和为%f",n,sum);
}
