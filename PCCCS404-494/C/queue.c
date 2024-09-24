#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    int capacity;
    int *array;
};

struct Queue* createQueue(int capacity) {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = malloc(queue->capacity * sizeof(int));
    return queue;
}

void printQueue(struct Queue *queue) {
    if (queue == NULL || queue->array == NULL) {
        printf("Queue not allocated.");
        return;
    }

    for (int i = 0; i < queue->capacity; ++i) {
        printf("%d ", queue->array[i]);
    }
    putchar('\n');
}

void enqueue(struct Queue *queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue *queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int main() {
    struct Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 20);
    enqueue(queue, 20);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);
    printf("Dequeued: %d\n", dequeue(queue));
    free(queue->array);
    free(queue);
    return 0;
}
