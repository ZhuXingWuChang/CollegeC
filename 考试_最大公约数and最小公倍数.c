/*
�����Լ������շת�������
����С����������ö�ٷ��� 
*/
#include <stdio.h>
int main()
{
	int hcf(int,int);
	int lcd(int,int,int);
	int u,v,h,l;
	scanf("%d%d",&u,&v);
	h=hcf(u,v);
	printf("HCF=%d\n",h);
	l=lcd(u,v,h);
	printf("LCD=%d\n",l);
	return 0;
}
int hcf(int u,int v)//���Լ��
{
	int t,r;
	if(v>u)
	{
		t=u;u=v;v=t;//�Ѵ�ķŵ�ǰ�� 
	}
	while((r=u%v)!=0)
	{
		u=v;
		v=r;
	}
	return(v);
}
int lcd(int u,int v,int h)//��С������
{
	return(u*v/h);
}
