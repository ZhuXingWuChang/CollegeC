/*
�����в���ĳ�����ݣ�λ�á������� 
*/
#include<stdio.h>
void main(void)
{
	int a[10],t;
	int count=0,i;
	
	printf("������10����:");
	for(i=0; i<10; i++)
		scanf("%d",&a[i]);
	
	printf("����������ҵ�����:");
	scanf("%d",&t);
	
	printf("�������������λ��:\n");
	for(i=0; i<10; i++)
		if( a[i] == t )
		{
			count++;
			printf("%-2d",i+1);	//����ϰ�ߣ����Ǵ�1��ʼ�� 
		}
	printf("\n��������%d��",count);
}
