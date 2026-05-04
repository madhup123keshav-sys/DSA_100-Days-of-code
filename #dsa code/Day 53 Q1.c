#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

typedef struct Pair {
    Node* node;
    int hd;
} Pair;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(Node* root) {
    if (!root) return;

    Pair queue[1000];
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};

    int offset = 1000;
    int min = offset, max = offset;

    queue[rear++] = (Pair){root, offset};

    while (front < rear) {
        Pair p = queue[front++];
        Node* node = p.node;
        int hd = p.hd;

        map[hd][count[hd]++] = node->val;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            queue[rear++] = (Pair){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (Pair){node->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}
