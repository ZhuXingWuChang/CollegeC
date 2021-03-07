#include <stdio.h>
int main(void)
{
    float pint;     // 1品脱 = 2杯
    float cup;      // 1杯 = 8盎司
    float ounce;    // 1盎司 = 2大汤勺
    float bigspoon; // 1大汤勺 = 3茶勺
    float teaspoon; // 茶勺

    printf("Enter a number of cups: ____\b\b\b\b");
    scanf("%f", &cup);

    pint = cup / 2;
    ounce = cup * 8;
    bigspoon = ounce * 2;
    teaspoon = bigspoon * 3;

    printf("\n%.2f of cup equal %.2f of pint, "
           "equal %.2f of ounce, "
           "equal %.2f of bigspoon, "
           "equal %.2f of teaspoon.",
           cup, pint, ounce, bigspoon, teaspoon);

    return 0;
}