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
    // if (!(*linkList)->next)
    //     ClearList(linkList);
    // 为什么不能写这两句?因为一个未指向任何Node的LinkList引用,会指向内存中非NULL的区域
    // 所以一定会执行ClearList操作,但是其中又没有任何的Node,所以会产生未知的结果
    *linkList = (LinkList)malloc(sizeof(Node));
    if (!(*linkList))
        return ERROR;
    (*linkList)->next = NULL;
    return OK;
}

Status ListEmpty(LinkList linklist)
{
    // 只需要判断有没有第一个结点就行了
    LinkList currentNodeP = linklist->next;
    if (currentNodeP)
        return ERROR;
    return OK;
}

Status ClearList(LinkList *linkList)
{
    // 要清空一个表,就得从第一个结点开始,如果没有第一个结点,那么也就不需要清空了
    // 如果有第一个结点,那么用一个当前指针逐个往后遍历,每遍历一个释放一个
    // 但是这样的话,如果前一个结点已经被释放了,那么就找不到后一个结点了
    // 如果先让当前指针指向后一个结点,那么就找不回前一个结点了
    // 所以需要第二个指针,来存放前一个结点的信息,在当前指针指向后一个结点之后,释放前一个结点
    // 在最后,只剩下一个头结点,不要忘了让头结点的指针域指向NULL
    LinkList currentNodeP, previousNodeP;
    currentNodeP = (*linkList)->next; // 让当前指针指向第一个结点
    while (currentNodeP)              // 如果这不是一个空表
    {
        previousNodeP = currentNodeP;
        currentNodeP = currentNodeP->next;
        free(previousNodeP);
    }
    (*linkList)->next = NULL; // 让头结点的指针域指向NULL
    return OK;
}

int ListLength(LinkList linkList)
{
    // 要确定linkList的长度,就需要对整个表进行遍历,故应该有一个count来记录遍历的次数
    // 需要一个currentNodeP来遍历这个表,如果是空表,表长就为0,所以count的初值为0
    LinkList currentNodeP = linkList->next; // 计数的时候不能把头结点算进去,所以从第一个结点开始
    int count = 0;
    while (currentNodeP)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    return count;
}

Status GetElem(LinkList linkList, int i, ElemType *elem)
{
    // 获得指定位置的元素,我们首先需要一个指针遍历到i
    // 用一个循环来找到第i个结点,用一个count来计数目前找到哪一个了
    // 如果count还没到i,就已经遍历完了(用最后一个结点的指针域为NULL来判断)则退出循环
    // 如果count到i了,那么也退出循环.后面我们判断一下当前指针是否指向NULL或者count是否越界
    // 至此我们已经找到了第i个元素,让*elem把它的值带回来即可
    LinkList currentNodeP = linkList; // 从头结点开始找
    int count = 0;
    while (currentNodeP && count < i)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    if (!currentNodeP || count > i)
        return ERROR;
    *elem = currentNodeP->data;
    return OK;
}

int LocateElem(LinkList linkList, ElemType elem)
{
    // 返回linkList中第一个与elem相等的结点的位置,如果找不到就返回0
    LinkList currentNodeP = linkList; // 从头节点开始
    int count = 0;
    while (currentNodeP)
    {
        if (currentNodeP->data == elem)
            return count;
        count++;
        currentNodeP = currentNodeP->next;
    }
    return 0;
}

Status ListInsert(LinkList *linkList, int i, ElemType elem)
{
    // 注意这里的操作,因为要在第i个结点"之前"插入一个新节点,所以找到第i-1个结点的位置就行
    // 如果第i-1个结点为空,或者count超过了i,那么退出.
    // 至此我们已经找到了第i-1个结点,然后为新节点分配内存并赋值,让新节点指向第i个结点
    // 让第i-1个结点指向新节点,即可
    LinkList currentNodeP, newNodeP;
    currentNodeP = *linkList; // 让当前结点指向头结点
    int count = 0;
    while (currentNodeP && count < i - 1) // 如果是空表,那么不会进入这个循环
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    if (!currentNodeP || count > i - 1)
        return ERROR;
    newNodeP = (LinkList)malloc(sizeof(Node));
    if (!newNodeP) // 分配失败则退出
        return ERROR;
    newNodeP->data = elem;               // 赋值
    newNodeP->next = currentNodeP->next; // 让新结点指向当前结点的下一个
    currentNodeP->next = newNodeP;       // 当当前结点指向新节点
    return OK;
}

Status ListDelete(LinkList *linkList, int i, ElemType *elem)
{
    // 因为要删除第i个结点,所以同样只需要找到第i-1个结点
    // 如果第i-1个结点为空,或者count超过了i-1(因为要删除的是i,如果count超过了i-1,肯定无法删除i了),那么退出.
    // 至此,我们已经找到了第i-1个结点,但是先要让一个结点保存待删除的结点,以便于释放内存
    // 然后让第i-1个结点直接指向第i+1个结点,然后释放掉第i个结点的内存
    LinkList currentNodeP = *linkList; // 指向头结点
    int count = 0;
    while (currentNodeP && count < i - 1)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    if (!currentNodeP || count > i - 1)
        return ERROR;
    LinkList deleteNodeP = currentNodeP->next;
    currentNodeP->next = deleteNodeP->next;
    *elem = deleteNodeP->data;
    free(deleteNodeP);
    return OK;
}

Status ListTraverse(LinkList linkList)
{
    LinkList currentNodeP = linkList->next;
    while (currentNodeP)
    {
        visit(currentNodeP->data);
        currentNodeP = currentNodeP->next;
    }
    return OK;
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
void CreateListTail(LinkList *linkList, int elemNum)
{
    // 我们需要不断在尾结点后面插入一个新的Node,所以依赖一个循环,每循环一次count++
    // 由于我们需要一直不丢失尾结点的位置,所以需要一个tailNodeP指向尾结点
    // 还需要一个newNodeP指向新分配内存的结点,给这个结点赋一个随机值,
    // 然后让新结点指向NULL,让尾结点指向新结点
    LinkList tailNodeP, newNodeP;
    (*linkList) = (LinkList)malloc(sizeof(Node)); // 建立头结点
    (*linkList)->next = NULL;                     // 让头结点的下一个指向NULL
    tailNodeP = *linkList;                        // 此时没有任何结点,所以尾结点指向头结点
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
