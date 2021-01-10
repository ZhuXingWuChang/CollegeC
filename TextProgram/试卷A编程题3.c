/*
3.编写程序，定义一个字符数组s，另输入一个字符x，统计数组中和字符x相同字符个数n，
如果n=0,则输出"不存在这个字符"，否则输出此字符的个数。（10分）
*/
#include <stdio.h>
#include <string.h>
void main(void)
{
	char s[80] = "one,two,three,blue";
	char x;
	int i, n = 0;
	x = getchar();
	for (i = 0; i < strlen(s); i++)
		if (s[i] == x)
			n++;
	if (n > 0)
		printf("字符%c有%d个", x, n);
	else
		printf("不存在这个字符");
}
