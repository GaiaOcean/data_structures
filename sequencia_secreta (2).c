#include <stdio.h>
#define MaxPilha 500

typedef struct{
	int topo;
	int array[MaxPilha];
}Pilha;

Pilha criarPilha();
void push(Pilha*,int);
int peek(Pilha);
int numeros_da_sequencia(int arr[],int);

int main(){
	//input
    int tamanho_array,numero, qtd_numeros = 0;
    
	scanf("%d",&tamanho_array);
	int array[tamanho_array];
	
	for(int i = 0; i < tamanho_array; i++){
		scanf("%d",&numero);
		array[i] = numero;
	}	
	qtd_numeros = numeros_da_sequencia(array,tamanho_array);
	
	//output do programa
	printf("%d", qtd_numeros);
	
	return 0;
}

Pilha criarPilha(){
	Pilha stack;
	stack.topo = 0;
	
	return stack;
}

void push(Pilha* stack, int item){
	
	if(stack->topo < MaxPilha){
		stack->array[stack->topo] = item;
		stack->topo++;
	}
}

int peek(Pilha stack){
	int topo = -1;
	if(stack.topo > 0){
     	topo = stack.array[stack.topo - 1];
	}	
	return topo;	
}

// Calcula a maior sequência de números sem repetição consecutiva
int numeros_da_sequencia(int array[],int tamanho){
	Pilha stack = criarPilha();
	push(&stack, array[0]);
	int sequencia = 1;
	
	for(int i = 1; i < tamanho; i++){
		if(peek(stack) != array[i]){
			push(&stack,array[i]);
			sequencia++;
		}
	}
	return sequencia;
}
