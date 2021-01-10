/*
极值计算、平均值计算 
*/
#include<stdio.h>
void main(void)
{
	int max,min,sum,a[10];
	float average;		//平均值很可能不是一个整数 
	int i;
	for(i=0; i<10; i++)
		scanf("%d",&a[i]);	//使用for循环来给数组赋值
	
	max=a[0];
	min=a[0];	//我们先假定第一个值就是最大值 
	
	for(i=0; i<10; i++)
		if(a[i]>max)
			max=a[i];	//如果遇到更大的值，则更新max 
	
	for(i=0; i<10; i++)
		if(a[i]<min) 
			min=a[i];	//如果遇到更小的值，则更新min
	
	for(i=0; i<10; i++)
		sum+=a[i];		//求和，用于求平均值 
	average=sum/10.0;	//sum是整型，若除10，则得到的还是一个整型 
	
	printf("max=%d,min=%d,average=%f",max,min,average);
}
