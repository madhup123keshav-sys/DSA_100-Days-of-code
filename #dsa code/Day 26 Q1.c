#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *prev = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        temp = createNode(x);

        if (head == NULL)
            head = temp;
        else {
            prev->next = temp;
            temp->prev = prev;
        }

        prev = temp;
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
