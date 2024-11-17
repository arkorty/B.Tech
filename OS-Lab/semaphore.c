#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

// Shared variable
int shared_var = 0;

// Semaphore to ensure proper synchronization
sem_t sem;

// Function for incrementing the shared variable
void *increment(void *arg) {
    for (int i = 0; i < 10; i++) {
        // Wait (decrease) semaphore
        sem_wait(&sem);

        // Critical section
        shared_var++;
        printf("Incremented: shared_var = %d\n", shared_var);

        // Signal (increase) semaphore
        sem_post(&sem);
    }
    return NULL;
}

// Function for decrementing the shared variable
void *decrement(void *arg) {
    for (int i = 0; i < 10; i++) {
        // Wait (decrease) semaphore
        sem_wait(&sem);

        // Critical section
        shared_var--;
        printf("Decremented: shared_var = %d\n", shared_var);

        // Signal (increase) semaphore
        sem_post(&sem);
    }
    return NULL;
}

int main() {
    // Initialize semaphore with a value of 1
    sem_init(&sem, 0, 1);

    // Create thread variables
    pthread_t inc_thread, dec_thread;

    // Create threads
    pthread_create(&inc_thread, NULL, increment, NULL);
    pthread_create(&dec_thread, NULL, decrement, NULL);

    // Wait for threads to finish
    pthread_join(inc_thread, NULL);
    pthread_join(dec_thread, NULL);

    // Destroy semaphore
    sem_destroy(&sem);

    printf("Final value of shared_var = %d\n", shared_var);

    return 0;
}
