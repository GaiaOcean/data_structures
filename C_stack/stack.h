#include <stdbool.h>
#ifndef STACK_H
#define STACK_H

typedef struct{
	int *arr;
	int capacity;
	int size;	
}Stack;

Stack *create_stack(int capacity);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
bool push(Stack *stack, int item);
bool peek(Stack *stack, int *index);
bool pop(Stack *stack, int *item);

#endif