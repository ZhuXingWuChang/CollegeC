/*
孩子表示法的特点:
    便于查找某个结点的全部孩子(在CTNode构成的链表中)
    便于查找孩子的全部兄弟(在CTNode构成的链表中)
    难以查找双亲(必须遍历)

孩子表示法的改进:
    与双亲表示法结合,修改CTBox(表头)结构,在其中增加一个parent字段,存储双亲的位置(若无,为-1)
*/
#define MAX_TREE_SIZE 100

typedef int TElemType;

// 孩子结点
typedef struct CTNode
{
    int child;
    struct CTNode *next;
} * ChildPtr;

// 表头结构
typedef struct
{
    TElemType data;
    ChildPtr firstchild;
} CTBox;

// 树结构
typedef struct
{
    CTBox nodes[MAX_TREE_SIZE]; // 结点数组
    int root, nodeNum;          // 根的位置和结点数
} CTree;