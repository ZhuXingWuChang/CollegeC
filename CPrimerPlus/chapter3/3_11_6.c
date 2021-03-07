#include <stdio.h>
int main(void)
{
    int quart; //水的夸脱数

    printf("Enter the quart of water: _____\b\b\b\b\b");
    scanf("%d", &quart);
    printf("\n%d quart of water equal %e water molecules.\n", quart, 950 * quart / 3.0e-23);

    return 0;
}