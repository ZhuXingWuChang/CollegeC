#include <stdio.h>
#include <stdlib.h> // 提供srand()的原形
#include <time.h>   // 提供time()的原形

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20
typedef int Status;
typedef int ElemType;

Status visit(ElemType elem)
{
    printf("%d ", elem);
    return OK;
}

typedef struct Node
{
    ElemType data;     // data是一个普通变量,存放数据
    struct Node *next; // next是一个一级指针变量,存放(下一个Node的)地址
} Node;

typedef struct Node *LinkList; //自定义的LinkList类型,其实是一个结构体指针类型

// 初始化链式线性表
Status InitList(LinkList *linkList) // linkList是结构体指针的指针变量,即结构体Node的二级指针变量
{
    // malloc()分配成功,会返回分配区域的地址,失败则会返回NULL
    *linkList = (LinkList)malloc(sizeof(Node)); // 产生头节点,并使linkList指向此头节点,*linkList是一级指针变量
    if (!(*linkList))                           // 如果失败,即如果*linkList==NULL,即!(*linkList)==TRUE
        return ERROR;
    (*linkList)->next = NULL; // 头节点的指针域为空,即初始化后,链表里只有一个头结点

    return OK;
}

// 初始条件:链式线性表linkList已存在
// 操作结果:将linkList重置为空表
Status ClearList(LinkList *linkList)
{
    LinkList currentNodeP, nextNodeP;
    currentNodeP = (*linkList)->next; // 用指针currentNodeP存放头节点的指针域(即第一个结点的地址)
    while (currentNodeP)              // 如果currentNodeP为非空
    {
        nextNodeP = currentNodeP->next; // 让nextNodeP存放指针currentNodeP的指针域(currentNodeP的下一个结点的地址)
        free(currentNodeP);             // 释放掉指针currentNodeP区域的内存(当前结点的内存)
        currentNodeP = nextNodeP;       // 让currentNodeP为下一个结点的地址
    }                                   // 此时所有结点都已经被释放掉内存,链表中只剩下一个头节点
    (*linkList)->next = NULL;           // 头节点的指针域为空

    return OK;
}

// 初始条件:链式线性表linkList已存在,1<=i<=ListLength(linkList)
// 操作结果:用elem返回linkList中第i个数据元素的值
int ListLength(LinkList linkList)
{
    int i = 0;
    LinkList currentNodeP = linkList->next; // currentNodeP指向第一个结点
    while (currentNodeP)
    {
        i++;
        currentNodeP = currentNodeP->next;
    }
    return i;
}

// 初始条件:链式线性表linkList已存在,1<=i<=ListLength(linkList)
// 操作结果:用elem返回linkList中第i个数据元素的值
Status GetElem(LinkList linkList, int i, ElemType *elem)
{
    int j = 1;                              // j为计数器
    LinkList currentNodeP = linkList->next; // 让currentNodeP指向第一个结点
    while (currentNodeP && j < i)           // currentNodeP非空,或者还没遍历到i时,继续
    {
        currentNodeP = currentNodeP->next; // 让currentNodeP指向下一个结点
        j++;
    }
    if (!currentNodeP || j > i) // currentNodeP==NULL的情况是currentNodeP到了链表的末尾,j>i的情况是超过了链表长度
        return ERROR;
    *elem = currentNodeP->data;
    return OK;
}

// 初始条件:链式线性表linkList已经存在
// 操作结果:返回linkList中第一个与elem满足相等关系的数据元素的位序
// 若这样的元素不存在,则返回值为0
int LocateElem(LinkList linkList, ElemType elem)
{
    int i = 0;
    LinkList currentNodeP = linkList->next;
    while (currentNodeP)
    {
        i++;
        if (currentNodeP->data == elem)
            return i;
    }

    return 0;
}

// 初始条件:链式线性表linkList已存在,1<=i<=ListLength(linkList)
// 操作结果:在linkList中第i个位置之前插入新的数据元素elem,linkList的长度加1
Status ListInsert(LinkList *linkList, int i, ElemType elem)
{
    LinkList currentNodeP, insertNodeP;
    currentNodeP = (*linkList)->next; // 让currentNodeP指向第一个结点.为什么不指向头节点?因为反正是要插入一个的.
    int j = 1;
    while (currentNodeP && j < i)
    {
        currentNodeP = currentNodeP->next;
        j++;
    }
    if (!currentNodeP || j > i)
        return ERROR;
    insertNodeP = (Node *)malloc(sizeof(Node));
    insertNodeP->next = currentNodeP->next;
    currentNodeP->next = insertNodeP; // 因为S是一个LinkList(即Node的指针),所以不需要用&运算符了
    insertNodeP->data = elem;
    return OK;
}

// 初始条件:链式线性表linkList已存在,1<=i<=ListLength(linkList)
// 操作结果:删除linkList的第i个数据元素,并用elem返回其值,linkList的长度减1
Status ListDelete(LinkList *linkList, int i, ElemType *elem)
{
    LinkList currentNodeP, nextNodeP;
    currentNodeP = *linkList; // 让currentNodeP指向头节点.为什么不指向第一个结点?因为可能没有结点.
    int j = 1;
    while (currentNodeP->next && j < i)
    {
        currentNodeP = currentNodeP->next;
        j++;
    }
    if (!currentNodeP || j > i)
        return ERROR;
    // 现在可以确认,currentNodeP存在且i范围合法,且currentNodeP正指向i(待删除)的结点
    *elem = currentNodeP->data;
    nextNodeP = currentNodeP->next;
    free(currentNodeP);
    currentNodeP = nextNodeP->next;
    // currentNodeP->next = currentNodeP->next->next; 如果这样,那么会导致内存泄露
    return OK;
}

// 初始条件:链式线性表linkList已存在,1<=i<=ListLength(linkList)
// 操作结果:一次对linkList的每个数据元素输出
Status ListTraverse(LinkList linkList)
{
    LinkList currentNodeP = linkList->next;
    int i = 1;
    while (currentNodeP && i <= ListLength(linkList))
    {
        visit(currentNodeP->data);
        currentNodeP = currentNodeP->next;
        i++;
    }
    if (i == ListLength(linkList))
        return OK;
    return ERROR;
}

// 随机产生elemNum个元素的值,建立带表头结点的单链线性表L(头插法)
void CreateListHead(LinkList *linklist, int elemNum)
{
    LinkList currentNodeP, tailNodeP;
    srand(time(0)); // 初始化随机种子
    *linklist = (LinkList)malloc(sizeof(Node));
    tailNodeP = *linklist; // 此时只有一个头节点,所以头结点和尾结点是同一结点
    for (int i = 1; i <= elemNum; i++)
    {
        currentNodeP = (Node *)malloc(sizeof(Node));
        currentNodeP->data = rand() % 100 + 1; // 随机生成100以内的数字
        tailNodeP->next = currentNodeP;        // 把当前节点插入到尾节点后面
        tailNodeP = currentNodeP;              // 尾结点后移一位
    }
    tailNodeP->next = NULL;
}
