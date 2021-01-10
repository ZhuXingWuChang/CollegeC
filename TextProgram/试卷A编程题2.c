/*2.编写程序，输出在200-300之间的满足以下两个条件的所有整数：1）个位、十位和百位之和等于12；2）个位、十位和百位之积等于42。10分）*/
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
