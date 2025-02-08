#include <stdio.h>
#include <stdlib.h>

/*Node* createNode(int data);
void addEdge(Node* node, int dest, int weight);
void printGraph(Node** graph, int numNodes)
Node** createGraph(int numNodes, int numEdges)

*/

typedef struct Edge
{
    int weight;
    int dest;
} Edge;

typedef struct Node
{
    int data;
    int numedges;
    Edge *edge;
} Node;

void createNode(Node *node, int data)
{
    node->data = data;
    node->numedges = 0;
    node->edge = malloc(sizeof(Edge));
    node->edge = NULL;
}

void addedge(Node *node, int dest, int weight)
{
    node->edge = (Edge *)realloc(node->edge, sizeof(Edge) * (node->numedges + 1));
    node->edge[node->numedges].dest = dest;
    node->edge[node->numedges].weight = weight;
    node->numedges++;
}

void printGraph(Node **graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        printf("%d:", graph[i]->data);
        for (int j = 0; j < graph[i]->numedges; j++)
        {
            printf("(%d,%d)", graph[i]->edge[j].dest, graph[i]->edge[j].weight);
        }
        printf("\n");
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int a[], int b[], int c[], int n) // in this sorting the largest will come first to its pakce then after second largest and then so on..
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
                swap(&c[j], &c[j + 1]);
            }
        }
    }
}
int matchh(int mstSet[], int src, int V)
{
    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == src)
        {
            return 1;
        }
    }
    return 0;
}

void krushkal(Node **graph, int V, int E)
{
    int src[E];
    int dest[E];
    int weight[E];
    for (int i = 0; i < E; i++)
    {
        for (int j = 0; j < graph[i]->numedges; j++)
        {
            weight[i] = graph[i]->edge[j].weight;
            src[i] = graph[i]->data;
            dest[i] = graph[i]->edge[j].dest;
        }
    }

    sort(weight, src, dest, E);

    int mstSet[V];

    int index = 0;
    mstSet[index] = src[0];
    index++;
    mstSet[index] = dest[0];
    index++;
    int mincost = 0;
    int i = 0;
    while (index < V)
    {
        if (matchh(mstSet, src[i], V) == 0 || matchh(mstSet, dest[i], V) == 0)
        {
            mstSet[index] = src[i];
            index++;
            mstSet[index] = dest[i];
            index++;
            mincost += weight[i];
            printf("1%d\n",index);
        }
        i++;
        printf("2%d\n",index);
    }

    printf("3%d\n", mincost);
    for (int i = 0; i < V; i++)
    {
        printf("4%d \t", mstSet[i]);
    }
}

int main()
{

    int V, E;
    int src, dest, weight;
    printf("enter the no. of vertex and edges:");
    scanf("%d %d", &V, &E);
    Node **graph = malloc(V * sizeof(Node *));
    for (int i = 0; i < V; i++)
    {
        graph[i] = (Node *)malloc(sizeof(Node));
        createNode(graph[i], i);
    }

    for (int i = 0; i < E; i++)
    {
        printf("enter the src,dest and weight");
        scanf("%d %d %d", &src, &dest, &weight);

        addedge(graph[src], dest, weight);
        addedge(graph[dest], src, weight);
    }
    printGraph(graph, V);

    krushkal(graph, V, E);
    return 0;
}
