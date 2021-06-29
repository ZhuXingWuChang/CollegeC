/*
邻接表：Adjacency List
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void visit(VertexType vertex)
{
    printf("%c ", vertex);
    return;
}

ALGraph CreateALGraph(ALGraph *graph)
{
    int i, j;       // i和j代表顶点的下标
    int weight;     // 边的权值
    EdgeNode *edge; // 存放新分配的结点, 插到链表中
    printf("Input number of Vertexs and Edges:\n");
    scanf("%d%d", &graph->numVexs, &graph->numEdges);
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
        fflush(stdin);
        printf("Input Vertex1 and Vertex2 of Edge, and weight of Edge:\n");
        scanf("%d%d%d", &i, &j, &weight);
        // 使用头插法将EdgeNode链到VertexNode上
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        edge->adjvex = j - 1;
        edge->weight = weight;
        edge->next = graph->adjList[i - 1].firstedge;
        graph->adjList[i - 1].firstedge = edge;
        // 因为是无向图,所以adjList[i]和adjList[j]应该互指
        edge = (EdgeNode *)malloc(sizeof(EdgeNode));
        edge->adjvex = i - 1;
        edge->weight = weight;
        edge->next = graph->adjList[j - 1].firstedge;
        graph->adjList[j - 1].firstedge = edge;
    }
    return *graph;
}

// 标志访问的数组,用来标记该顶点是否已经被访问过
bool visited[MAXVEX];

// 深度优先遍历的操作,供下面的深度优先遍历函数调用
void DFS(ALGraph graph, int i)
{
    // 先设置访问标志为true
    visited[i] = true;
    EdgeNode *edge = graph.adjList[i].firstedge;
    visit(graph.adjList[i].data);
    while (edge)
    {
        if (!visited[edge->adjvex])
            DFS(graph, edge->adjvex);
        edge = edge->next;
    }
    return;
}
// 深度优先遍历,需要调用上面的DFS封装好的操作
void DFSTraverse(ALGraph graph)
{
    int i; // 访问顶点的下标变量
    // 先设置visited数组的标志为false
    for (i = 0; i < graph.numVexs; i++)
        visited[i] = false;
    for (i = 0; i < graph.numVexs; i++)
        if (!visited[i])
            DFS(graph, i);
    return;
}

/* ****************************************************** */
/* 在广度优先遍历中,需使用广度优先队列,来记录"每一层"(也就是广度) */

/* 循环队列的顺序存储结构 */
typedef struct
{
    int data[MAXVEX];
    int front; /* 头指针 */
    int rear;  /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
} Queue;

/* 初始化一个空队列Q */
Queue InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return *Q;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
bool QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear) /* 队列空的标志 */
        return true;
    else
        return false;
}

/* 若队列未满，则插入元素e为Q新的队尾元素 */
void EnQueue(Queue *Q, int e)
{
    if ((Q->rear + 1) % MAXVEX == Q->front) /* 队列满的判断 */
        return;
    Q->data[Q->rear] = e;             /* 将元素e赋值给队尾 */
    Q->rear = (Q->rear + 1) % MAXVEX; /* rear指针向后移一位置， */
                                      /* 若到最后则转到数组头部 */
    return;
}

/* 若队列不空，则删除Q中队头元素，用e返回其值 */
void DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear) /* 队列空的判断 */
        return;
    *e = Q->data[Q->front];             /* 将队头元素赋值给e */
    Q->front = (Q->front + 1) % MAXVEX; /* front指针向后移一位置， */
                                        /* 若到最后则转到数组头部 */
    return;
}
/* ****************************************************** */

// 邻接表的广度优先遍历算法
void BFSTraverse(ALGraph graph)
{
    int i = 0;      // 访问顶点的下标变量
    EdgeNode *edge; // edge指针,在广度有限遍历的实现中使用
    Queue queue;    // 广度优先队列
    queue = InitQueue(&queue);
    for (i = 0; i < graph.numVexs; i++)
        visited[i] = false;
    // 遍历每个顶点,并且进行广度优先遍历
    for (i = 0; i < graph.numVexs; i++)
    {
        if (!visited[i])
        {
            // 顶点的访问操作
            visited[i] = true;
            visit(graph.adjList[i].data);
            EnQueue(&queue, i);
            // 广度优先遍历的具体操作
            while (!QueueEmpty(queue))
            {
                DeQueue(&queue, &i);
                edge = graph.adjList[i].firstedge;
                while (edge)
                {
                    if (!visited[edge->adjvex])
                    {
                        visited[edge->adjvex] = true;
                        visit(graph.adjList[edge->adjvex].data);
                        EnQueue(&queue, edge->adjvex);
                    }
                    edge = edge->next;
                }
            }
        }
    }
    return;
}

void main(void)
{
    ALGraph graph;
    graph = CreateALGraph(&graph);
    printf("Depth First Search:\n");
    DFSTraverse(graph);
    printf("\nBreach First Search:\n");
    BFSTraverse(graph);
    return;
}