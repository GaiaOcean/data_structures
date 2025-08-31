#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5
#define SINAL -1

// Forward declaration of tree node
typedef struct No No;

// Queue structure storing pointers to tree nodes
typedef struct {
    int start;
    int end;
    No* arr[MAX];  // store pointers to nodes
} queue;

// Initialize an empty queue
static inline void createEmptyQueue(queue* q) {
    q->start = SINAL;
    q->end = SINAL;
}

// Check if the queue is empty
static inline bool isEmpty(queue* q) {
    return (q->start == SINAL);
}

// Check if the queue is full
static inline bool isFull(queue* q) {
    int seq = (q->end + 1) % MAX;
    return (seq == q->start);
}

// Enqueue a node pointer
static inline void enqueue(queue* q, No* item) {
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

// Dequeue the first node pointer
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

// Peek the first node pointer
static inline No* peek(queue* q) {
    if(isEmpty(q)) {
        printf("Queue is empty, cannot peek.\n");
        return NULL;
    }
    return q->arr[q->start];
}

//// Show the values of nodes in the queue
//static inline void showQueue(queue* q) {
//    if(isEmpty(q)) {
//        printf("Queue is empty\n");
//        return;
//    }
//
//    printf("Queue: ");
//    int i = q->start;
//    while (true) {
//        printf("%d ", q->arr[i]->item);  // print node value
//        if(i == q->end) break;
//        i = (i + 1) % MAX;
//    }
//    printf("\n");
//}

#endif
