#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (!head) return newNode;

    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;

    return head;
}

struct Node* deleteKey(struct Node* head, int key) {
    if (!head) return head;

    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    while (curr->next && curr->next->data != key) {
        curr = curr->next;
    }

    if (curr->next) {
        struct Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }

    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n, x, key;
    scanf("%d", &n);

    struct Node* head = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = append(head, x);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    printList(head);

    return 0;
}
