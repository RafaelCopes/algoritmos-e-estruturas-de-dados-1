#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct QueueNode* createNode(int data);
struct Queue* createQueue();
void enqueue(struct Queue* queue, int data);
void dequeue(struct Queue* queue);

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 6);
    enqueue(queue, 44);
    enqueue(queue, 69);
    enqueue(queue, 23);
    dequeue(queue);
    dequeue(queue);

    printf("Queue Front: %d\n", queue->front->data);
    printf("Queue Rear: %d\n", queue->rear->data);
    

    return 0;
}

struct QueueNode* createNode(int data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
};

void enqueue(struct Queue* queue, int data) {
    struct QueueNode* queueNode = createNode(data);

    if (queue->rear == NULL) {
        queue->front = queueNode;
        queue->rear = queueNode;
        
        printf("%d was enqueued!\n", data);
        return;
    }

    queue->rear->next = queueNode;
    queue->rear = queueNode;

    printf("%d was enqueued!\n", data);
};

void dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("The queue is already empty!\n");
        return;
    }

    struct QueueNode* front = queue->front;

    int dequeued = front->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    printf("%d was dequeued!\n", dequeued);
    
    free(front);
};