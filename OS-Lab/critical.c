#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define N 5 // buffer size
int buf[N]; // shared buffer
int in = 0, out = 0;

sem_t empty, full, mutex;

void *prod(void *_) {
    int item = 1;
    for (int i = 0; i < 10; ++i) {
        sem_wait(&empty); // wait for empty slot
        sem_wait(&mutex); // enter critical section

        buf[in] = item++; // add item to buffer
        printf("P: %d\n", buf[in]);
        in = (in + 1) % N;

        sem_post(&mutex); // exit critical section
        sem_post(&full);  // signal item added

        sleep(1); // wait a bit
    }
    return NULL;
}

void *cons(void *_) {
    for (int i = 0; i < 10; ++i) {
        sem_wait(&full);  // wait for item
        sem_wait(&mutex); // enter critical section

        printf("C: %d\n", buf[out]);
        out = (out + 1) % N;

        sem_post(&mutex); // exit critical section
        sem_post(&empty); // signal slot freed

        sleep(2); // wait a bit
    }
    return NULL;
}

int main(void) {
    // init semaphores
    sem_init(&empty, 0, N); // N empty slots
    sem_init(&full, 0, 0);  // 0 full slots
    sem_init(&mutex, 0, 1); // binary semaphore

    // create threads
    pthread_t p, c;
    pthread_create(&p, NULL, prod, NULL);
    pthread_create(&c, NULL, cons, NULL);
    pthread_join(p, NULL);

    return 0;
}
