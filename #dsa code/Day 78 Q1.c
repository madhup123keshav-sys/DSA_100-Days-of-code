#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005

int n, m;

typedef struct {
    int to, weight;
} Edge;

Edge adj[MAX][MAX];
int adjSize[MAX];

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int prim() {
    int parent[MAX];
    int key[MAX];
    int mstSet[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int count = 1; count <= n - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i].to;
            int w = adj[u][i].weight;

            if (mstSet[v] == 0 && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    int total = 0;
    for (int i = 2; i <= n; i++)
        total += key[i];

    return total;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adjSize[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]].to = v;
        adj[u][adjSize[u]].weight = w;
        adjSize[u]++;

        adj[v][adjSize[v]].to = u;
        adj[v][adjSize[v]].weight = w;
        adjSize[v]++;
    }

    printf("%d\n", prim());
    return 0;
}
