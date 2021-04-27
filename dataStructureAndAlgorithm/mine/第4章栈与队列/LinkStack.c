#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;

// StackNode是一个结构体,它就是一个普通的结点,具有数据域和指针域
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr; // LinkStackPtr即Link stack pointer

// LinkStack也是一个结构体,它既指向头结点,又保存了栈中的元素个数
typedef struct
{
    LinkStackPtr top;
    int count;
} LinkStack;

void visit(SElemType elem)
{
    printf("%d ", elem);
}

Status InitStack(LinkStack *stack)
{
    stack->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!stack->top)
        return ERROR;
    stack->top = NULL;
    stack->count = 0;
    return OK;
}

Status ClearStack(LinkStack *stack)
{
    LinkStackPtr currentNodePtr, prevNodePtr;
    currentNodePtr = stack->top;
    while (currentNodePtr)
    {
        prevNodePtr = currentNodePtr;
        currentNodePtr = currentNodePtr->next;
        free(prevNodePtr);
    }
    stack->count = 0;
    return OK;
}

Status StackEmpty(LinkStack stack)
{
    if (stack.count <= 0)
        return ERROR;
    return OK;
}

int StackLength(LinkStack stack)
{
    return stack.count;
}

Status GetTop(LinkStack stack, SElemType *elem)
{
    if (!stack.top)
        return ERROR;
    *elem = stack.top->data;
    return OK;
}

Status Push(LinkStack *stack, SElemType elem)
{
    LinkStackPtr newNodePtr = (LinkStackPtr)malloc(sizeof(StackNode));
    newNodePtr->data = elem;
    newNodePtr->next = stack->top;
    stack->top = newNodePtr;
    stack->count++;
    return OK;
}

Status Pop(LinkStack *stack, SElemType *elem)
{
    LinkStackPtr deleteNodePtr = stack->top;
    if (!stack->top)
        return ERROR;
    *elem = stack->top->data;
    stack->top = stack->top->next;
    free(deleteNodePtr);
    stack->count--;
    return OK;
}

void StackTraverse(LinkStack stack)
{
    LinkStackPtr currentNodePtr = stack.top;
    for (int i = 0; i < stack.count; i++)
    {
        visit(currentNodePtr->data);
        currentNodePtr = currentNodePtr->next;
    }
    printf("\n");
}

int main(void)
{
    LinkStack stack;
    SElemType elem;
    visit(InitStack(&stack));
    visit(Push(&stack, 6));
    visit(Push(&stack, 7));
    visit(Pop(&stack, &elem));
    visit(Push(&stack, 8));
    printf("\n");
    StackTraverse(stack);
    visit(StackEmpty(stack));
    visit(ClearStack(&stack));
    visit(StackEmpty(stack));

    return 0;
}