#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0

typedef int Status;

typedef char TElemType;
TElemType Nil = '#';

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void visit(TElemType e)
{
    printf("%c ", e);
    return;
}

Status InitBiTree(BiTree *bt)
{
    *bt = NULL;
    return OK;
}

Status DestoryBiTree(BiTree *bt)
{
    if (*bt)
    {
        if ((*bt)->lchild)
            DestoryBiTree(&((*bt)->lchild));
        if ((*bt)->rchild)
            DestoryBiTree(&((*bt)->rchild));
        free(*bt);
        *bt = NULL;
    }
    return OK;
}

Status CreateBiTree(BiTree *bt)
{
    TElemType ch;
    scanf("%c", &ch);
    fflush(stdin);
    if (ch == Nil)
        *bt = NULL;
    else
    {
        *bt = (BiTree)malloc(sizeof(BiTNode));
        if (!*bt)
            return ERROR;
        (*bt)->data = ch;
        CreateBiTree(&((*bt)->lchild));
        CreateBiTree(&((*bt)->rchild));
    }
    return OK;
}

bool BiTreeEmpty(BiTree bt)
{
    if (bt->data)
        return false;
    else
        return true;
}

#define ClearBiTree DestoryBiTree

int BiTreeDepth(BiTree bt)
{
    int leftSubTreeDepth, rightSubTreeDepth;

    if (!bt)
        return 0;

    if (bt->lchild)
        leftSubTreeDepth = BiTreeDepth(bt->lchild);
    else
        leftSubTreeDepth = 0;

    if (bt->rchild)
        rightSubTreeDepth = BiTreeDepth(bt->rchild);
    else
        rightSubTreeDepth = 0;

    return leftSubTreeDepth > rightSubTreeDepth ? leftSubTreeDepth + 1 : rightSubTreeDepth + 1;
}

TElemType Root(BiTree bt)
{
    if (!bt)
        return Nil;
    return bt->data;
}

// 传入一个结点指针,返回某个结点的值
TElemType Value(BiTNode *nodeP)
{
    return nodeP->data;
}

// 传入一个结点指针,给这个结点赋值
void Assign(BiTNode *nodeP, TElemType value)
{
    nodeP->data = value;
}

// 前序遍历算法
void PreOrderTraverse(BiTree bt)
{
    if (bt == NULL)
        return;
    visit(bt->data);
    PreOrderTraverse(bt->lchild);
    PreOrderTraverse(bt->rchild);
    return;
}

// 中序遍历算法
void InOrderTraverse(BiTree bt)
{
    if (bt == NULL)
        return;
    InOrderTraverse(bt->lchild);
    visit(bt->data);
    InOrderTraverse(bt->rchild);
    return;
}

// 后续遍历算法
void PostOrderTraverse(BiTree bt)
{
    if (bt == NULL)
        return;
    PostOrderTraverse(bt->lchild);
    PostOrderTraverse(bt->rchild);
    visit(bt->data);
    return;
}

int main(void)
{
    BiTree mybt;
    InitBiTree(&mybt);
    printf("Input some value for create BiTree:\n");
    CreateBiTree(&mybt);
    printf("Depth: %c\n", BiTreeDepth(mybt));
    printf("Root: %c\n", Root(mybt));

    BiTree nodeP = mybt->lchild;
    printf("The value of 2rd: %c", Value(nodeP));

    nodeP = mybt->lchild;
    Assign(nodeP, 'D');

    printf("\nPre taverse:\n");
    PreOrderTraverse(mybt);

    printf("\nIn traverse:\n");
    InOrderTraverse(mybt);

    printf("\nPost traverse:\n");
    PostOrderTraverse(mybt);

    return 0;
}