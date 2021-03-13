/*
 * 用外层循环处理行
 * 每行用三个内层循环，分别处理空格、以升序打印字母、以降序打印字母
 * 我们以中点的位置为列数，所以行=列（比如最后一行输出ABCDEDCBA，到中间字母E位置，有五列）
 * 在控制行的for循环外，ch的作用是确认行列数
 * 进入控制行的for循环之后，因为行列数已经保存了给ch赋值时的信息（比如给ch赋值E，行列=5）
 * 在循环内部，不再需要输入的那个数值，由于每一行都是从A开始，所以直接给ch赋A
 */
#include <stdio.h>
int main(void)
{
    char ch;
    printf("Enter a letter: ");
    ch = getchar(); // 下面的情况全部按找假设输入E来讨论

    const int COL = ch - 'A' + 1; // 列数为E-A+1=5

    // 外层循环，按行打印，并且下面的情况全部假设是第一行来讨论
    for (int i = 0; i < COL; i++)
    {
        int blank_num = COL - i - 1; // blank_num=5-0-1=4
        ch = 'A';                    // 每一行都会从A开始输出

        // 内层循环1：打印空格
        for (int j = 0; j < blank_num; j++)
            printf(" "); // a blank

        // 内层循环2：升序打印字母
        for (int j = blank_num; j < COL; j++) // j=4;j<5，执行一次循环体
            printf("%c", ch++);               // 输出ch=A，接着令ch=B
        ch--;                                 // 如果在第二行，此时ch=C，但是接下来要打印A

        // 内层循环3：降序打印字母
        for (int j = 0; j < i; j++) // 第一行打印0个，第二行打印1个，第三行打印2个
            printf("%c", --ch);

        printf("\n");
    }

    return 0;
}