#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[20] = {'0'};
    char surname[20] = {'0'};

    printf("Enter your first name and last name:\n");
    scanf("%s%s", name, surname);

    printf("%s %s\n", name, surname);
    printf("%*d %*d\n", strlen(name), strlen(name), strlen(surname), strlen(surname));

    printf("%s %s\n", name, surname);
    printf("%-*d %-*d\n", strlen(name), strlen(name), strlen(surname), strlen(surname));

    return 0;
}