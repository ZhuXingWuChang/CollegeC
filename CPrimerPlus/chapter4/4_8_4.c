#include <stdio.h>
int main(void)
{
    float centimeter = 0.0; // 厘米
    float meter = 0.0;      // 米
    char name[30] = {'0'};

    printf("Enter your height(cm) and name:\n");
    scanf("%f%s", &centimeter, name);
    meter = centimeter / 100;
    printf("%s, you are %.2f meter tall.", name, meter);

    return 0;
}