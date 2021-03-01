#include <stdio.h>
/*
 * C Primer Plus 程序1.1。
*/
int main(void)
{
    int dogs;

    printf("How many dogs do you have?\n");
    scanf("%d", &dogs);
    printf("So you have %d dog(s)!\n", dogs);

    return 0;
}