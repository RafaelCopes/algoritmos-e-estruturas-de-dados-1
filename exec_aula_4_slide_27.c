#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

struct StackNode {
    struct Person person;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* root;
};

struct StackNode* createNode(struct Person person);
struct Stack* createStack();
struct Person createPerson(struct Person* person);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, struct Person person);
void pop(struct Stack* stack);
// void removeByName();
void clear(struct Stack* stack);
void list(struct Stack* stack);

int main() {
    int op = 0;

    struct Stack* stack = createStack();
    
    struct Person person;

    while (op != 6) {

        printf("Choose an option:\n\n");
        printf("1: Add Person\n");
        printf("2: Remove Person from top\n");
        printf("3: Remove Person by name\n");
        printf("4: Clear Stack\n");
        printf("5: List People\n");
        printf("6: Exit\n\n");
        printf("Option: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                createPerson(&person);

                push(stack, person);
            break;
            case 2: 
               pop(stack);
            break; 
            // case 3: 
            //    removeByName();
            // break; 
            case 4: 
               clear(stack);
            break; 
            case 5: 
               list(stack);
            break; 
            case 6: 
                printf("\nBye!\n\n");
                return 0;
            break; 
            default:
                printf("\n\nInvalid Option.\n\n");
            break;
        }
    }

    return 0;
}

int isEmpty(struct Stack* stack) {
    if (stack->root == NULL) {
        return 1;
    }

    return 0;
};

struct StackNode* createNode(struct Person person) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->person = person;
    newNode->next = NULL;

    return newNode;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->root = NULL;

    return stack;
};

void push(struct Stack* stack, struct Person person) {
    struct StackNode* stackNode = createNode(person);
    stackNode->next = stack->root;
    stack->root = stackNode;

    printf("\nThe info from %s was pushed to the stack!\n\n", person.name);
};

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nThe stack is already empty!\n\n");
        return;
    }

    struct StackNode* tmp = stack->root;
    struct Person poped = tmp->person;
    stack->root = stack->root->next;

    free(tmp);

    printf("\n%s was poped from stack!\n\n", poped.name);
};


struct Person createPerson(struct Person* person) {
    printf("Enter the person name: ");
    scanf("%s", person->name);

    printf("Enter the person age: ");
    scanf("%d", &person->age);

    return *person;
};

void list(struct Stack* stack) {
    struct StackNode* tmp = stack->root;
    
    printf("\n");
    while (tmp != NULL) {
        printf("Nome: %s\nIdade: %d\n\n", tmp->person.name, tmp->person.age);
        tmp = tmp->next;
    }
};

void clear(struct Stack* stack) {
    struct StackNode* tmp;
    
    while (stack->root->next != NULL) {
        tmp = stack->root;
        stack->root = stack->root->next;
        free(tmp);
    }

    tmp = stack->root;
    free(tmp);
    stack->root = NULL;
};
