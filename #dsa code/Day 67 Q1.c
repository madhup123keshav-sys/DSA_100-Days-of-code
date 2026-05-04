#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int stack[MAX];
int top = -1;

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int node) {
    visited[node] = 1;
    struct Node* temp = adj[node];
    while (temp) {
        if (!visited[temp->data])
            dfs(temp->data);
        temp = temp->next;
    }
    stack[++top] = node;
}

int main() {
    int V = 6;

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs(i);

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}
