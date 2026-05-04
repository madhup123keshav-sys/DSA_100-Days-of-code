#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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
        else
            prev->next = temp;

        prev = temp;
    }

    int key;
    scanf("%d", &key);

    int count = 0;
    temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}
