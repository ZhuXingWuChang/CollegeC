#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define ElemType int

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *CircularLinkList;
typedef int Status;

Status visit(ElemType elem)
{
    printf("%d ", elem);
    return OK;
}

Status InitList(CircularLinkList *CLL)
{
    *CLL = (CircularLinkList)malloc(sizeof(Node));
    if (!(*CLL))
        return ERROR;
    (*CLL)->next = *CLL;
    return OK;
}

Status ListEmpty(CircularLinkList CLL)
{
    CircularLinkList headNodeP = CLL;
    if (headNodeP->next != headNodeP)
        return ERROR;
    return OK;
}

Status ClearList(CircularLinkList *CLL)
{
    CircularLinkList currentNodeP = *CLL;
    CircularLinkList headNodeP = *CLL;
    CircularLinkList previousNodeP;
    while (currentNodeP->next != headNodeP)
    {
        previousNodeP = currentNodeP;
        currentNodeP = currentNodeP->next;
        free(previousNodeP);
    }
    headNodeP->next = headNodeP;
    return OK;
}
int ListLength(CircularLinkList CLL)
{
    CircularLinkList currentNodeP = CLL;
    CircularLinkList headNodeP = CLL;
    int count = 0;
    while (currentNodeP->next != headNodeP)
    {
        currentNodeP = currentNodeP->next;
        count++;
    }
    return count;
}
Status GetElem(CircularLinkList CLL, int index, ElemType *elem)
{
    CircularLinkList currentNodeP = CLL;
    CircularLinkList headNodeP = CLL;
    int count = 0;
    if (index < 1)
        return ERROR;
    while (currentNodeP->next != headNodeP)
    {
        currentNodeP = currentNodeP->next;
        count++;
        if (count == index)
        {
            *elem = currentNodeP->data;
            return OK;
        }
    }
    return ERROR;
}
int LocateElem(CircularLinkList CLL, ElemType elem)
{
    CircularLinkList currentNodeP = CLL;
    CircularLinkList headNodeP = CLL;
    int count = 0;
    while (currentNodeP->next != headNodeP)
    {
        currentNodeP = currentNodeP->next;
        count++;
        if (currentNodeP->data == elem)
            return count;
    }
    return 0;
}

Status ListInsert(CircularLinkList *CLL, int index, ElemType elem)
{
    CircularLinkList currentNodeP = *CLL;
    CircularLinkList headNodeP = *CLL;
    CircularLinkList insertNodeP = NULL;
    int count = 0;
    while (currentNodeP->next != headNodeP && count < index - 1)
    {
        currentNodeP = currentNodeP->next;
        count++;
    } // 如果index值合法,循环退出时,currentNodeP应当指向第i-1个Node
    if (count > index - 1)
        return ERROR;
    insertNodeP = (CircularLinkList)malloc(sizeof(Node));
    if (!insertNodeP)
        return ERROR;
    insertNodeP->data = elem;
    insertNodeP->next = currentNodeP->next;
    currentNodeP->next = insertNodeP;
    return OK;
}

Status ListDelete(CircularLinkList *CLL, int index, ElemType *elem)
{
    CircularLinkList currentNodeP = *CLL;
    CircularLinkList headNodeP = *CLL;
    CircularLinkList deleteNodeP = NULL;
    int count = 0;
    while (currentNodeP->next != headNodeP && count < index - 1)
    {
        currentNodeP = currentNodeP->next;
        count++;
    }
    if (currentNodeP->next == headNodeP || count > index - 1)
        return ERROR;
    deleteNodeP = currentNodeP->next;
    *elem = deleteNodeP->data;
    currentNodeP->next = deleteNodeP->next;
    free(deleteNodeP);
    return OK;
}

Status ListTraverse(CircularLinkList CLL)
{
    CircularLinkList currentNodeP = CLL;
    CircularLinkList headNodeP = CLL;
    while (currentNodeP->next != headNodeP)
    {
        currentNodeP = currentNodeP->next;
        visit(currentNodeP->data);
    }
    printf("\n");
    return OK;
}

void CreateListHead(CircularLinkList *CLL, int elemNum)
{
    CircularLinkList headNodeP = *CLL;
    CircularLinkList insertNodeP = NULL;
    for (int i = 0; i < elemNum; i++)
    {
        insertNodeP = (CircularLinkList)malloc(sizeof(Node));
        insertNodeP->data = rand() % 100 + 1;
        insertNodeP->next = headNodeP->next;
        headNodeP->next = insertNodeP;
    }
    return;
}

void CreateListTail(CircularLinkList *CLL, int elemNum)
{
    CircularLinkList tailNodeP = *CLL;
    CircularLinkList headNodeP = *CLL;
    CircularLinkList insertNodeP = NULL;
    while (tailNodeP->next != headNodeP)
        tailNodeP = tailNodeP->next; // 循环结束时,tailNodeP就指向尾结点了
    for (int i = 0; i < elemNum; i++)
    {
        insertNodeP = (CircularLinkList)malloc(sizeof(Node));
        insertNodeP->data = rand() % 100 + 1;
        insertNodeP->next = tailNodeP->next;
        tailNodeP->next = insertNodeP;
    }
    return;
}

int main(void)
{
    CircularLinkList CLL;
    printf("Can function InitList() work? %s!\n", InitList(&CLL) ? "Yes" : "No");
    printf("Can function ListInsert() work? %s!\n", ListInsert(&CLL, 1, 25) ? "Yes" : "No");
    CreateListHead(&CLL, 5);
    CreateListTail(&CLL, 5);
    printf("Can function ListTraverse() word? %s!\n", ListTraverse(CLL) ? "Yes" : "No");
    printf("The index of the element 25 is %d.\n", LocateElem(CLL, 25));
    ElemType elem;
    GetElem(CLL, 1, &elem);
    printf("The element of the index 1 is %d.\n", elem);
    printf("Can function ListDelete() work? %s!\n", ListDelete(&CLL, 6, &elem) ? "Yes" : "No");
    printf("The deleted element is %d.\n", elem);
    ListTraverse(CLL);
    return 0;
}