#include <stdio.h>
int main(void)
{
    double inch;

    printf("Enter your height in inches: ___\b\b\b");
    scanf("%lf", &inch);
    printf("\n%.2lf inches equal %.2lf cm.\n", inch, 2.54 * inch);

    return 0;
}