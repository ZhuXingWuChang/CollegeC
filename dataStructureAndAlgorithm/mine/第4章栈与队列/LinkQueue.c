/*
ADT 队列(Queue)
Data
    同线性表.元素具有相同的类型,相邻元素具有前驱和后继关系.
Operation
    InitQueue(*Q):初始化操作,建立一个空队列Q.
    DestoryQueue(*Q):若队列存在,则销毁它.
    ClearQueue(*Q):将队列清空.
    QueueEmpty(Q):若队列Q为空,返回true,否则返回false.
    GetHead(Q,*e):若队列Q存在且非空,用e返回队列Q的队头元素.
    EnQueue(Q,e):若队列Q存在,插入寻元素e到队列Q中并成为队尾元素.
    DeQueue(*Q,*e):删除队列Q中队头元素,并用e返回其值.
    QueueLength(Q):返回队列Q的元素个数.
endADT

这里和顺序栈对rear处理有所不同.
在顺序栈中,为了操作和计算的方便,我们令rear指向队尾元素的后一个元素.
但是在链式栈中,如果也这也操作,就会一直在队尾分配一个空的结点,
所以这里是让rear指向最后一个元素,而不是让rear指向最后一个元素的后面.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *QueuePtr;
typedef struct
{
    QueuePtr front, rear; // 队头队尾指针
} LinkQueue;

void visit(ElemType elem)
{
    printf("%d ", elem);
    return;
}

Status InitQueue(LinkQueue *lqueue)
{
    lqueue->front = lqueue->rear = (QueuePtr)malloc(sizeof(Node));
    if (!lqueue->front)
        return ERROR;
    lqueue->rear->next = NULL;
    return OK;
}

// 销毁队列的时候,会连带队列的头结点一起free
Status DestoryQueue(LinkQueue *lqueue)
{
    QueuePtr deleteNodeP = lqueue->front;
    while (deleteNodeP)
    {
        lqueue->front = lqueue->front->next;
        free(deleteNodeP);
        deleteNodeP = lqueue->front;
    }
    return OK;
}

// 清空队列的时候,会保留队列的头结点
Status ClearQueue(LinkQueue *lqueue)
{
    QueuePtr prevNodeP, currentNodeP;
    prevNodeP = lqueue->front;
    currentNodeP = lqueue->front->next;
    while (currentNodeP)
    {
        prevNodeP = currentNodeP;
        currentNodeP = currentNodeP->next;
        free(prevNodeP);
    }
    lqueue->rear = lqueue->front;
    lqueue->front->next = NULL;
    return OK;
}

Status QueueEmpty(LinkQueue lqueue)
{
    if (lqueue.front == lqueue.rear)
        return true;
    return false;
}

Status GetHead(LinkQueue lqueue, ElemType *elem)
{
    if (lqueue.front == lqueue.rear)
        return ERROR;
    *elem = lqueue.front->next->data;
    return OK;
}

Status EnQueue(LinkQueue *lqueue, ElemType elem)
{
    QueuePtr newNodeP = (QueuePtr)malloc(sizeof(Node));
    if (!newNodeP)
        return ERROR;
    newNodeP->data = elem;
    lqueue->rear->next = newNodeP;
    lqueue->rear = newNodeP;
    newNodeP->next = NULL;
    return OK;
}

Status DeQueue(LinkQueue *lqueue, ElemType *elem)
{
    QueuePtr deleteNodeP;
    if (lqueue->rear == lqueue->rear)
        return ERROR;
    deleteNodeP = lqueue->front->next;
    *elem = deleteNodeP->data;
    lqueue->front->next = deleteNodeP->next;
    if (lqueue->rear == deleteNodeP)
        lqueue->rear = lqueue->front;
    free(deleteNodeP);
    return OK;
}

void QueueTraverse(LinkQueue lqueue)
{
    QueuePtr currentNodeP = lqueue.front->next;
    while (currentNodeP)
    {
        visit(currentNodeP->data);
        currentNodeP = currentNodeP->next;
    }
    printf("\n");
    return;
}

int main(void)
{
    LinkQueue lqueue;
    ElemType elem;
    InitQueue(&lqueue);
    EnQueue(&lqueue, 1);
    EnQueue(&lqueue, 2);
    EnQueue(&lqueue, 3);
    EnQueue(&lqueue, 4);
    EnQueue(&lqueue, 5);
    QueueTraverse(lqueue);
    DeQueue(&lqueue, &elem);
    printf("The deleted element is %d\n", elem);
    GetHead(lqueue, &elem);
    printf("The front node's data is %d\n", elem);
    ClearQueue(&lqueue);
    printf("The Queue is empty? %s\n", QueueEmpty(lqueue) ? "Yes" : "No");
    printf("Did the Queue deleted? %s\n", DestoryQueue(&lqueue) ? "Yes" : "No");

    return 0;
}