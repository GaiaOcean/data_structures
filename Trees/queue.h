#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5
#define SINAL -1

typedef struct {
    int start;
    int end;
    int arr[MAX];
} queue;

static inline void createEmptyQueue(queue* q) {
    q->start = SINAL;
    q->end = SINAL;
}

static inline bool isEmpty(queue* q) {
    return (q->start == SINAL);
}

static inline bool isFull(queue* q) {
    int seq = (q->end + 1) % MAX;
    return (seq == q->start);
}

static inline void enqueue(queue* q, int item) {
    int seq = (q->end + 1) % MAX;
    if(!isFull(q)) {
        if(isEmpty(q)) {
            q->start = 0;
            q->end = 0;
        } else {
            q->end = seq;
        }
        q->arr[q->end] = item;
    }
}

static inline void dequeue(queue* q) {
    if(!isEmpty(q)) {
        if(q->start == q->end) {
            q->start = SINAL;
            q->end = SINAL;
        } else {
            q->start = (q->start + 1) % MAX;
        }
    }
}

static inline int peek(queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty, cannot peek.\n");
        return SINAL; // or some sentinel value
    }
    return q->arr[q->start];
}

static inline void showQueue(queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    int i = q->start;
    while (true) {
        printf("%d ", q->arr[i]);
        if(i == q->end) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

#endif
