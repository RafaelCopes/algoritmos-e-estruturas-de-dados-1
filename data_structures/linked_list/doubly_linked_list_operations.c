#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void print(struct Node* n);
void push(struct Node** head, int data);
void append(struct Node** head, int data);
void insertAfter(struct Node* prevNode, int data);
void insertBefore(struct Node** head, struct Node* nextNode, int data);
void deleteNode(struct Node** head, struct Node* del);

int main() {    
    struct Node* head = NULL;

    push(&head, 5);
    push(&head, 4);
    append(&head, 6);
    append(&head, 7);
    append(&head, 8);
    insertAfter(head->next, 44);
    insertBefore(&head, head->next->next, 69);

    deleteNode(&head, head->next->next);

    print(head);

    return 0;
}

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
};

void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL"); 
        return; 
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node *last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        (*head) = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
};

void insertBefore(struct Node** head, struct Node* nextNode, int data) {
    if (nextNode == NULL) {
        printf("The given next node cannot be NULL");  
        return;  
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = nextNode->prev;
    nextNode->prev = newNode;
    newNode->next = nextNode;

    if (newNode->prev != NULL) {
        newNode->prev->next = newNode;
    } else {
        *head = newNode;
    }
};

void print(struct Node* n) {
    struct Node* last;

    printf("\nTraversal in forward direction \n");  
    while (n != NULL) {
        printf("%d ", n->data);
        last = n;
        n = n->next;
    }

    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
};

void deleteNode(struct Node** head, struct Node* del) {
    if (*head == NULL && del == NULL) {
        return;
    }

    if (*head == del) {
        *head = del->next;
    }

    if (del->next != NULL) {
        del->next->prev = del->prev; 
    }

    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
};
