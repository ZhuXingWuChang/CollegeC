#include <stdio.h>
#define LITRE_TO_GALLON 3.785   // 1gallon = 3.785litre
#define KILOMETER_TO_MILE 1.609 // 1mile = 1.609kilometer
int main(void)
{
    float litre = 0.0;                       // 升
    float kilometer = 0.0;                   // 千米
    float litre_per_hundred_kilometer = 0.0; // 升/100千米
    float mile_per_gallon = 0.0;             // 英里/加仑

    printf("Enter the litres and the kilometers:\n");
    scanf("%f%f", &litre, &kilometer);

    litre_per_hundred_kilometer = 100 * litre / kilometer;                         // t (L/100km) = 100 * t (L/km)
    mile_per_gallon = (LITRE_TO_GALLON * kilometer) / (KILOMETER_TO_MILE * litre); // q (mile/gallon) = (m / 1.609 (km)) / (n / 3.785 (litre))

    printf("%.4f(L/100km) = %.4f(mile/gallon)\n", litre_per_hundred_kilometer, mile_per_gallon);

    return 0;
}