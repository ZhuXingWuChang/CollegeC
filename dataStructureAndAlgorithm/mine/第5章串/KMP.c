/*
StrAssign(String T,char *chars)
ClearStr(String S)
StrPrint(String T)
NextPrint(int next[],int length): 打印next数组
StrLength(String S)
Index(String S, String T, int pos): 朴素的模式匹配算法

get_next(String T, int *next): 计算出next数组的值
Index_KMP(String S, String T, int pos): KMP模式匹配算法

get_nextval(String T, int *nextval): 对于改进后的KMP算法, 计算出next数组的值
Index_KMP1(String S, String T, int pos): KMP模式匹配算法的改进
*/

#include <stdio.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 40

typedef char String[MAXSIZE + 1];
typedef int Status;

Status StrAssign(String str, char *chars)
{
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    str[0] = strlen(chars);
    for (int i = 0; i <= str[0]; i++)
        str[i + 1] = str[i];
    return OK;
}

Status ClearStr(String str)
{
    str[0] = 0;
    return OK;
}

void StrPrint(String str)
{
    for (int i = 1; i <= str[0]; i++)
        printf("%c", str[i]);
    printf("\n");
}

int StrLength(String str)
{
    return str[0];
}

/*
输出next数组的值
params: 
    next[]: 需要打印的next数组指针
    length: next数组的长度
*/
void NextPrint(int next[], int length)
{
    for (int i = 0; i < length; i++)
        printf("%d", next[i]);
    printf("\n");
}

/*
朴素的模式匹配算法
params:
    
*/
int Index(String mainStr, String subStr, int len)
{
    
}