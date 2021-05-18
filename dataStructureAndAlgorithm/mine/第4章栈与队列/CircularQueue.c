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

在循环队列中,我们认为当还剩下一个空位的时候就是队满.
这是为了便于将队空和队满的情况分开.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 5

typedef int Status;
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} CircularQueue;

void visit(ElemType elem)
{
    printf("%d ", elem);
    return;
}

Status InitQueue(CircularQueue *cqueue)
{
    cqueue->front = 0;
    cqueue->rear = 0;
    return OK;
}

Status ClearQueue(CircularQueue *cqueue)
{
    cqueue->front = 0;
    cqueue->rear = 0;
    return OK;
}

Status QueueEmpty(CircularQueue cqueue)
{
    if (cqueue.front == cqueue.rear)
        return OK;
    return ERROR;
}

Status GetHead(CircularQueue cqueue, ElemType *elem)
{
    if (cqueue.front == cqueue.rear)
        return ERROR;
    *elem = cqueue.data[cqueue.front];
    return OK;
}

Status EnQuene(CircularQueue *cqueue, ElemType elem)
{
    if ((cqueue->rear + 1) % MAXSIZE == cqueue->front)
        return ERROR;
    cqueue->data[cqueue->rear] = elem;
    cqueue->rear = (cqueue->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(CircularQueue *cqueue, ElemType *elem)
{
    if (cqueue->front == cqueue->rear)
        return ERROR;
    *elem = cqueue->data[cqueue->front];
    cqueue->front = (cqueue->front + 1) % MAXSIZE;
    return OK;
}

int QueueLength(CircularQueue cqueue)
{
    return ((MAXSIZE - cqueue.front) + (cqueue.rear)) % MAXSIZE;
}

void QueueTraverse(CircularQueue cqueue)
{
    int i;
    i = cqueue.front;
    while ((i + cqueue.front) != cqueue.rear)
    {
        visit(cqueue.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
}

int main(void)
{
    CircularQueue cqueue;
    ElemType elem;
    InitQueue(&cqueue);
    EnQuene(&cqueue, 0);
    EnQuene(&cqueue, 1);
    EnQuene(&cqueue, 2);
    EnQuene(&cqueue, 3);
    DeQueue(&cqueue, &elem);
    DeQueue(&cqueue, &elem);
    EnQuene(&cqueue, 4);
    EnQuene(&cqueue, 0);
    QueueTraverse(cqueue);

    return 0;
}