//function implementations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

Stack *create_stack(int capacity){
    if(capacity <= 0) return NULL;
    
    Stack *stack = malloc(sizeof(Stack));  // ? FIXED
    if(stack == NULL) return NULL;
    
    stack->arr = malloc(sizeof(int) * capacity);
    if(stack->arr == NULL){
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}


bool is_full(Stack *stack){
	return stack->capacity = stack->size;
}

bool is_empty(Stack *stack){
	return stack->capacity == 0;
}

bool push(Stack *stack, int item){
	if(is_full(stack)) return false;
	stack-> arr[stack->size] = item;
	stack -> size++;
	
	return true;
}

bool peek(Stack *stack, int *index){
	if(is_empty(stack)) return false;
	
	*index = stack->arr[stack->size - 1];
	
	return true;
}

bool pop(Stack *stack, int *item){
	if(is_empty(stack)) return false;
	stack->size--;
	*item = stack->arr[stack->size];
	
	return true;
}