#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph_t {
    int V;
    Node** adjList;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adjList = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++) {
        g->adjList[i] = NULL;
    }

    return g;
}

void addEdge(Graph* g, int v, int w) {
    Node* newNode = createNode(w);
    newNode->next = g->adjList[v];
    g->adjList[v] = newNode;
}

void DFS(Graph* g, int s) {
    bool* visited = (bool*)malloc(g->V * sizeof(bool));
    for (int i = 0; i < g->V; i++) {
        visited[i] = false;
    }

    int* stack = (int*)malloc(g->V * sizeof(int));
    int top = -1;

    visited[s] = true;
    stack[++top] = s;

    while (top != -1) {
        s = stack[top--];
        printf("%d ", s);

        Node* current = g->adjList[s];
        while (current != NULL) {
            int adjacent = current->data;
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                stack[++top] = adjacent;
            }
            current = current->next;
        }
    }

    free(visited);
    free(stack);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* g = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int v, w;
        printf("Enter edge (vertex1 vertex2): ");
        scanf("%d %d", &v, &w);
        addEdge(g, v, w);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Following is Depth First Traversal (starting from vertex %d)\n", startVertex);
    DFS(g, startVertex);

    free(g);

    return 0;
}
