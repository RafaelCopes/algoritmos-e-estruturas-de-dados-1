#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* createNode(int data);
int isEmpty(struct StackNode* root);
void push(struct StackNode** root, int data);
int pop(struct StackNode** root);
int peek(struct StackNode* root);

int main() {
    struct StackNode *root = NULL;

    push(&root, 3);
    push(&root, 6);
    push(&root, 78);
    push(&root, 98);
    
    printf("%d is at the top of the stack\n", peek(root));


    printf("%d popped from stack\n", pop(&root)); 

    printf("%d is at the top of the stack\n", peek(root));


    return 0;
}

struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
};

int isEmpty(struct StackNode* root) {
    return !root;
};

void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = createNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack!\n", data);
};

int pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        printf("The stack is already empty!\n");
        return -1;
    }

    struct StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    
    free(temp);

    return popped;
};

int peek(struct StackNode* root) {
    if (isEmpty(root)) {
        printf("The stack is empty!");
        return -1;
    }

    return root->data;
};
