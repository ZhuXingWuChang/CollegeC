/*2.��д���������200-300֮�������������������������������1����λ��ʮλ�Ͱ�λ֮�͵���12��2����λ��ʮλ�Ͱ�λ֮������42��10�֣�*/
#include <stdio.h>
void main(void)
{
	int i;
	int gw, sw, bw;
	for (i = 200; i <= 300; i++)
	{
		gw = i % 10;
		bw = i / 100;
		sw = (i / 10) % 10;
		//printf("bw=%d,sw=%d,gw=%d\n",bw,sw,gw);
		if (gw + sw + bw == 12 && gw * sw * bw == 42)
			printf("%d\n", i);
	}
}
