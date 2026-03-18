#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* temp = malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct TreeNode* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int queueSize(struct Queue* q) {
    int count = 0;
    struct QueueNode* temp = q->front;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        int size = queueSize(q);

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);
            printf("%d ", node->val);

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        printf("\n");
    }
}
