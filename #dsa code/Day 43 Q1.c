#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void printInorder(struct Node* root) {
    if (!root) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = newNode(arr[0]);
    if (!root) return 0;

    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (head < tail && i < n) {
        struct Node* curr = queue[head++];

        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[tail++] = curr->left;
            }
            i++;
        }

        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[tail++] = curr->right;
            }
            i++;
        }
    }

    printInorder(root);
    printf("\n");

    free(arr);
    free(queue);
    return 0;
}
