/*
在这个静态链表中,规定以SLL[0]为备用链表的头结点,以SLL[MAXSIZE-1]为使用链表的头结点.
并且备用域的最后一个结点的cursor指向SLL[MAXSIZE-1],使用域的最后一个结点的cursor指向空(0)
 */
#include <stdio.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 1000

typedef int Status;
typedef char ElemType;
typedef struct
{
    ElemType data;
    int cursor; // cursor:光标, 为0时表示无指向
} Node, StaticLinkList[MAXSIZE];

Status visit(ElemType elem)
{
    printf("%c ", elem);
    return OK;
}

// 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，"0"表示空指针
Status InitList(StaticLinkList space)
{
    // 在初始化阶段,所有的Node都是备用域,故应该让space[0].cursor=1.
    // 又使用域一个结点都没有,故应该让space[MAXSIZE-1].cursor=0.
    for (int i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cursor = i + 1;
    }
    space[MAXSIZE - 1].cursor = 0;
    return OK;
}

// spare: 备用的 inUse: 使用的
// 若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space)
{
    // 首先找到备用链表的第一个结点
    // 如果备用链表有结点供分配,那么让备用链表的cursor后移一个
    // (否则就是备用链表指向空,返回0)
    // 返回这第一个结点的下标
    int mallocNodeIndex = space[0].cursor;
    if (space[0].cursor)                                 // 如果备用链表有结点供分配的话
        space[0].cursor = space[mallocNodeIndex].cursor; // 让备用链表的头结点向后移动一个
    return mallocNodeIndex;                              // 返回备用链表的第一个结点
}

// 将下标为index的空闲结点回收到备用链表
void Free_SLL(StaticLinkList space, int freeNodeIndex)
{
    // 找到这个下标对应的结点,将其加入到space[0]的下一个结点(即备用链表的第一个结点)处即可
    space[freeNodeIndex].cursor = space[0].cursor;
    space[0].cursor = freeNodeIndex;
    return;
}

/* 初始条件：静态链表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(StaticLinkList space)
{
    int count = 0;
    int currentNodeIndex = space[MAXSIZE - 1].cursor; // 指向第一个结点
    while (currentNodeIndex)
    {
        count++;
        currentNodeIndex = space[currentNodeIndex].cursor;
    }
    return count;
}

/*  在L中第i个元素之前插入新的数据元素e   */
Status ListInsert(StaticLinkList space, int index, ElemType elem)
{
    // 需要一个currentNodeIndex存放当前结点,用它遍历到第i-1个结点,需要一个insertNodeIndex存放分配的新结点
    int currentNodeIndex, insertNodeIndex;
    currentNodeIndex = MAXSIZE - 1; // 让当前索引指向头结点
    if (index < 1 || index > ListLength(space) + 1)
        return ERROR;
    insertNodeIndex = Malloc_SLL(space); // 给插入的结点分配一个内存
    if (insertNodeIndex)                 // 如果分配成功
    {
        space[insertNodeIndex].data = elem;
        for (int i = 0; i < ListLength(space) - 1; i++)
            currentNodeIndex = space[currentNodeIndex].cursor; // 找到第i-1个结点的索引
        space[insertNodeIndex].cursor = space[currentNodeIndex].cursor;
        space[currentNodeIndex].cursor = insertNodeIndex;
        return OK;
    }
    return ERROR;
}

/*  删除在L中第i个数据元素   */
Status ListDelete(StaticLinkList space, int deleteNodeInder)
{
    // 需要一个currentNodeIndex存放当前结点,用它遍历到第i-1个结点
    int currentNodeIndex;
    currentNodeIndex = MAXSIZE - 1; // 让当前索引指向头结点
    if (deleteNodeInder < 1 || deleteNodeInder > ListLength(space))
        return ERROR;
    for (int i = 0; i < ListLength(space) - 1; i++)
        currentNodeIndex = space[currentNodeIndex].cursor;                         // 找到第i-1个结点的索引
    space[currentNodeIndex].cursor = space[space[currentNodeIndex].cursor].cursor; // 让第i-1个结点直接指向第i+1个结点
    return OK;
}

Status ListTraverse(StaticLinkList space)
{
    int currentNodeIndex = MAXSIZE - 1;
    for (int i = 0; i < ListLength(space); i++)
    {
        currentNodeIndex = space[currentNodeIndex].cursor;
        visit(space[currentNodeIndex].data);
    }
    printf("\n");
    return OK;
}

int main(void)
{
    StaticLinkList L;
    Status i;
    i = InitList(L);
    printf("L.length=%d\n", ListLength(L));

    i = ListInsert(L, 1, 'F');
    i = ListInsert(L, 1, 'E');
    i = ListInsert(L, 1, 'D');
    i = ListInsert(L, 1, 'B');
    i = ListInsert(L, 1, 'A');

    printf("L.data=");
    ListTraverse(L);

    i = ListInsert(L, 3, 'C');
    printf("L.data=");
    ListTraverse(L);

    i = ListDelete(L, 1);
    printf("L.data=");
    ListTraverse(L);

    return 0;
}