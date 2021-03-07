#include <stdio.h>
int main(void)
{
    int ascii;

    printf("Please input a ASCII value: ___\b\b\b"); // \b是退格
    scanf("%d", &ascii);
    printf("\n%d is a \'%c\'.\n", ascii, ascii);

    return 0;
}