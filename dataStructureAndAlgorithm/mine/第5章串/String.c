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
    StrInsert(S,pos,T):串S和T存在,1<=pos<=StrLength(S).
                        在串S的第pos个字符之前插入串T.
    StrDelete(S,pos,len):串S存在,1<=pos<=StrLength(S).
                        从串S中删除第pos个字符起长度为len的子串.
    Replace(S,T,V):串S T V存在,T是非空串.用V替换主串S中出现的所有
                    与T相等的不重叠的子串.
endADT
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 5

typedef int Status;
typedef char String[MAXSIZE + 1];

// 思路:把char数组中的值,一个一个的赋值给str,并且求出char数组的长度,把长度存放在str
/*
params:
    str:    用来返回初始化后的字符串
    *chars: 一个字符数组,里面字符串需要的值
*/
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
/*
params:
    newStr: 用来存储复制后的字符串
    oldStr: 这个字符串被复制
*/
Status StrCopy(String newStr, String oldStr)
{
    for (int i = 0; i <= oldStr[0]; i++)
        newStr[i] = oldStr[i];
    return OK;
}

// 思路:只需要修改字符串的长度为0即可
Status ClearStr(String str)
{
    str[0] = 0;
    return OK;
}

// 思路:只需要根据str[0]来判断即可
_Bool StrEmpty(String str)
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
/*
params:
    resultStr:  用来返回两个字符串拼接好的结果
    prevStr:    在拼接中位于前面的字符串
    nextStr:    在拼接中位于后面的字符串
*/
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

// 思路:用一个for循环,将mainStr[subStartP]到mainStr[subStartP+subLen-1]赋值给subStr[1]到subStr[subLen]
//      在循环开始之前,要检验subStartP和subLen的值是否合法
//      在循环结束之后,要将subLen赋值给subStr[0]
/*
params:
    subStr:     返回子串的结果
    mainStr:    传入的主串
    subStartP:  子串开始的位置
    subLen:     子串的长度,即subStartP到subStartP+subLen-1这个位置是子串
*/
Status SubString(String subStr, String mainStr, int subStartP, int subLen)
{
    if (subStartP < 1 || subStartP > mainStr[0] || subLen < 0 || subLen + subStartP > mainStr[0] + 1)
        return ERROR;
    for (int i = 1; i <= subLen; i++)
        subStr[i] = mainStr[subStartP + i - 1];
    subStr[0] = subLen;
    return OK;
}

// 思路:需要两个下标i和j,分别用他们来访问主串和子串
//      进入循环(如果i和j都未超过数组的长度)
//          如果mainStr[i]和desStr[j]相等
//              i和j向前移动一位
//          一旦mainStr[i]和desStr[j]不相等
//              j回溯到1,并且i回溯到i-j+2也就是i和j开始比较的起始位置+1的位置
//      循环end
//      如果是因为j越界而结束循环
//          找到了匹配串,返回OK
//      否则,j没有越界而结束了循环
//          没有找到匹配串,返回ERROR
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
    while (mainCursor <= mainStr[0] && desCursor < desStr[0])
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
    //mainStr:      abcd
    //desStr:        bc
    //queryStartP:   2
    //mainCursor:    234
    //desCursor:     123(越界,退出循环)
    //return:        2(2=4-2 即 return mainCursor-desStr[0])
    if (desCursor > desStr[0])
        return mainCursor - desStr[0];
    else
        return 0;
}

// 思路:需要一个strOfMain来存放mainStr中的子串
//      进入循环(当mainCursor不越界时)
//          取出以mainCursor为首的,长度和desStr一致的子串
//          如果子串和desStr相等
//              返回mainCursor
//      循环end
//      返回0
/*
params:
    desStr:     用户要查找的目的串,需要在主串中寻找到该目的串(destination String)
    mainStr:    主串,同样由用户传入
    queryStartP:从主串中开始查找子串的起始位置
*/
int Index2(String desStr, String mainStr, int queryStartP)
{
    String strOfMain;
    int mainCursor = queryStartP;
    while (mainCursor - 1 + desStr[0] < mainStr[0])
    {
        SubString(strOfMain, mainStr, mainCursor, desStr[0]);
        if (StrCompare(strOfMain, desStr))
            return mainCursor;
        mainCursor++;
    }
    return 0;
}

// 思路:首先判断insertPos是否越界
//      然后分两种情况,一种是插入后超过了最大长度,另一种是插入后没有超过最大长度
//      如果未超过最大长度(返回true)
//          首先从(主串末尾+插入串的长度)开始,将串的余下部分都向后移动insertStr[0]个位置
//          然后从insertPos开始,将insertStr复制到这个空出来的空间里
//      如果超过了最大长度(返回false)
//          首先从(主串末尾)开始,将串的余下部分都向后移动insertStr[0]个位置
//          然后从insertPos开始,将insertStr复制到这个空出来的空间里
/*
params:
    mainStr:    向该主串中插入一个子串
    insertPos:  子串插入到主串之后,子串的第一个字符所处的位置
    insertStr:  所插入的子串
*/
_Bool StrInsert(String mainStr, int insertPos, String insertStr)
{
    if (insertPos < 1 || insertPos > MAXSIZE + 1)
        return ERROR;
    if (mainStr[0] + insertStr[0] <= MAXSIZE)
    {
        for (int i = mainStr[0]; i >= insertPos; i--) // 以移动多少长度得到循环条件的关系
            mainStr[i + insertStr[0]] = mainStr[i];   // 以移动的间隔得到赋值条件的关系
        for (int i = 1; i <= insertStr[0]; i++)       // 以插入多少长度得到循环条件的关系
            mainStr[i - 1 + insertPos] = insertStr[i];
        return true;
    }
    else
    {
        for (int i = MAXSIZE + 1 - insertStr[0]; i >= insertPos; i--) // 以移动多少长度得到循环关系
            mainStr[i + insertStr[0]] = mainStr[i];                   // 以移动的间隔得到赋值关系
        for (int i = 1; i <= insertStr[0]; i++)                       // 以插入多少长度得到循环条件的关系
            mainStr[i - 1 + insertPos] = insertStr[i];
        return false;
    }
}

// 思路:首先检查deletePos和len是否越界
//      接着,需要移动从末尾到deletePos+len这一段的字符串,向前移动len个长度
//      for(int i=deletePos+len; i<=str[0]; i++)
//          str[i-len]=str[i];
//      str[0]-=len;
/*
params:
    str:        对该串进行子串的删除操作
    deletePos:  从deletePos位置开始删除一个子串
    len:        删除的子串长度为len
*/
Status StrDelete(String str, int deletePos, int len)
{
    if (deletePos < 1 || deletePos > str[0] || len < 1 || deletePos + len > str[0] + 1)
        return ERROR;
    for (int i = deletePos + len; i < str[0]; i++)
        str[i - len] = str[i];
    str[0] -= len;
    return OK;
}

// 思路:这个操作最好使用其它的函数,单独实现的话需要考虑许多情况,比如替换后是否越界等
//      queryStartP=1,从开头开始匹配
//      do
//          从查找的起始位置,获取长度和旧串相同的子串
//          如果在这个位置之后,有子串和旧串模式匹配,那么起始位置更新至旧串的开头(使用模式匹配)
//              删除主串中的旧子串
//              在删除的位置增加一个新子串
//              起始位置更新至旧串的结尾
//      while(queryStartP非0)
/*
params:
    oldSubStr:  传入参数,指出要删除的旧串
    mainStr:    传入参数,对该主串进行替换操作
    newSubStr:  传入参数,指出要替换旧串的新串
*/
Status Replace(String oldSubStr, String mainStr, String newSubStr)
{
    int queryStartP = 1;
    String subStr;
    do
    {
        SubString(subStr, mainStr, queryStartP, oldSubStr[0]);
        if (queryStartP = Index(subStr, mainStr, queryStartP))
        {
            StrDelete(mainStr, queryStartP, oldSubStr[0]);
            StrInsert(mainStr, queryStartP, newSubStr);
            queryStartP += newSubStr[0];
        }
    } while (queryStartP);
    return OK;
}

int main(void)
{
    String str1, str2;
    StrAssign(str1, "abcde");
    StrAssign(str2, "tt");
    StrInsert(str1, 2, str2);
    return 0;
}