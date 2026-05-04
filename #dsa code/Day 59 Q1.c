#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (arr[i] == val)
            return i;
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* root = newNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd)
        return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return root;
}

void preorder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int *inorder = (int*)malloc(n * sizeof(int));
    int *postorder = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    free(inorder);
    free(postorder);

    return 0;
}
