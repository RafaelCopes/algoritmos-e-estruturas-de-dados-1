#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;    
};

void print(struct Node* n);
void push(struct Node** head, int data);
void insertAfter(struct Node* prevNode, int data);
void append(struct Node** head, int data);
void deleteNodeWith(struct Node** head, int key);
void deleteNodeAt(struct Node** head, int position);
void deleteList(struct Node** head);

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head = NULL;

    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    deleteNodeWith(&head, 8);
    deleteNodeAt(&head, 1);

    printf("The created Linked list is: "); 
    print(head);

    deleteList(&head);

    return 0;
}

void print(struct Node* n) {
    while (n != NULL) {
        printf(" %d", n->data);
        n = n->next;
    }
    printf("\n");
};

void push(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;
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
};

void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node* last = *head;

    newNode->data = data;
    newNode->next = NULL;


    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
};

void deleteNodeWith(struct Node** head, int key) {
    struct Node *temp, *prev;
    temp = *head;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;

    free(temp);
};

void deleteNodeAt(struct Node** head, int position) {
    if (*head == NULL) {
        return;
    }

    struct Node* temp = *head;
    
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    int i = 0;

    while (temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        return;
    }

    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
};

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
};
