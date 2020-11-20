#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _player { 
	char *name;
    int age;
} Player;

typedef struct _priority_queue {
    Player player;
    int priority;
    struct _priority_queue *next;
} PriorityQueue;

PriorityQueue *head = NULL;

Player* newPlayer(char *text, int age);
PriorityQueue* newNode(Player *player, int priority);
void push(PriorityQueue **head, Player* player, int priority);
void pop(PriorityQueue **head);
void peek(PriorityQueue **head, char *text);
void printPriorityQueue(PriorityQueue **head);
void freePriorityQueue(PriorityQueue **head);

int main() {
    push(&head, newPlayer("Art", 26), 2);
    push(&head, newPlayer("Fallen", 29), 1);
    push(&head, newPlayer("Stanislaw", 23), 10);
    push(&head, newPlayer("Fer", 28), 14);
    push(&head, newPlayer("KSCERATO", 26), 5);

    printPriorityQueue(&head);

    printf("\n");

    pop(&head);
    pop(&head);

    printPriorityQueue(&head);

    freePriorityQueue(&head);

    printPriorityQueue(&head);

    return 0;
}                  

Player* newPlayer(char *text, int age) {
    Player *newPlayer = (Player*)malloc(sizeof(Player));
    newPlayer->name = (char*)malloc(strlen(text) + 1);
    strcpy(newPlayer->name, text);
    newPlayer->age = age;

    return newPlayer;
};

PriorityQueue* newPriorityQueueNode(Player *player, int priority) {
    PriorityQueue* newNode = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    newNode->priority = priority;
    newNode->player = *player;
    newNode->next = NULL;

    return newNode;
};


void push(PriorityQueue **head, Player* player, int priority) {
    PriorityQueue **tracer;
    tracer = head;

    PriorityQueue* node = newPriorityQueueNode(player, priority);
   
    while ((*tracer) && ((*tracer)->priority < priority)) {
        tracer = &(*tracer)->next;
        
    }
    
    node->next = *tracer;
    *tracer = node; 
};

void pop(PriorityQueue **head) {
    PriorityQueue *tmp = *head;

    *head = (*head)->next;
    free(tmp);
};

void printPriorityQueue(PriorityQueue **head) {
    PriorityQueue **tracer;
    tracer = head;

    while (*tracer) {
        printf("Name: %s - Age: %d\n", (*tracer)->player.name, (*tracer)->player.age);
        tracer = &(*tracer)->next;
    }
};

void freePriorityQueue(PriorityQueue **head) {
    PriorityQueue **tracer = head;
    PriorityQueue *tmp = *head;

    while(*tracer) {
        tmp = *tracer;
        tracer = &(*tracer)->next;
        free(tmp);
    }
};
