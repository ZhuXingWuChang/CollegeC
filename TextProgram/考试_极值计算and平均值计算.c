/*
��ֵ���㡢ƽ��ֵ���� 
*/
#include<stdio.h>
void main(void)
{
	int max,min,sum,a[10];
	float average;		//ƽ��ֵ�ܿ��ܲ���һ������ 
	int i;
	for(i=0; i<10; i++)
		scanf("%d",&a[i]);	//ʹ��forѭ���������鸳ֵ
	
	max=a[0];
	min=a[0];	//�����ȼٶ���һ��ֵ�������ֵ 
	
	for(i=0; i<10; i++)
		if(a[i]>max)
			max=a[i];	//������������ֵ�������max 
	
	for(i=0; i<10; i++)
		if(a[i]<min) 
			min=a[i];	//���������С��ֵ�������min
	
	for(i=0; i<10; i++)
		sum+=a[i];		//��ͣ�������ƽ��ֵ 
	average=sum/10.0;	//sum�����ͣ�����10����õ��Ļ���һ������ 
	
	printf("max=%d,min=%d,average=%f",max,min,average);
}
