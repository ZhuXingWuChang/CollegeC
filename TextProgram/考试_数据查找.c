/*
数组中查找某特数据（位置、次数） 
*/
#include<stdio.h>
void main(void)
{
	int a[10],t;
	int count=0,i;
	
	printf("请输入10个数:");
	for(i=0; i<10; i++)
		scanf("%d",&a[i]);
	
	printf("输入您想查找的数字:");
	scanf("%d",&t);
	
	printf("它在数组的如下位置:\n");
	for(i=0; i<10; i++)
		if( a[i] == t )
		{
			count++;
			printf("%-2d",i+1);	//按照习惯，我们从1开始数 
		}
	printf("\n它出现了%d次",count);
}
