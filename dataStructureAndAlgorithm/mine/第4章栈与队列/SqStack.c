/*
ADR 栈(stack)
Data
    同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation
    InitStack(*S): 初始化操作，建立一个空栈S。
    DestoryStack(*S): 若栈存在，则销毁它。
    ClearStack(*S): 将栈清空。
    StackEmpty(S): 若栈为空，返回true，否则返回false。
    GetTop(S, *e): 若栈存在且非空，用e返回S的栈顶元素。
    Push(*S,e): 若栈S存在，插入新元素e到栈S中并成为栈顶元素。
    Pop(*S,*e): 删除栈S中栈顶元素，并用e返回其值。
    StackLength(S): 返回栈S的元素个数。
*/
#include <stdio.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 5
typedef int SElemType;
typedef int Status;
typedef struct
{
    SElemType data[MAXSIZE];
    int top; // 用于栈顶指针
} SqStack;

void visit(SElemType elem)
{
    printf("%d ", elem);
}

Status InitStack(SqStack *stack)
{
    stack->top = -1;
    return OK;
}

// 顺序栈不涉及内存分配的问题，所以也不涉及销毁的问题
// Status DestoryStack(SqStack *stack)
// {
//     return OK;
// }

Status ClearStack(SqStack *stack)
{
    stack->top = -1;
    return OK;
}

bool StackEmpty(SqStack stack)
{
    if (stack.top <= -1)
        return true;
    else
        return false;
}

Status GetTop(SqStack stack, SElemType *elem)
{
    if (stack.top <= -1 || stack.top >= MAXSIZE)
        return ERROR;
    *elem = stack.data[stack.top];
    return OK;
}

Status Push(SqStack *stack, SElemType elem)
{
    if (stack->top < -1 || stack->top >= MAXSIZE - 1)
        return ERROR;
    stack->top++;
    stack->data[stack->top] = elem;
    return OK;
}

Status Pop(SqStack *stack, SElemType *elem)
{
    if (stack->top <= -1 || stack->top >= MAXSIZE)
        return ERROR;
    *elem = stack->data[stack->top];
    stack->top--;
    return OK;
}

int StackLength(SqStack stack)
{
    return stack.top + 1;
}

void StackTraverse(SqStack stack)
{
    for (int i = 0; i < stack.top + 1; i++)
        visit(stack.data[i]);
    printf("\n");
    return;
}

int main(void)
{
    SqStack stack;
    InitStack(&stack);
    Push(&stack, 10);
    Push(&stack, 9);
    Push(&stack, 8);
    SElemType elem;
    Pop(&stack, &elem);
    visit(elem);
    printf("\n");
    StackTraverse(stack);
    GetTop(stack, &elem);
    visit(elem);
    printf("\n");
    ClearStack(&stack);
    printf("The length of the Stack is: %d\n", StackLength(stack));
    printf("The Stack is empty? %s\n", StackEmpty(stack) ? "Yes" : "No");
    return 0;
}