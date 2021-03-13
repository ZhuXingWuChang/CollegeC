/* 
 * 需要一个char数组，然后用for循环把26个元素写进去
 * 然后再使用for循环把
 */
#include <stdio.h>
const int SIZE = 26;
int main(void)
{
    char ch_array[SIZE];
    for (int i = 0; i < SIZE; i++)
        ch_array[i] = 'A' + i;
    for (int i = 0; i < SIZE; i++)
        printf("%c ", ch_array[i]);

    return 0;
}