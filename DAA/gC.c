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
    node->edge=NULL;
}

void addedge(Node* node,int dest,int weight){
    node->edge=(Edge*)realloc( node->edge,sizeof(Edge)*(node->numedges+1));
    node->edge[node->numedges].dest=dest;
    node->edge[node->numedges].weight=weight;
    node->numedges++;
}

void printGraph(Node** graph, int V){
    for (int i = 0; i < V; i++)
    {
        printf("%d:",graph[i]->data);
        for (int j = 0; j < graph[i]->numedges; j++)
        {
            printf("(%d,%d)",graph[i]->edge[j].dest,graph[i]->edge[j].weight);
        }
        printf("\n");
        
    }
    
}

int main()
{

    int V, E;
    int src,dest, weight;
    printf("enter the no. of vertex and edges:");
    scanf("%d %d", &V, &E);
    Node **graph = malloc(V * sizeof(Node *));
    for (int i = 0; i < V; i++){
        graph[i] = (Node *)malloc(sizeof(Node));
         createNode(graph[i],i);
    }


    for (int i = 0; i < E; i++){
        printf("enter the src,dest and weight");
        scanf("%d %d %d",&src, &dest, &weight);
       
        addedge(graph[src],dest,weight);
        //addedge(graph[dest],src,weight);
    }
    printGraph(graph,V);
    return 0;
}
