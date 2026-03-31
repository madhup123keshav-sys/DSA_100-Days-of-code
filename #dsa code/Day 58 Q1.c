#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

void buildPost(int preorder[], int inorder[], int inStart, int inEnd, int *preIndex) {
    if (inStart > inEnd)
        return;

    int root = preorder[(*preIndex)++];
    int inIndex = search(inorder, inStart, inEnd, root);

    buildPost(preorder, inorder, inStart, inIndex - 1, preIndex);
    buildPost(preorder, inorder, inIndex + 1, inEnd, preIndex);

    printf("%d ", root);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;
    buildPost(preorder, inorder, 0, n - 1, &preIndex);

    return 0;
}
