#include <stdio.h>
#include <string.h>
int main(void)
{
    char name[30];

    printf("Enter your name:\n");
    scanf("%s", name);
    printf("a. Hello \"%s\"\n", name);
    printf("b. Hello \"%20s\"\n", name);
    printf("c. Hello \"%-20s\"\n", name);
    printf("d. Hello \"%*s\"\n", strlen(name) + 3, name);

    return 0;
}