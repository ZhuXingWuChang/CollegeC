#include <stdio.h>
int main(void)
{
    double number;

    printf("Enter a number:\n");
    scanf("%lf", &number);
    printf("a. The input is %.1lf or %.2le.\n", number, number);
    printf("b. The input is %+.3lf or %+.3lE.\n", number, number);

    return 0;
}