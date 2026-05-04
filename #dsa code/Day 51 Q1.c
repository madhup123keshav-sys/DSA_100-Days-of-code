#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int findLCA(struct Node* root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root->val;
    }
    return -1;
}

int main() {
    int n, i, x, p, q;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d %d", &p, &q);
    printf("%d", findLCA(root, p, q));
    return 0;
}
