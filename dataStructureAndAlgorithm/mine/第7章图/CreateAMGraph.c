#include <stdio.h>

typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535
typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType edge[MAXVEX][MAXVEX];
    int numVexs, numEdges;
} MGraph;

MGraph CreateAMGraph(MGraph *graph)
{
    int i, j;   // i和j代表顶点的下标
    int weight; // 边的权值
    printf("Input number of Vertexs and Edges:\n");
    scanf("%d%d", &graph->numVexs, &graph->numEdges);
    // 给各个顶点赋值
    for (int k = 0; k < graph->numVexs; k++)
    {
        fflush(stdin);
        printf("Input a value of %dth Vertex:\n", k + 1);
        scanf("%c", &graph->vexs[k]);
    }
    // 给所有边默认赋值为INFINITY(无权值)
    for (int i = 0; i < graph->numVexs; i++)
        for (int j = 0; j < graph->numVexs; j++)
            graph->edge[i][j] = INFINITY;
    // 指定numEdges条边依附的顶点,以及权值
    for (int k = 0; k < graph->numEdges; k++)
    {
        printf("Input Vertex1 and Vertex2 of Edge, and input weight of Edge:\n");
        scanf("%d%d%d", &i, &j, &weight);
        graph->edge[i - 1][j - 1] = weight;
        graph->edge[j - 1][i - 1] = graph->edge[i - 1][j - 1];
    }
    return *graph;
}

void main(void)
{
    MGraph graph;
    CreateAMGraph(&graph);
    return;
}