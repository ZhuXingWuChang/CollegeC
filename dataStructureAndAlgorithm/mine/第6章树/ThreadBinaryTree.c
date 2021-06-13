#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define OK 1
#define ERROR 0
#define MAX_TREE_SIZE 100

typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAX_TREE_SIZE];

// level: 结点所在的层
// order: 结点在该层的序号
typedef struct
{
    int level, order;
} Position;

TElemType Nil = 0; // 以0为空值

void visit(TElemType c)
{
    printf("%d ", c);
    return;
}

Status InitBiTree(SqBiTree bt)
{
    for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
        bt[i] = Nil;
    return OK;
}

Status CreateBiTree(SqBiTree bt)
{
    int input = 0;
    int i = 0;
    printf("Input a value of node(0 is Nil, q to quit):\n");
    while (1 == scanf("%d", &input) && i < MAX_TREE_SIZE)
    {
        bt[i] = input;
        if (i != 0 && bt[(i + 1) / 2 - 1] == Nil && bt[i] != Nil)
            return ERROR;
        i++;
    }

    while (i < MAX_TREE_SIZE)
    {
        bt[i] = Nil;
        i++;
    }

    printf("Create end.\n");
    return OK;
}

// 在顺序存储结构中,二者是一样的
#define ClearBiTree InitBiTree

bool BiTreeEmpty(SqBiTree bt)
{
    // 只需要判断根节点
    if (bt[0] == Nil)
        return true;
    else
        return false;
}

// 返回二叉树的深度
int BiTreeDepth(SqBiTree bt)
{
    int lastNode;
    int depth = 0;
    // 用一个for循环找到Tree中最后一个结点的为止
    for (lastNode = MAX_TREE_SIZE - 1; lastNode >= 0; lastNode--)
        if (bt[lastNode] != Nil)
            break;
    // 因为数组是以0开始,所以为了与定义的以1开始一致,这里加一
    lastNode++;
    // 用一个while循环计算Tree的深度
    while (lastNode >= pow(2, depth))
        depth++;

    return depth;
}

// 返回树的根节点的值
TElemType Root(SqBiTree bt)
{
    if (BiTreeEmpty(bt))
        return Nil;
    else
        return bt[0];
}

// 返回给定深度和本层位置的结点
TElemType Value(SqBiTree bt, Position e)
{
    // 按照定义的逻辑计算树的index
    // 因为pow(2, e.level - 1)是指该层的第一个结点,所以在最后要-1
    int index = (int)pow(2, e.level - 1) + e.order - 1;
    // 数组以0开头,与定义相差1,所以再-1
    return bt[index - 1];
}

// 给二叉树bt的e位置赋值value
Status Assign(SqBiTree bt, Position e, TElemType value)
{
    int index = (int)pow(2, e.level - 1) + e.order - 1;
    // 如果输入值为Nil或者该结点的双亲结点为Nil
    if (value != Nil && bt[index / 2 - 1] == Nil)
        return ERROR;
    // 如果输入值为空 且 该节点有非空的子节点
    else if (value == Nil && bt[(index - 1) * 2 + 1] != Nil || bt[(index - 1) * 2 + 2] != Nil)
        return ERROR;
    // 赋值
    bt[index - 1] = value;
    return OK;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的双亲,若无则返回Nil
TElemType Parent(SqBiTree bt, TElemType e)
{
    if (bt[0] == Nil)
        return Nil;
    for (int i = 1; i <= MAX_TREE_SIZE - 1; i++)
        if (bt[i] == e)
            return bt[(i + 1) / 2 - 1];
    return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的左孩子,若无则返回Nil
TElemType LeftChild(SqBiTree bt, TElemType e)
{
    if (bt[0] == Nil)
        return Nil;
    for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (bt[i] == e)
            return bt[(i + 1) / 2 - 1];
    return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的右孩子,若无则返回Nil
TElemType RightChild(SqBiTree bt, TElemType e)
{
    if (bt[0] == Nil)
        return Nil;
    for (int i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (bt[i] == e)
            return bt[(i + 1) / 2];
    return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的左兄弟,若无则返回Nil
TElemType LeftSibling(SqBiTree bt, TElemType e)
{
    if (bt[0] == Nil)
        return Nil;
    for (int i = 1; i <= MAX_TREE_SIZE; i++)
        // i是偶数,那么i-1是奇数,说明i是右孩子
        if (bt[i] == e && !(i % 2))
            return bt[i - 1];
    return Nil;
}

// 二叉树bt存在,e是bt中的某个结点
// 返回e的右兄弟,若无则返回Nil
TElemType RightSibling(SqBiTree bt, TElemType e)
{
    if (bt[0] == Nil)
        return Nil;
    for (int i = 1; i <= MAX_TREE_SIZE - 1; i++)
        // i是奇数,那么i+1是偶数,说明i是左孩子
        if (bt[i] == e && i % 2)
            return bt[i + 1];
    return Nil;
}

// 供PreOrderTraverse调用
void PreTraverse(SqBiTree bt, int i)
{
    visit(bt[i]);
    if (bt[2 * (i + 1) - 1] != Nil)
        PreTraverse(bt, 2 * (i + 1) - 1);
    if (bt[2 * (i + 1)] != Nil)
        PreTraverse(bt, 2 * (i + 1));
    return;
}
// 前序遍历算法
Status PreOrderTraverse(SqBiTree bt)
{
    if (!BiTreeEmpty(bt))
        PreTraverse(bt, 0);
    printf("\n");
    return OK;
}

// 供InOrderTraverse()调用
void InTraverse(SqBiTree bt, int i)
{
    if (bt[2 * (i + 1) - 1] != Nil)
        InTraverse(bt, 2 * (i + 1) - 1);
    visit(bt[i]);
    if (bt[2 * (i + 1)] != Nil)
        InTraverse(bt, 2 * (i + 1));
    return;
}
// 中序遍历算法
Status InOrderTraverse(SqBiTree bt)
{
    if (!BiTreeEmpty(bt))
        InTraverse(bt, 0);
    printf("\n");
    return OK;
}

// 供PostOrderTraverse()调用
void PostTraverse(SqBiTree bt, int i)
{
    if (bt[2 * (i + 1) - 1] != Nil)
        PostTraverse(bt, 2 * (i + 1) - 1);
    if (bt[2 * (i + 1)] != Nil)
        PostTraverse(bt, 2 * (i + 1));
    visit(bt[i]);
    return;
}
// 后序遍历算法
Status PostOrderTraverse(SqBiTree bt)
{
    if (!BiTreeEmpty(bt))
        PostTraverse(bt, 0);
    printf("\n");
    return OK;
}

// 层序遍历算法
void LevelOrderTraverse(SqBiTree bt)
{
    int lastNode;
    for (lastNode = MAX_TREE_SIZE - 1; lastNode >= 0; lastNode--)
        if (bt[lastNode] != Nil)
            break;
    lastNode++;
    for (int i = 0; i < lastNode; i++)
        if (bt[i] != Nil)
            visit(bt[i]);
    printf("\n");
}

// 逐层,按本层序号输出二叉树
void Print(SqBiTree bt)
{
    Position p;
    TElemType e;
    for (int level = 1; level <= BiTreeDepth(bt); level++)
    {
        printf("LEVEL%d: ", level);
        for (int i = 1; i <= pow(2, level - 1); i++)
        {
            p.level = level;
            p.order = i;
            e = Value(bt, p);
            if (e != Nil)
                printf("[%d]:%d ", i, e);
        }
        printf("\n");
    }
}

int main(void)
{
    SqBiTree mybt;
    InitBiTree(mybt);
    CreateBiTree(mybt);

    printf("Level traverse:\n");
    LevelOrderTraverse(mybt);

    printf("Pre traverse:\n");
    PreOrderTraverse(mybt);

    printf("In traverse:\n");
    InOrderTraverse(mybt);

    printf("Post traverse:\n");
    PostOrderTraverse(mybt);

    printf("Depth: %d\n", BiTreeDepth(mybt));

    printf("Print:\n");
    Print(mybt);

    return 0;
}