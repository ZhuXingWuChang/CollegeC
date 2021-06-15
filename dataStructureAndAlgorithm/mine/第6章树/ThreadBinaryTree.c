#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;
typedef enum
{
    Link,  // 0值代表Link,作为链使用
    Thread // 1值代表Thread,作为线索使用
} PointerTag;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

TElemType Nil = '#';

void visit(TElemType e)
{
    printf("%c ", e);
    return;
}

Status InitBiThrTree(BiThrTree *btt)
{
    *btt = NULL;
    return OK;
}

// 按前序遍历算法的顺序来构造一棵树
Status CreateBiThrTree(BiThrTree *btt)
{
    TElemType ch;
    scanf("%c", &ch);
    fflush(stdin);

    if (ch == Nil)
        *btt = NULL;
    else
    {
        *btt = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!*btt)
            exit(0);
        (*btt)->data = ch;
        CreateBiThrTree(&((*btt)->lchild));
        if (!(*btt)->lchild)
            (*btt)->LTag = Link;
        CreateBiThrTree(&((*btt)->rchild));
        if (!(*btt)->rchild)
            (*btt)->RTag = Link;
    }
    return OK;
}

// 全局变量,用来指向上一个访问过的结点(保存前驱结点的位置)
BiThrTree pre = NULL;
// 用中序遍历进行中序线索化
Status InThreading(BiThrTree bt)
{
    
}

int main(void)
{
    BiThrTree mybtt;
    InitBiThrTree(&mybtt);
    printf("Create a Tree:\n");
    CreateBiThrTree(&mybtt);
    return 0;
}