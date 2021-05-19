/*
ADT 串(string)
Data
    串中元素仅由一个字符组成,相邻元素句具有前驱和后继关系
Operation
    StrAssign(T,*chars):生成一个其值等于字符串常量chars的串T.
    StrCopy(T,S):串S存在,由串S复制得串T.
    ClearString(S):串S存在,将串清空.
    StringEmpty(S):若串S为空,返回true,否则返回false.
    StrLength(S):返回串S的元素个数,即串的长度.
    StrCompare(S,T):若S>T,返回值>0;若S=T,返回值=0;若S<T,返回值<0.
    Concat(T,S1,S2):用T返回由S1和S2联接而成的新串.
    SubString(Sub,S,pos,len):串S存在,1<=pos<=StrLength(S),
                            且0<=len<=StrLength(S)-pos+1,用Sub返
                            回串S的第pos个字符起长度为len的子串.
    Index(S,T,pos):串S和T存在,T是非空串,1<=pos<=StrLength(S).
                    若主串S中存在和串T值相同的子串,则返回它在主串S中
                    第pos个字符之后第一次出现的位置,否则返回0.
    Replace(S,T,V):串S T V存在,T是非空串.用V替换主串S中出现的所有
                    与T相等的不重叠的子串.
    StrInsert(S,pos,T):串S和T存在,1<=pos<=StrLength(S).
                        在串S的第pos个字符之前插入串T.
    StrDelete(S,pos,len):串S存在,1<=pos<=StrLength(S).
                        从串S中删除第pos个字符起长度为len的子串.
endADT
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 40

typedef int Status;
typedef char String[MAXSIZE + 1];

// 思路:把char数组中的值,一个一个的赋值给str,并且求出char数组的长度,把长度存放在str
Status StrAssign(String str, char *chars)
{
    if (strlen(chars) > MAXSIZE)
        return ERROR;
    str[0] = strlen(chars);
    for (int i = 1; i <= str[0]; i++)
        str[i] = *(chars + i - 1);
    return OK;
}

// 思路:从0到MAXSIZE(包括MAXSIZE),把所有的元素都赋值给新串
Status StrCopy(String newStr, String mainStr)
{
    for (int i = 0; i <= mainStr[0]; i++)
        newStr[i] = mainStr[i];
    return OK;
}

// 思路:只需要修改字符串的长度为0即可
Status ClearStr(String str)
{
    str[0] = 0;
    return OK;
}

// 思路:只需要根据str[0]来判断即可
Status StrEmpty(String str)
{
    if (str[0] == 0)
        return true;
    else
        return false;
}

// 思路:只需要返回str[0]即可
int StrLength(String str)
{
    return str[0];
}

// 思路:因为str1和str2本身都是String,所以不用担心越界问题
//      首先使用一个循环,当str1或者str2到尾部时,结束循环
//      在循环内部,逐个对str1和str2进行比较,如果不一致,则返回比较的结果
//      如果直到str1或str2结束,二者都还一致,那么长度短的较小
// 当str1>str2时,返回1; 当str1==str2时,返回0; 当str1<str2时,返回-1
int StrCompare(String str1, String str2)
{
    for (int i = 0; i <= str1[0] && i <= str2[0]; i++)
        if (str1[i] != str2[i])
            return (str1[i] - str2[i]) > 0 ? 1 : -1;
    // 如果上面的循环没有比较出结果,说明str1和str2是主串-子串的关系,此时长度更长的主串要大于子串
    if (str1[0] == str2[0])
        return 0;
    else
        return (str1[0] - str2[0]) < 0 ? -1 : 1;
}

// 思路:当两个字符串拼接到一起的时候,要考虑总长度是否超过了MAXSIZE,下面分'合法'和'越界'两种情况
//      合法:
//      在resultStr的前半段利用for循环,来将prevStr的值逐一赋值过去; 后半段同理
//      越界:
//      前半段不变; 后半段,因为for循环到nextStr[0]会越界,所以for循环到MAXSIZE(包括MAXSIZE)截止
Status Concat(String resultStr, String prevStr, String nextStr)
{
    if (prevStr[0] + nextStr[0] <= MAXSIZE)
    {
        for (int i = 1; i <= prevStr[0]; i++)
            resultStr[i] = prevStr[i];
        for (int i = 1; i < nextStr[0]; i++)
            resultStr[i + prevStr[0]] = nextStr[i];
        resultStr[0] = prevStr[0] + nextStr[0];
    }
    else
    {
        for (int i = 1; i <= prevStr[0]; i++)
            resultStr[i] = prevStr[i];
        for (int i = 1; i <= MAXSIZE - prevStr[0]; i++)
            resultStr[i + prevStr[0]] = nextStr[i];
        resultStr[0] = MAXSIZE;
    }
    return OK;
}

// 思路:
Status SubString(String subStr, String mainStr, int pos, int len)
{
    return OK;
}
