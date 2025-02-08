#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int dest;
    int weight;
} Edge;

typedef struct Node {
    int data;
    int numEdges;
    Edge* edges;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->numEdges = 0;
    node->edges = NULL;
    return node;
}

void addEdge(Node* node, int dest, int weight) {
    node->edges = (Edge*)realloc(node->edges, sizeof(Edge) * (node->numEdges + 1));
    node->edges[node->numEdges].dest = dest;
    node->edges[node->numEdges].weight = weight;
    node->numEdges++;
}

Node** createGraph(int numNodes, int numEdges) {
    Node** graph = (Node**)malloc(numNodes * sizeof(Node*));
    for (int i = 0; i < numNodes; i++) {
        graph[i] = createNode(i);
    }
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph[src], dest, weight);
        addEdge(graph[dest], src, weight);
    }
    return graph;
}

void printGraph(Node** graph, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        printf("%d: ", graph[i]->data);
        for (int j = 0; j < graph[i]->numEdges; j++) {
            printf("(%d, %d) ", graph[i]->edges[j].dest, graph[i]->edges[j].weight);
        }
        printf("\n");
    }
}

int main() {
    int numNodes, numEdges;
    scanf("%d %d", &numNodes, &numEdges);
    Node** graph = createGraph(numNodes, numEdges);
    printGraph(graph, numNodes);
    return 0;
}
