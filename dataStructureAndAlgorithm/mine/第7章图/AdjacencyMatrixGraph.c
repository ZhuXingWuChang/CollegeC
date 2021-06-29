/*
邻接矩阵：Adjacency Matrix
*/
#include <stdio.h>
#include <stdbool.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100
#define INFINITY 65535

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType edge[MAXVEX][MAXVEX];
    int numVexs, numEdges;
} AMGraph;

// 标志访问的数组,用来标记该顶点是否已经被访问过
bool visited[MAXVEX];

void visit(VertexType vertex)
{
    printf("%c ", vertex);
    return;
}

AMGraph CreateAMGraph(AMGraph *graph)
{
    int i, j;   // i和j代表顶点的下标
    int weight; // 边的权值
    printf("Input number of Vertexs and Edges:\n");
    scanf("%d%d", &graph->numVexs, &graph->numEdges);
    // 给各个顶点赋值
    for (int k = 0; k < graph->numVexs; k++)
    {
        printf("Input a value of %dth Vertex:\n", k + 1);
        fflush(stdin);
        scanf("%c", &graph->vexs[k]);
    }
    // 给所有边默认赋值为INFINITY(无权值)
    for (int i = 0; i < graph->numVexs; i++)
        for (int j = 0; j < graph->numVexs; j++)
            graph->edge[i][j] = INFINITY;
    // 指定numEdges条边依附的顶点,以及权值
    for (int k = 0; k < graph->numEdges; k++)
    {
        printf("Input a Edge for connecting Vertex1 and Vertex2, and input weight of the Edge:\n");
        fflush(stdin);
        scanf("%d%d%d", &i, &j, &weight);
        graph->edge[i - 1][j - 1] = weight;
        graph->edge[j - 1][i - 1] = graph->edge[i - 1][j - 1];
    }
    return *graph;
}

// 深度优先遍历的操作,供下面的深度优先遍历函数调用
void DFS(AMGraph graph, int i)
{
    int j;             // j是邻接矩阵中,一行的每一列,遍历一行的所有列,等于遍历一个顶点的所有相邻顶点
    visited[i] = true; // 访问过该顶点,故将其的访问标志改为true
    visit(graph.vexs[i]);
    // 遍历顶点的每一个邻接点,并且找到一个邻接点后,继续递归调用,形成深度优先
    for (j = 0; j < graph.numVexs; j++)
        // 如果这个边存在,且这个边所连接的顶点未被访问过
        if (graph.edge[i][j] != INFINITY && !visited[j])
            DFS(graph, j);
    return;
}
// 深度优先遍历,需要调用上面的DFS封装好的操作
void DFSTraverse(AMGraph graph)
{
    int i; // i既是visited数组的下标,又是邻接矩阵中
    // 先初始化visited数组,所有顶点都是未访问过的状态
    for (i = 0; i < graph.numVexs; i++)
        visited[i] = false;
    // 从第一个顶点开始,对所有的顶点进行深度优先遍历
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

// 邻接矩阵的广度优先遍历算法
void BFSTraverse(AMGraph graph)
{
    int i, j;
    Queue queue; // 广度优先队列,该队列用于存放广度优先遍历中每一层的顶点的下标
    queue = InitQueue(&queue);
    // 先初始化visited数组,所有顶点都是未访问过的状态
    for (i = 0; i < graph.numVexs; i++)
        visited[i] = false;
    // 从第一个顶点开始,对所有的顶点进行广度优先遍历
    for (i = 0; i < graph.numVexs; i++)
    {
        if (!visited[i])
        {
            // 先设置未访问过的顶点标记为已访问过
            visited[i] = true;
            visit(graph.vexs[i]);
            // 将第一个顶点的下标添加到广度优先队列中
            EnQueue(&queue, i);
            // while循环中的操作是: 每出队一个顶点,就将该顶点的所有未访问过的邻接点入队
            while (!QueueEmpty(queue))
            {
                // 删除队头元素,并且把它的"下一层"都加入到队尾
                DeQueue(&queue, &i);
                // 上面只进行了删除,下面就开始向队尾中添加被删除元素的下一层
                // 遍历被出队元素的所有邻接点
                for (j = 0; j < graph.numVexs; j++)
                {
                    // 如果是未访问过的邻接点
                    if (graph.edge[i][j] != INFINITY && !visited[j])
                    {
                        // 先设置未访问过的顶点标记为已访问过
                        visited[j] = true;
                        visit(graph.vexs[j]);
                        // 将找到此顶点入队列
                        EnQueue(&queue, j);
                    }
                }
            }
        }
    }
    return;
}

void main(void)
{
    AMGraph graph;
    graph = CreateAMGraph(&graph);
    printf("Depth First Search:\n");
    DFSTraverse(graph);
    printf("\nBreadth First Search:\n");
    BFSTraverse(graph);
    return;
}