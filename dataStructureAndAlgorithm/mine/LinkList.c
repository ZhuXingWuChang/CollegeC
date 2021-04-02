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
#include <stdlib.h> // 提供了内存分配函数的原型
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next; // 声明了一个指针变量next,next指向Node的地址
} Node;
typedef struct Node *LinkList; // Node是指针,Node的地址是二级指针,所以LinkList是一个二级指针类型

Status visit(ElemType elem);
Status InitList(LinkList *linkList);
Status ClearList(LinkList *linkList);
int ListLength(LinkList linkList);
Status GetElem(LinkList linkList, int i, ElemType *elem);
int LocateElem(LinkList linkList, ElemType elem);
Status ListInsert(LinkList *linkList, int i, ElemType elem);
Status ListDelete(LinkList *linkList, int i, ElemType *elem);
Status ListTraverse(LinkList linkList);
void CreateListHead(LinkList *linklist, int elemNum);
void CreateListTail(LinkList *linkList, int elemNum);

Status visit(ElemType elem)
{
    printf("%d ", elem);
    return OK;
}

Status InitList(LinkList *linkList)
{
    // linklist = (LinkList *)malloc(sizeof(Node)); 这种写法是给一个二级指针分配了内存
    *linkList = (LinkList)malloc(sizeof(Node)); // 给二级指针*linkList分配一个结点的内存
    if (!(linkList))
        return ERROR;
    (*linkList)->next = NULL;
    return OK;
}

Status ClearList(LinkList *linkList)
{

    if (ListLength(*linkList) == 0 && (*linkList) == NULL)
        return ERROR;
    LinkList currentNodeP = (*linkList)->next; // 令当前结点指针指向第一个结点
    LinkList lastNodeP;
    while (currentNodeP->next)
    {
        lastNodeP = currentNodeP;
        currentNodeP = currentNodeP->next;
        free(lastNodeP);
    }
    (*linkList) = currentNodeP;
    return OK;
}

int ListLength(LinkList linkList)
{
    int count = 0;
    LinkList currentNodeP = linkList->next;
    while (currentNodeP)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    return count;
}

Status GetElem(LinkList linkList, int i, ElemType *elem)
{
}

int LocateElem(LinkList linkList, ElemType elem)
{
}

Status ListInsert(LinkList *linkList, int i, ElemType elem)
{
}

// 随机产生elemNum个元素的值,通过在头结点后面不断插入新结点,建立带头结点的单链线性表
void CreateListHead(LinkList *linkList, int elemNum)
{
    // 我们需要不断的在头结点的后面插入一个新的元素,所以依赖一个循环,每循环一次count++
    // 而(*linkList)可以直接获取到头结点,所以不需要一个currentNodeP指向头结点
    // 在循环中,我们需要一个newNodeP来指向新分配内存的结点,给这个结点赋随机值
    // 然后让它指向头结点的下一个,再让头结点指向它.当count等于elemNum时,循环结束
    LinkList newNodeP;
    (*linkList) = (LinkList)malloc(sizeof(Node)); // 建立头结点
    (*linkList)->next = NULL;
    for (int count = 0; count < elemNum; count++)
    {
        newNodeP = (LinkList)malloc(sizeof(Node));
        newNodeP->data = rand() % 100 + 1; // 原型在stdlib.h中
        newNodeP->next = (*linkList)->next;
        (*linkList)->next = newNodeP;
    }
    return;
}

// 随机产生elemNum个元素的值,通过在尾结点后面不断插入新结点,建立带头结点的单链线性表
void CreateListHead(LinkList *linkList, int elemNum)
{
    // 我们需要不断在尾结点后面插入一个新的Node,所以依赖一个循环,每循环一次count++
    // 由于我们需要一直不丢失尾结点的位置,所以需要一个tailNodeP指向尾结点
    // 还需要一个newNodeP指向新分配内存的结点,给这个结点赋一个随机值,
    // 然后让新结点指向NULL,让尾结点指向新结点
    LinkList tailNodeP, newNodeP;
    (*linkList) = (LinkList)malloc(sizeof(Node));
    tailNodeP = (*linkList)->next = NULL;
    for (int count = 0; count < elemNum; count++)
    {
        newNodeP = (LinkList)malloc(sizeof(Node));
        newNodeP->data = rand() % 100 + 1;
        // newNodeP->next = tailNodeP->next; 这一句不能这么写,因为尾结点没有下一个了
        tailNodeP->next = newNodeP;
        tailNodeP = newNodeP;
    }
    newNodeP->next = NULL;
}

int main(void)
{
    LinkList linkList;
    InitList(&linkList);
    printf("The length of the linkList is %d", ListLength(linkList));

    return 0;
}