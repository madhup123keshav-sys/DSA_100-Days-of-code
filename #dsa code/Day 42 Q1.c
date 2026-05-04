#include <stdio.h>
#define MAX 100

int queue[MAX], stack[MAX];
int front = -1, rear = -1, top = -1;

// Queue functions
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Stack functions
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    int n, x, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Move queue elements to stack
    while (front <= rear) {
        push(dequeue());
    }

    // Move stack elements back to queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
