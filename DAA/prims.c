#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INT_MAX 2147483647

typedef struct Edge {
    int weight;
    int dest;
} Edge;

typedef struct Node {
    int data;
    int numedges;
    Edge *edge;
} Node;

void createNode(Node *node, int data) {
    node->data = data;
    node->numedges = 0;
    node->edge = NULL;
}

void addedge(Node *node, int dest, int weight) {
    node->edge = realloc(node->edge, sizeof(Edge) * (node->numedges + 1));
    node->edge[node->numedges].dest = dest;
    node->edge[node->numedges].weight = weight;
    node->numedges++;
}

void printGraph(Node **graph, int V) {
    for (int i = 0; i < V; i++) {
        printf("%d:", graph[i]->data);
        for (int j = 0; j < graph[i]->numedges; j++) {
            printf("(%d,%d)", graph[i]->edge[j].dest, graph[i]->edge[j].weight);
        }
        printf("\n");
    }
}

void prims(Node **graph, int V, int E) {
    int mstSet[V];
    int key[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) { // Run the loop for V-1 times
        int u, min = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (mstSet[i] == 0 && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        mstSet[u] = 1;

        for (int i = 0; i < graph[u]->numedges; i++) {
            int v = graph[u]->edge[i].dest;
            int weight = graph[u]->edge[i].weight;
            if (mstSet[v] == 0 && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i]->edge[parent[i]].weight);
}

int main() {
    int V, E;
    int src, dest, weight;
    printf("enter the no. of vertex and edges:");
    scanf("%d %d", &V, &E);
    Node **graph = malloc(V * sizeof(Node *));
    for (int i = 0; i < V; i++) {
        graph[i] = (Node *)malloc(sizeof(Node));
        createNode(graph[i], i);
    }

    for (int i = 0; i < E; i++) {
        printf("enter the src,dest and weight");
        scanf("%d %d %d", &src, &dest, &weight);

        addedge(graph[src], dest, weight);
        addedge(graph[dest], src, weight);
    }
    printGraph(graph, V);
    prims(graph, V, E);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]->edge);
        free(graph[i]);
    }
    free(graph);

    return 0;
}
