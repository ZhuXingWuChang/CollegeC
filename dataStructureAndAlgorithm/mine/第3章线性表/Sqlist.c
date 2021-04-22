/*
 * 线性表的定义：
 * -------------------------------------------------------
 * ADT 线性表(List)
 * Data
 *      线性表的数据对象为集合{a1,a2, ...... ,an},每个元素的类型均为DataType。其中，除第一个
 * 元素a1之外，每一个元素有且只有一个直接前驱元素，除了最后一个元素an之外，每个元素有且只有一个
 * 直接后继元素。数据元素之间的关系是一对一的关系。
 * Operation
 *      InitList(*L):初始化操作，建立一个空的线性表L。
 *      ListEmpty(L):若线性表为空，返回true，否则返回false
 *      ClearList(*L):将线性表清空。
 *      GetElem(L, i, *e):将线性表L中的第i个位置的元素的值返回给e。
 *      LocateElem(L, e):在线性表L中查找与e相等的元素，成功则返回下标，失败则返回0。
 *      ListInsert(*L, i, e):在线性表的第L个位置插入新元素e。
 *      ListDelete(*L, i, *e):删除线性表L中的第i个位置元素，并用e返回其值。
 *      ListLength(L):返回线性表L的元素个数。
 * endADT
 */
#include <stdio.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef int ElemType;
typedef struct // 线性表的顺序存储结构的代码
{
    ElemType data[MAXSIZE]; // 数组，存储数据元素
    int length;             // 线性表当前长度
} SqList;

Status InitList(SqList *L);
Status ListEmpty(SqList L);
Status ClearList(SqList *L);
Status GetElem(SqList L, int i, ElemType *e);
Status LocateElem(SqList L, ElemType e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);
int ListLength(SqList L);

// 初始化一个顺序表
Status InitList(SqList *L)
{
    SqList list;
    list.length = 0;
    for (int i = 0; i < MAXSIZE; i++)
        list.data[i] = 0;
    *L = list;
    return OK;
}

// 判断线性表是否为空
Status ListEmpty(SqList L)
{
    if (L.length > 0)
        return ERROR;
    L.length = 0;
    return OK;
}

// 将线性表清空
Status ClearList(SqList *L)
{
    if (L->length != 0)
    {
        L->length = 0;
        return OK;
    }
    return OK;
}

// 将所有在线性表Lb但不在线性表La中的元素插入到La末尾
void unionL(SqList *La, SqList Lb)
{
    int La_len, Lb_len, i;
    ElemType e; // 用来存储Lb的元素的值
    La_len = ListLength(*La);
    Lb_len = ListLength(Lb);
    for (i = 1; i <= Lb_len; i++) // 对整个Lb表进行一次遍历
    {
        GetElem(Lb, i, &e);              // 获得Lb中第i个元素的值
        if (!LocateElem(*La, e))         // 如果在La中没有与e相等的元素
            ListInsert(La, ++La_len, e); // 那么就把e插入到La的末尾
    }
}

// 用e返回第i个位置的元素
Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i - 1];
    return OK;
}

// 查找表中与e相等的元素
Status LocateElem(SqList L, ElemType e)
{
    if (L.length <= 0)
        return ERROR;
    for (int i = 0; i < L.length; i++)
        if (e == L.data[i])
            return OK;
    return ERROR;
}

// 向i的位置插入元素e
Status ListInsert(SqList *L, int i, ElemType e)
{
    if (L->length == MAXSIZE) // 顺序线性表已经满
        return ERROR;
    if (i < 1 || i > L->length + 1) // 当i比第一位置小或者比最后一位位置大时
        return ERROR;
    if (i <= L->length)
        for (int k = L->length - 1; k >= i - 1; k--)
            L->data[k + 1] = L->data[k];
    L->data[i - 1] = e; // 对顺序线性表中第i个元素进行赋值
    L->length++;        // 表长加一
    return OK;
}

// 删除第i个位置的元素，并用e返回
Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0)
        return ERROR;
    if (i < 1 || i > L->length)
        return ERROR;
    *e = L->data[i - 1];
    if (i < L->length)
    {
        for (int k = i; k < L->length; k++)
            L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}

int ListLength(SqList L)
{
    return L.length;
}

int main(void)
{
    SqList list;
    bool flag;
    ElemType element;

    flag = InitList(&list);
    printf("I just initialized the SqList.\n");
    printf("Now, let's add some elements to the SqList.\n");
    for (int i = 1; i <= MAXSIZE; i++)
        ListInsert(&list, i, i);
    for (int i = 1; i <= ListLength(list); i++)
        printf("%d ", list.data[i - 1]);
    printf("\n");

    flag = ListEmpty(list);
    printf("The SqList is empty? %d.\n", flag);

    flag = ClearList(&list);
    printf("The SqList is empty? %d.\n", flag);

    printf("I just inserted some elements into the SqList.\n");
    for (int i = 1; i <= MAXSIZE; i++)
        ListInsert(&list, i, i);
    flag = GetElem(list, 6, &element);
    printf("The sixth element is %d.\n", element);

    flag = LocateElem(list, -1);
    printf("-1 is in the SqList? %d.\n", flag);

    printf("Now, let's delete the top 10 elements.\n");
    for (int i = 1; i <= 10; i++)
        ListDelete(&list, 1, &element);
    for (int i = 1; i <= ListLength(list); i++)
        printf("%d ", list.data[i - 1]);
    printf("\n");

    ClearList(&list);
    printf("Bye!\n");

    return 0;
}
