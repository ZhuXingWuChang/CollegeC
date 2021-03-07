#include <stdio.h>
int main(void)
{
    int age;

    printf("Enter your age: ___\b\b\b");
    scanf("%d", &age);
    printf("Your age equal %e seconds.", age * 3.156e7);

    return 0;
}