#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include <string.h>

char *reverseString(char str[]);

int main(){
	char str[] = "hello";
	return 0;
}

char *reverseString(char str[]){
	int size = strlen(str);
	Stack *stack = create_stack(size);
	char *reversedWord = (char *)malloc((size + 1) * sizeof(char));
	int j = 0;

	for(int i = 0; i < size; i++){
		push(stack,str[i]);
	}
	while(!is_empty(stack)){
		int item;
		if(pop(stack,&item)){
			reversedWord[j++] = (char)item;
		}
	
	}
	
    reversedWord[j] = '\0';  // Null-terminate the string

    // Clean up
    free(stack->arr);
    free(stack);

    return reversedWord;
	
}