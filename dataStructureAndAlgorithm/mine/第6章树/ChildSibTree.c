/*
孩子兄弟表示法:
    在该表示法中不需要一维数组,所以CSTree直接定义为头指针,整体全部采用链表结构
*/
#define MAX_TREE_SIZE 100

typedef int TElemType;

// 结点结构
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstchild, *rightsib;
} CSNode, *CSTree;
