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
        str[i + 1] = chars[i];
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
思路:   对于主串和目的串,都从第一个为止开始逐一比较,如果碰到不匹配的地方,
        那么主串下标回溯到开头的下一个位置,目的串下标回溯到目的串开头.
        这样一直比较到mainStr[0]-desStr[0]的位置后,退出.
步骤:   初始化一个"主串游标"
        初始化一个"子串游标"
        循环(两个游标都未越界)
            如果(两串匹配)
                主串游标自增,目的串游标自增
            否则(两串不匹配)
                主串游标回溯,目的串游标回溯
        如果(目的串游标越界,说明是因为匹配到了而结束)
            返回(主串游标-目的串长度)=主串起始下标
        否则(主串游标越界,说明没有匹配到目的串)
            返回0
*/
/*
params:
    desStr:     用户要查找的目的串,需要在主串中寻找到该目的串(destination String)
    mainStr:    主串,同样由用户传入
    queryStartP:从主串中开始查找子串的起始位置
*/
int Index(String desStr, String mainStr, int queryStartP)
{
    int mainCursor = queryStartP;
    int desCursor = 1;
    while (mainCursor <= mainStr[0] && desCursor <= desStr[0])
        if (mainStr[mainCursor] == desStr[desCursor])
        {
            mainCursor++;
            desCursor++;
        }
        else
        {
            mainCursor = mainCursor - desCursor + 2;
            desCursor = 1;
        }
    if (desCursor > desStr[0])
        return mainCursor - desStr[0];
    else
        return 0;
}

int main(void)
{
    
    return 0;
}