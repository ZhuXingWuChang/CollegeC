#include <stdio.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

void visit(SElemType elem)
{
    printf("%d ", elem);
    return;
}

Status InitStack(SqDoubleStack *stack)
{
    stack->top1 = -1;
    stack->top2 = MAXSIZE;
    return OK;
}

Status ClearStack(SqDoubleStack *stack)
{
    stack->top1 = -1;
    stack->top2 = MAXSIZE;
    return OK;
}

bool StackEmpty(SqDoubleStack stack)
{
    if (stack.top1 == -1 && stack.top2 == MAXSIZE)
        return true;
    return false;
}

int StackLength(SqDoubleStack stack)
{
    return (MAXSIZE - stack.top2) + (stack.top1 + 1);
}

Status Push(SqDoubleStack *stack, SElemType elem, int stackNum)
{
    if (stack->top2 - stack->top1 < 1)
        return ERROR;
    else if (1 == stackNum)
        stack->data[++stack->top1] = elem;
    else if (2 == stackNum)
        stack->data[--stack->top2] = elem;
    else
        return ERROR;
    return OK;
}

Status Pop(SqDoubleStack *stack, SElemType *elem, int stackNum)
{
    if (stack->top1 <= -1 || stack->top2 >= MAXSIZE)
        return ERROR;
    else if (1 == stackNum)
        *elem = stack->data[stack->top1--];
    else if (2 == stackNum)
        *elem = stack->data[stack->top2++];
    else
        return ERROR;
    return OK;
}

void StackTraverse(SqDoubleStack stack)
{
    printf("Stack1: ");
    for (int i = 0; i < stack.top1 + 1; i++)
        visit(stack.data[i]);
    printf("\nStack2: ");
    for (int i = MAXSIZE - 1; i > stack.top2 - 1; i--)
        visit(stack.data[i]);
    printf("\n");
    return;
}

int main(void)
{
    SqDoubleStack stack;
    InitStack(&stack);
    Push(&stack, 1, 1);
    Push(&stack, 2, 1);
    Push(&stack, 3, 1);
    Push(&stack, 4, 1);
    Push(&stack, 9, 2);
    Push(&stack, 8, 2);
    Push(&stack, 7, 2);
    Push(&stack, 6, 2);
    StackTraverse(stack);
    SElemType elem;
    Pop(&stack, &elem, 1);
    Pop(&stack, &elem, 2);
    StackTraverse(stack);
    ClearStack(&stack);
    printf("The length of the Stack is: %d\n", StackLength(stack));
    printf("The Stack is empty? %s\n", StackEmpty(stack) ? "Yes" : "No");
    return 0;
}