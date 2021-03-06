/* altnames.c -- 可移植整数类型名 */
#include <stdio.h>
#include <inttypes.h>
/*
 * C Primer Plus 程序3.6。
 */
int main(void)
{
    int32_t me32;

    me32 = 45933945;
    printf("First, assume int32_t is int: ");
    printf("me32 = %d\n", me32);
    printf("Next, let's not make any assumptions.\n");
    printf("Instead, use a \"macro\" inttypes.h: ");
    printf("me32 = %" PRId32 "\n", me32); // PRId32被define为"d"
    //然后C对 "me32 = %"  "d"  "\n"这三个字符串进行拼接操作，等价于"me32 = %d\n"
    return 0;
}