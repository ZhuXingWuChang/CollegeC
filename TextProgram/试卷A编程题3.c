/*
3.��д���򣬶���һ���ַ�����s��������һ���ַ�x��ͳ�������к��ַ�x��ͬ�ַ�����n��
���n=0,�����"����������ַ�"������������ַ��ĸ�������10�֣�
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
		printf("�ַ�%c��%d��", x, n);
	else
		printf("����������ַ�");
}
