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
    Link,       // 0值代表Link,作为链使用
    Thread      // 1值代表Thread,作为线索使用
} PointerTag;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;