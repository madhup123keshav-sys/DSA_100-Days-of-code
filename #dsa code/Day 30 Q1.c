#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coef, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int coef, int exp) {
    struct Node* newNode = createNode(coef, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->exp > 1)
            printf("%dx^%d", temp->coef, temp->exp);
        else if (temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%d", temp->coef);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
}

int main() {
    int n, coef, exp;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insert(&head, coef, exp);
    }
    printPolynomial(head);
    return 0;
}
