#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue* createQueue(unsigned capacity);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
int front(struct Queue* queue);
int rear(struct Queue* queue);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void printQueue(struct Queue* queue);


int main() {
    struct Queue* queue = createQueue(10);

    enqueue(queue, 4);
    enqueue(queue, 7);

    printQueue(queue);
    
    printf("%d dequeued from queue\n", dequeue(queue));

    enqueue(queue, 10);

    printQueue(queue);
  
    printf("Front item is %d\n", front(queue)); 
    printf("Rear item is %d\n", rear(queue)); 
    

    return 0;
}

int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
};

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));

    return queue;
};

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;

    printf("%d enqueued to queue\n", item); 
};

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;

    return item;
};

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }

    return queue->array[queue->front];
};

int rear(struct Queue* queue) {
    if (isFull(queue)) {
        return -1;
    }

    return queue->array[queue->rear];
};

void printQueue(struct Queue* queue) {
    printf("\n");

    for (int i = queue->front; i < queue->size + 1; i++) {   
        if (queue->array[i]) {
            printf("%d ", queue->array[i]);
        }
    }
    printf("\n\n");
};
