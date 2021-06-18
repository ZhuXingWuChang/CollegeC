#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 100
typedef char VertexType;
typedef int EdgeType;

// Edge使用链表结构
typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
} EdgeNode;

// Vertex使用数组结构
typedef struct VertextNode
{
    VertexType data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVexs, numEdges;
} ALGraph;

ALGraph CreateALGraph(ALGraph *graph)
{
    int i, j;       // i和j代表顶点的下标
    int weight;     // 边的权值
    EdgeNode *edge; // 存放新分配的结点, 插到链表中
    printf("Input number of Vertexs and Edges:\n");
    scanf("%d,%d", &graph->numVexs, &graph->numEdges);
    // 给AdjList[]中的各个VertexNode的data域赋初值, 并初始化firstedge域为NULL
    for (int k = 0; k < graph->numVexs; k++)
    {
        fflush(stdin);
        printf("Input a value of %dth Vertex:\n", k + 1);
        scanf("%c", &graph->adjList[k].data);
        graph->adjList[k].firstedge = NULL;
    }
    // 给numEdges条边指定依附的结点, 并赋权值
    for (int k = 0; k < graph->numEdges; k++)
    {
        printf("Input Vertex1 and Vertex2 of Edge, and weight of Edge:\n");
        scanf("%d,%d,%d", &i, &j, &weight);
        // 使用头插法将EdgeNode链到VertexNode上
        edge = (EdgeNode*)malloc(sizeof(EdgeNode));
        edge->adjvex = j;
        edge->weight = weight;
        edge->next = graph->adjList[i].firstedge;
        graph->adjList[i].firstedge = edge;
        // 因为是无向图,所以adjList[i]和adjList[j]应该互指
        edge = (EdgeNode*)malloc(sizeof(EdgeNode));
        edge->adjvex = i;
        edge->weight = weight;
        edge->next = graph->adjList[j].firstedge;
        graph->adjList[j].firstedge = edge;
    }
    return *graph;
}

void main(void)
{
    ALGraph graph;
    CreateALGraph(&graph);
    return;
}