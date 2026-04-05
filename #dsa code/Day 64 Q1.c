#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

int main() {
    int n, s;
    scanf("%d", &n);

    int adj[100][100];
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &adj[i][j]);
        }
        adj[i][m] = -1;
    }

    scanf("%d", &s);

    int visited[100] = {0};

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int i = 0; adj[u][i] != -1; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }

    return 0;
}
