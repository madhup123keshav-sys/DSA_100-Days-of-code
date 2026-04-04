#include <stdio.h>
#include <stdbool.h>

void dfs(int node, int n, int adj[n][n], bool visited[]) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    dfs(s, n, adj, visited);

    return 0;
}
