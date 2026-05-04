#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (front < rear && i < n) {
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

int isMirror(Node* a, Node* b) {
    if (!a && !b) return 1;
    if (!a || !b) return 0;
    if (a->val != b->val) return 0;
    return isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

int isSymmetric(Node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    if (isSymmetric(root)) printf("YES");
    else printf("NO");

    return 0;
}
