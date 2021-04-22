#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef struct DulNote
{
    ElemType data;
    struct DulNote *prior;
    struct DulNote *next;
} DulNote, *DulLinkList;
typedef int Status;

Status visit(ElemType elem)
{
    printf("%d ", elem);
    return OK;
}

Status InitList(DulLinkList *DLL)
{
    *DLL = (DulLinkList)malloc(sizeof(DulNote));
    if (!(*DLL))
        return ERROR;
    (*DLL)->prior = *DLL;
    (*DLL)->next = *DLL;
    return OK;
}

Status ListEmpty(DulLinkList DLL)
{
    if (DLL->next != DLL)
        return ERROR;
    return OK;
}

Status ClearList(DulLinkList *DLL)
{
    DulLinkList currentNodeP = *DLL;
    while (currentNodeP->next != *DLL)
    {
        currentNodeP = currentNodeP->next;
        if (currentNodeP->prior != *DLL)
            free(currentNodeP->prior);
    }
    return OK;
}

int ListLength(DulLinkList DLL)
{
    DulLinkList currentNodeP = DLL;
    int count = 0;
    while (currentNodeP->next != DLL)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    return count;
}

Status GetElem(DulLinkList DLL, int index, ElemType *elem)
{
    DulLinkList currentNodeP = DLL;
    int count = 0;
    while (currentNodeP->next != DLL && count < index)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    if (currentNodeP == DLL || count > index)
        return ERROR;
    *elem = currentNodeP->data;
    return OK;
}

int LocateElem(DulLinkList DLL, ElemType elem)
{
    DulLinkList currentNodeP = DLL;
    int count = 0;
    while (currentNodeP->next != DLL)
    {
        count++;
        currentNodeP = currentNodeP->next;
        if (currentNodeP->data == elem)
            return count;
    }
    return 0;
}

Status ListInsert(DulLinkList *DLL, int index, ElemType elem)
{
    DulLinkList currentNodeP = *DLL;
    DulLinkList insertNodeP = NULL;
    int count = 0;
    while (currentNodeP->next != *DLL && count < index - 1)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    if (count > index - 1)
        return ERROR;
    insertNodeP = (DulLinkList)malloc(sizeof(DulNote));
    insertNodeP->data = elem;
    insertNodeP->next = currentNodeP->next;
    insertNodeP->prior = currentNodeP;
    currentNodeP->next->prior = insertNodeP;
    currentNodeP->next = insertNodeP;
    return OK;
}

Status ListDelete(DulLinkList *DLL, int index, ElemType *elem)
{
    DulLinkList currentNodeP = *DLL;
    DulLinkList deleteNodeP = NULL;
    int count = 0;
    while (currentNodeP->next != *DLL && count < index - 1)
    {
        count++;
        currentNodeP = currentNodeP->next;
    }
    if (count > index - 1)
        return ERROR;
    deleteNodeP = currentNodeP->next;
    *elem = deleteNodeP->data;
    deleteNodeP->next->prior = deleteNodeP->prior;
    deleteNodeP->prior->next = deleteNodeP->next;
    free(deleteNodeP);
    return OK;
}

Status ListTraverse(DulLinkList DLL)
{
    DulLinkList currentNodeP = DLL;
    while (currentNodeP->next != DLL)
    {
        currentNodeP = currentNodeP->next;
        visit(currentNodeP->data);
    }
    printf("\n");
    return OK;
}

int main(void)
{
    DulLinkList DLL;
    InitList(&DLL);
    ListInsert(&DLL, 1, 10);

    ElemType elem;
    GetElem(DLL, 1, &elem);
    printf("%d\n", elem);

    printf("%d\n", LocateElem(DLL, 10));

    ListDelete(&DLL, 1, &elem);
    visit(elem);
    printf("\n");

    printf("%s\n", ListEmpty(DLL) ? "Yes" : "NO");

    return 0;
}