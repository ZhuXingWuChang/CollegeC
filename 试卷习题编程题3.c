/*
编写程序，定义一个有20个整型数据的数组，另输入一个整数，统计这个整数在数组中出现的次数，
如果次数>0，输出此数和出现的总的次数，否则，输出"此数不在数组中！"。（10分）
*/
#include<stdio.h>
void main(void)
{
	int a[20];
	int x,i,count=0;
	printf("输入数组:");
	for(i=0; i<20; i++)
		scanf("%d",&a[i]);
	printf("输入另一个整数x:");
	scanf("%d",&x);
	for(i=0; i<20; i++)
		if(a[i]==x)
			count++;
	if(count)
		printf("x出现了%d次\n",count);
	else
		printf("此数不在数组中！"); 
}
