#include <stdio.h>
int main(void)
{
    int a = 1000000000000;
    float b = 999999999999.999;
    float c = 999.999999999999;

    printf("Integer overflow: a=1000000000000, a=%d\n", a);
    printf("Float overflow: b=999999999999.999, b=%f\n", b);
    printf("Float underflow: c=999.999999999999, c=%f\n", c);

    return 0;
}