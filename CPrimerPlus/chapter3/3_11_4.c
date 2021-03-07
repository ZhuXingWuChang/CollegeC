#include <stdio.h>
int main(void)
{
    float afloat;

    printf("Enter a floating-point value: ");
    scanf("%f", &afloat);
    printf("\nfixed-point natation: %f\n", afloat);
    printf("exponential natation: %e\n", afloat);
    printf("p natation: %a\n", afloat);

    return 0;
}