#include <stdio.h>
#define KM_PER_MILE (1.609)      // 1mile = 1.609km
#define LITRE_PER_GALLON (3.785) // 1gallon = 3.785litre
void p4_8(void)
{
    float driven_distance = 0.0;      // 行使的路程
    float gas_consumption = 0.0;      // 消耗的汽油量
    float litre_per_hundred_km = 0.0; // L/100km
    float mile_per_gallon = 0.0;      // mile/gallon

    printf("How much distance have you traveled in kilometer:"); // 你走了多远？
    scanf_s("%f", &driven_distance);
    printf("How much gas have you used in litre:"); // 消耗了多少升汽油？
    scanf_s("%f", &gas_consumption);

    litre_per_hundred_km = 100 * gas_consumption / driven_distance;                           // t (L/100km) = 100 * t (L/km)
    mile_per_gallon = (driven_distance / KM_PER_MILE) / (gas_consumption / LITRE_PER_GALLON); // q (mile/gallon) = (m / 1.609 (km)) / (n / 3.785 (litre))

    printf("Fuel consumptions:%f pint/100km or %f mile/gallon\n", litre_per_hundred_km, mile_per_gallon);
}

int main(int argc, char **argv)
{
    p4_8();

    getchar();
}