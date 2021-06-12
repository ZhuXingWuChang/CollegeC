/*
双亲表示法的特点:
    容易找到双亲结点
    难以找到孩子结点(必须遍历整个树)
    难以找到兄弟(必须遍历整个树)

双亲表示法的改进:
    可以在结点结构中添加一个"firstChild"(长子)字段,存储该节点的最左边孩子(若没有,为-1)
    可以在结点结构中添加一个"rightSib"(右兄弟)字段,存储在给点右边的兄弟(若没有,为-1)
*/
#define MAX_TREE_SIZE 100

typedef int TElemType;

// 结点结构
typedef struct
{
    TElemType data; // 结点数据
    int parent;     // 双亲位置
} PTNode;

// 树结构
typedef struct
{
    PTNode nodes[MAX_TREE_SIZE]; // 结点数组
    int root, nodeNum;           //  根的位置和结点数
} PTree;
