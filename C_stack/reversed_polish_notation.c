#define MaxPilha 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* str;

typedef struct{
	int topo;
	char array[MaxPilha];
}Pilha;

Pilha criarPilha();
void push(Pilha*,char);
char pop(Pilha*);
char peek(Pilha);
str reversed_polish_notation(str);
int stackVazio(Pilha);

int main(){
    str infix = "A+(B*(C-D^E)^(F+G-H)*I)-J*K/L";
    str postfix = reversed_polish_notation(infix);
    
    printf("Infix: %s\n", infix);
    printf("Postfix: %s;\n", postfix);
    free(postfix);


	return 0;
}

char pop(Pilha* stack){
	char ultimo_elemento;
	
	if(!stackVazio(*stack)){
		ultimo_elemento = stack -> array[stack->topo-1];
		stack->topo--;
	}
	return ultimo_elemento;
}

int stackVazio(Pilha stack){
	int empty = 0;
	
	if(stack.topo == 0){
		empty = 1;
	}
	
	return empty;
}

Pilha criarPilha(){
	Pilha stack;
	stack.topo = 0;
	
	return stack;
}

void push(Pilha* stack, char item){
	
	if(stack->topo != MaxPilha - 1){
		stack->array[stack->topo] = item;
		stack->topo++;
	}
}


char peek(Pilha stack){
	char topo = -1;
	if(stack.topo > 0){
     	topo = stack.array[stack.topo - 1];
	}	
	return topo;	
}

int is_operator(char element){
	int operator;
	
	 switch(element) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':  
            return 1;
        default:
            return 0;
    }
}
int higher_precendece(char element){
	int higher_precedence;
	
	 switch(element) {
        case '^':
        	return 3;
        case '-':
        case '+': 
        	return 1;
        case '*':
        case '/':
        	return 2;
        default:
            return 0;
    }
    return higher_precedence;
}

str reversed_polish_notation(str infix_str){
	Pilha stack = criarPilha();
	int i,k;
	str postfix = malloc(strlen(infix_str));
	
	k = 0;
	for(i = 0; infix_str[i] != '\0'; i++){
		char element = infix_str[i];
		if(element == '('){
			push(&stack,element);
		}else if(element == ')'){
			while(peek(stack) != '('){
				postfix[k++] = pop(&stack);
			}
			pop(&stack);
		}else if(is_operator(element)){
			 while (!stackVazio(stack) && is_operator(peek(stack)) && 
	                   higher_precendece(peek(stack)) >= higher_precendece(element)) {
	                postfix[k++] = pop(&stack);
	            }
	            push(&stack, element);  
		}else{
		   postfix[k++] = element; 
		}
	}

	while(!stackVazio(stack)){
			postfix[k++] = pop(&stack);
	}
	
	postfix[k] = '\0';

	
	return postfix;
}

































