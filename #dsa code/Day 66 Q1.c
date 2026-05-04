#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int V, int** adj, int* sizes, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < sizes[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, V, adj, sizes, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(int V, int** adj, int* sizes) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, V, adj, sizes, visited, recStack))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 4;

    int** adj = (int**)malloc(V * sizeof(int*));
    int sizes[4] = {1, 1, 2, 0};

    adj[0] = (int*)malloc(1 * sizeof(int));
    adj[0][0] = 1;

    adj[1] = (int*)malloc(1 * sizeof(int));
    adj[1][0] = 2;

    adj[2] = (int*)malloc(2 * sizeof(int));
    adj[2][0] = 0;
    adj[2][1] = 3;

    adj[3] = NULL;

    if (hasCycle(V, adj, sizes))
        printf("YES");
    else
        printf("NO");

    return 0;
}
