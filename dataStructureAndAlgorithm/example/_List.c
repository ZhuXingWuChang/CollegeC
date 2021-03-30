#include <stdio.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20    //存储空间初始分配量
typedef int ElemType; // ElemType根据实际情况而定,这里假设为int
typedef struct
{
    ElemType data[MAXSIZE]; // 数据,存储数据元素
    int length;             // 线性表当前长度
} SqList;

typedef int Status; // Status是函数的类型,其值是函数结果状态代码,如OK等

// 访问某一个元素
Status visit(ElemType elem)
{
    printf("%d ", elem);
    return OK;
}

// 初始化顺序线性表
Status InitList(SqList *sequenceList)
{
    sequenceList->length = 0;
    return OK;
}

// 初始条件:顺序线性表sequenceList已经存在
// 操作结果:若sequenceList为空表,则返回TRUE,否则返回FALSE
Status ListEmpty(SqList sequenceList)
{
    if (sequenceList.length == 0)
        return TRUE;
    else
        return FALSE;
}

// 初始条件:顺序线性表sequenceList已经存在
// 操作结果:将sequenceList重置为空表
Status ClearList(SqList *sequenceList)
{
    sequenceList->length = 0;
    return OK;
}

// 初始条件:顺序线性表sequenceList已存在
// 操作结果:返回sequenceList中数据元素个数
int ListLength(SqList sequenceList)
{
    return sequenceList.length;
}

// 初始条件:先行顺序表sequenceList已存在, 1<=i<=ListLength(sequenceList)
// 操作结果:用elem返回sequenceList中第i个数据元素的值,注意i是指位置,第1个位置的数组是从0开始
Status GetElem(SqList sequenceList, int i, ElemType *elem)
{
    if (sequenceList.length == 0 || i < 1 || i > sequenceList.length)
        return ERROR;
    *elem = sequenceList.data[i - 1];

    return OK;
}

// 初始条件:顺序线性表sequenceList已存在
// 操作结果:返回sequenceList中第一个与elem满足相等关系的数据元素的位序
// 若这样的元素不存在,则返回值为0
Status LocateElem(SqList sequenceList, ElemType elem)
{
    int i;
    if (sequenceList.length == 0)
        return 0;
    for (i = 0; i < sequenceList.length; i++)
    {
        if (sequenceList.data[i] == elem)
            break;
    }
    if (i >= sequenceList.length)
        return 0;

    return i + 1;
}

// 初始条件:线性顺序表sequenceList已存在,1<=i<=ListLength(sequenceList)
// 操作结果:在sequenceList中第i个位置之前插入新的数据元素elem,sequenceList的长度加1
Status ListInsert(SqList *sequenceList, int i, ElemType elem)
{
    int k;
    if (sequenceList->length == MAXSIZE) // 顺序线性表已满
        return ERROR;
    if (i < 1 || i > sequenceList->length + 1) // 当i比第一位置小或者比最后一位的后一位还要大时
        return ERROR;
    if (i <= sequenceList->length) // 若插入数据位置不在表尾
    {
        for (k = sequenceList->length - 1; k >= i - 1; k--)
            sequenceList->data[k + 1] = sequenceList->data[k];
    }
    sequenceList->data[i - 1] = elem; // 将新元素插入
    sequenceList->length++;

    return OK;
}

// 初始条件:顺序线性表sequenceList已存在,1<=i<=ListLength(sequenceList)
// 操作结果:删除sequenceList的第i个数据元素,并用elem返回其值,sequenceList的长度减1
Status ListDelete(SqList *sequenceList, int i, ElemType *elem)
{
    int k;
    if (sequenceList->length == 0) // 线性表为空
        return ERROR;
    if (i < 1 || i > sequenceList->length) // 删除位置不正确
        return ERROR;
    *elem = sequenceList->data[i - 1];
    if (i < sequenceList->length) // 如果删除不是最后位置
    {
        for (k = i; k < sequenceList->length; k++) // 将删除位置后继元素前移
            sequenceList->data[k - 1] = sequenceList->data[k];
    }
    sequenceList->length--;

    return OK;
}

// 初始条件:顺序线性表sequenceList已存在
// 操作结果:一次对sequenceList的每个数据元素输出
Status ListTraverse(SqList sequenceList)
{
    int i;
    for (i = 0; i < sequenceList.length; i++)
        visit(sequenceList.data[i]);
    printf("\n");
    return OK;
}

// 将所有的在线性表listB中但不在listA中的数据元素插入到listA中
void unionL(SqList *listA, SqList listB)
{
    int La_len, Lb_len, i;
    ElemType elem;               // 声明与listA和listB相同的数据元素elem
    La_len = ListLength(*listA); // 求线性表的长度
    Lb_len = ListLength(listB);
    for (i = 1; i <= Lb_len; i++)
    {
        GetElem(listB, i, &elem);              // 取listB中第i个数据元素赋给elem
        if (!LocateElem(*listA, elem))         // listA中不存在和elem相同的数据元素
            ListInsert(listA, ++La_len, elem); // 表长加一后,插入到listA的表尾
    }
}

int main()
{

    SqList sequenceList;
    SqList listB;

    ElemType elem;
    Status i;
    int j, k;
    i = InitList(&sequenceList);
    printf("After initializing the sequenceList: sequenceList.length=%d\n", sequenceList.length);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&sequenceList, 1, j);
    printf("After inserting 1 to 5 in the header of sequenceList: sequenceList.data=");
    ListTraverse(sequenceList);

    printf("sequenceList.length=%d \n", sequenceList.length);
    i = ListEmpty(sequenceList);
    printf("Is sequenceList null? i=%d(1:Yes 0:No)\n", i);

    i = ClearList(&sequenceList);
    printf("After clearing sequenceList: sequenceList.length=%d\n", sequenceList.length);
    i = ListEmpty(sequenceList);
    printf("Is sequenceList null? i=%d(1:Yes 0:No)\n", i);

    for (j = 1; j <= 10; j++)
        ListInsert(&sequenceList, j, j);
    printf("After inserting 1 to 10 at the end of the sequenceList table: sequenceList.data=");
    ListTraverse(sequenceList);

    printf("sequenceList.length=%d \n", sequenceList.length);

    ListInsert(&sequenceList, 1, 0);
    printf("After inserting 0 into the header of sequenceList: sequenceList.data=");
    ListTraverse(sequenceList);
    printf("sequenceList.length=%d \n", sequenceList.length);

    GetElem(sequenceList, 5, &elem);
    printf("The value of the fifth element is: %d\n", elem);
    for (j = 3; j <= 4; j++)
    {
        k = LocateElem(sequenceList, j);
        if (k)
            printf("The value of the %dth element is %d\n", k, j);
        else
            printf("There are no elements of value %d\n", j);
    }

    k = ListLength(sequenceList); /* k为表长 */
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&sequenceList, j, &elem); /* 删除第j个数据 */
        if (i == ERROR)
            printf("Failed to delete the %dth data\n", j);
        else
            printf("The delete element value of the %dth element is: %d\n", j, elem);
    }
    printf("The elements of sequenceList are printed in sequence: ");
    ListTraverse(sequenceList);

    j = 5;
    ListDelete(&sequenceList, j, &elem); /* 删除第5个数据 */
    printf("The delete element value of the %dth element is: %d\n", j, elem);

    printf("The elements of sequenceList are printed in sequence: ");
    ListTraverse(sequenceList);

    //构造一个有10个数的listB
    i = InitList(&listB);
    for (j = 6; j <= 15; j++)
        i = ListInsert(&listB, 1, j);

    unionL(&sequenceList, listB);
    printf("listB.data=");
    ListTraverse(listB);

    printf("Output the elements of sequenceList combined with listB in sequence: ");
    ListTraverse(sequenceList);

    return 0;
}