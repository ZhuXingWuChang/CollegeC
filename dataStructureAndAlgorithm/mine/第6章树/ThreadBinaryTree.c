/*
如果所用的二叉树需要经常遍历，或者查找结点的时候需要
某种遍历序列中的前驱和后继，那么采用线索二叉树，能将
整个链表的扫描时间复杂度从复杂的递归，降低到O(n)
*/
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
        if ((*btt)->lchild)
            (*btt)->LTag = Link;
        CreateBiThrTree(&((*btt)->rchild));
        if ((*btt)->rchild)
            (*btt)->RTag = Link;
    }
    return OK;
}

// 全局变量,用来指向上一个访问过的结点(保存前驱结点的位置)
BiThrTree prevP = NULL;
// 用中序遍历进行中序线索化
Status InThreading(BiThrTree currentP)
{
    if (currentP)
    {
        // 在中序遍历中,按照左根右的顺序,找到最左的子树
        InThreading(currentP->lchild);
        // 从最左边的子树开始往回递归,下面是递归过程中对当前左子树根节点的操作
        // 操作该结点,让其线索指到前驱
        if (!currentP->lchild)
        {
            currentP->LTag = Thread;
            currentP->lchild = prevP;
        }
        // 操作该结点的前驱结点,让其线索指到后继
        if (!prevP->rchild)
        {
            prevP->RTag = Thread;
            prevP->rchild = currentP;
        }
        // 该结点操作完毕,现在该结点称为前驱结点,递归
        prevP = currentP;
        // 操作完该子树的根结点,开始递归进入该子树的右子树
        InThreading(currentP->rchild);
    }
}
// 中序遍历二叉树,thrHead指向头结点,btt是二叉树本身
Status InOrderThreading(BiThrTree *thrHead, BiThrTree btt)
{
    *thrHead = (BiThrTree)malloc(sizeof(BiThrNode));
    if (!*thrHead)
        exit(0);
    // 初始化头结点的lchild,它最终要作为Link,指向树的Root
    (*thrHead)->LTag = Link;
    (*thrHead)->lchild = NULL;
    // 初始化头结点的rchild,它最终要作为线索,指向中序遍历中的最后一个元素
    (*thrHead)->RTag = Thread;
    (*thrHead)->rchild = NULL;
    // 如果btt不是空树
    if (btt)
    {
        (*thrHead)->lchild = btt;
        // 在中序化线索前,以头结点为前一个结点,将其传入InThreading()中
        prevP = (*thrHead);
        InThreading(btt);
        // 在中序线索化后,全局变量prevP就成了最后一个结点
        prevP->RTag = Thread;
        // 最后一个结点的rchild指向头结点
        prevP->rchild = (*thrHead);
        // 头结点的rchild指向最后一个结点
        (*thrHead)->rchild = prevP;
    }
    return OK;
}

// 以非递归的形式(降低时间复杂度,这也是线索二叉树的目的所在)
// 来遍历整个二叉树btt
Status InOrderTraverse_Thr(BiThrTree btt)
{
    BiThrTree currentP;
    currentP = btt->lchild;
    // 从根节点开始,遍历结束后会回到头结点(和循环链表一样)
    // 故以头结点作为判断循环是否结束的依据
    while (currentP != btt)
    {
        // 先找到最左的子树
        while (currentP->LTag == Link)
            currentP = currentP->lchild;
        // 循环结束后,currentP指向了最左子树的根结点
        visit(currentP->data);
        // 看最左子树是否有最右子树,如果没有,使用线索回到它的双亲
        while (currentP->RTag == Thread && currentP->rchild != btt)
        {
            currentP = currentP->rchild;
            visit(currentP->data);
        }
        // 剩下最后一种情况就是还剩Link右子树,那么进入
        currentP = currentP->rchild;
    }
    return OK;
}

int main(void)
{
    BiThrTree mybtt, header;
    InitBiThrTree(&mybtt);
    printf("Create a Tree:\n");
    CreateBiThrTree(&mybtt);
    printf("Create end.\n");
    InOrderThreading(&header, mybtt);
    InOrderTraverse_Thr(header);
    return 0;
}