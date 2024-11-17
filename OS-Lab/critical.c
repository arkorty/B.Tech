#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5 // Define the buffer size

// Shared buffer and related variables
int buffer[BUFFER_SIZE];
int in = 0;  // Index for the next producer slot
int out = 0; // Index for the next consumer slot

// Semaphores
sem_t empty; // Semaphore to count empty slots in buffer
sem_t full;  // Semaphore to count full slots in buffer
sem_t mutex; // Mutex for mutual exclusion when accessing buffer

// Producer function
void *producer(void *arg) {
    for (int i = 0; i < 10; ++i) { // Produce 10 items
        int item = rand() % 100;   // Produce a random item

        // Wait for an empty slot
        sem_wait(&empty);

        // Enter critical section (protect buffer access)
        sem_wait(&mutex);

        // Produce an item and place it in the buffer
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        // Exit critical section
        sem_post(&mutex);

        // Signal that there is a new full slot
        sem_post(&full);

        // Sleep to simulate time taken to produce an item
        usleep(rand() % 1000);
    }

    return NULL;
}

// Consumer function
void *consumer(void *arg) {
    for (int i = 0; i < 10; ++i) { // Consume 10 items
        int item;

        // Wait for a full slot
        sem_wait(&full);

        // Enter critical section (protect buffer access)
        sem_wait(&mutex);

        // Consume an item from the buffer
        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        // Exit critical section
        sem_post(&mutex);

        // Signal that there is a new empty slot
        sem_post(&empty);

        // Sleep to simulate time taken to consume an item
        usleep(rand() % 1000);
    }

    return NULL;
}

int main() {
    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE); // All buffer slots are initially empty
    sem_init(&full, 0, 0);            // No items are initially in the buffer
    sem_init(&mutex, 0, 1);           // Mutex is initially available (1)

    // Create threads for producer and consumer
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
