/*
求最大公约数（用辗转相除法）
求最小公倍数（用枚举法） 
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
int hcf(int u,int v)//最大公约数
{
	int t,r;
	if(v>u)
	{
		t=u;u=v;v=t;//把大的放到前面 
	}
	while((r=u%v)!=0)
	{
		u=v;
		v=r;
	}
	return(v);
}
int lcd(int u,int v,int h)//最小公倍数
{
	return(u*v/h);
}
