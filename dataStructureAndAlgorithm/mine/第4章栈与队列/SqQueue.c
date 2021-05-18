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
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20

typedef int ElemType;
typedef int Status;
typedef struct
{
    ElemType data[MAXSIZE];
    int front; // 头指针,指向队列的首个元素的位置
    int rear;  // 尾指针,指向队列下一个能够插入元素的位置
} SqQueue;

void visit(ElemType elem)
{
    printf("%d ", elem);
    return;
}

Status InitQueue(SqQueue *queue)
{
    queue->front = 0;
    queue->rear = 0;
    return OK;
}

Status ClearQueue(SqQueue *queue)
{
    queue->front = 0;
    queue->rear = 0;
    return OK;
}

Status QueueEmpty(SqQueue queue)
{
    if (queue.rear == 0)
        return OK;
    return ERROR;
}

Status GetHead(SqQueue queue, ElemType *elem)
{
    if (queue.rear == 0)
        return ERROR;
    *elem = queue.data[queue.front];
    return OK;
}

Status EnQueue(SqQueue *queue, ElemType elem)
{
    if (queue->rear >= MAXSIZE)
        return ERROR;
    queue->data[queue->rear] = elem;
    queue->rear++;
    return OK;
}

Status DeQueue(SqQueue *queue, ElemType *elem)
{
    if (queue->rear <= 0)
        return ERROR;
    *elem = queue->data[queue->rear - 1];
    queue->rear--;
    return OK;
}

int QueueLength(SqQueue queue)
{
    return queue.rear - queue.front;
}

void QueueTraverse(SqQueue queue)
{
    for (int i = queue.front; i < queue.rear; i++)
        visit(queue.data[i]);
    printf("\n");
    return;
}

int main(void)
{
    SqQueue queue;
    ElemType elem;
    InitQueue(&queue);
    EnQueue(&queue, 6);
    EnQueue(&queue, 7);
    EnQueue(&queue, 8);
    DeQueue(&queue, &elem);
    printf("elem = %d\n", elem);
    GetHead(queue, &elem);
    printf("elem = %d\n", elem);
    QueueTraverse(queue);
    ClearQueue(&queue);
    bool flag = QueueEmpty(queue);
    printf("flag = %d\n", flag);

    return 0;
}