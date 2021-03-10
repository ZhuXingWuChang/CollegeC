#include <stdio.h>
int main(void)
{
    char name[20];
    char surname[20];

    printf("Enter your first name and last name:\n");
    scanf("%s%s", name, surname);
    printf("Hello %s %s!", name, surname);

    return 0;
}