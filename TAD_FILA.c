#include <stdio.h>
#define sinal -1
#include <stdbool.h>
#define fantasma 63
#define MAXFILA 5 /* a fila pode guardar até 10 elementos */
typedef struct{
 int inicio; // inicio indica o local do primeiro da fila
 int fim; // fim indica o local do último da fila
 unsigned char item [MAXFILA]; // o array item guarda os elementos a partir do zero
}Fila;


void criarFilaVazia(Fila*);
unsigned char peek(Fila*);
bool verificarFilaVazia(Fila*);
bool verificarFilaCheia(Fila*);
void push(Fila*, unsigned char);
unsigned char pop(Fila*);
void esvaziarFila(Fila*);
void furaFila(Fila*, unsigned char); //coloca um elemento no início da fila, se possível.
void inverterFila(Fila*); //devolve a fila invertida
void mostrarFila(Fila*);

int main(){
	unsigned int popped;
	Fila f;
	criarFilaVazia(&f);
	push(&f,9); // morreu
	push(&f,15);//morreu
	push(&f,18);//morreu
	push(&f,11);
	push(&f,22);
	popped = pop(&f);
	printf("Item retirado: %d\n",popped);
	push(&f,88);
	push(&f,50);
	popped = pop(&f);
	printf("Item retirado: %d\n",popped);
	popped = pop(&f);
	printf("Item retirado: %d\n",popped);
	push(&f,100);
	push(&f,50);
//	popped = pop(&f);
//	popped = pop(&f);
//	popped = pop(&f);
//	popped = pop(&f);
	
	printf("Inicio da fila %d com o elemento %d\n ", f.inicio, f.item[f.inicio]);
	printf("Fim da fila %d com o elemento %d\n", f.fim, f.item[f.fim]);
	printf("Fila Normal\n");
	mostrarFila(&f);
	printf("Fila Invertida\n");
	inverterFila(&f);
	mostrarFila(&f);
	printf("Inicio da fila %d com o elemento %d\n ", f.inicio, f.item[f.inicio]);
	printf("Fim da fila %d com o elemento %d\n", f.fim, f.item[f.fim]);
	
	return 0;
}

void criarFilaVazia(Fila* queue){
	queue -> inicio = sinal;
	queue -> fim = sinal;
}

unsigned char peek(Fila* queue){
	unsigned char item = fantasma;
	if(queue -> inicio != sinal){
		item = queue -> item[0];
	}
	return item;
}

bool verificarFilaVazia(Fila* queue){
	bool vazia = false;
	if(queue -> inicio == sinal){
		vazia = true;
	}
	
	return vazia;
}

bool verificarFilaCheia(Fila* queue){
	bool cheia = false;
	int next = (queue -> fim + 1)% MAXFILA;
	
	if(next == queue -> inicio){
		cheia = true;
	}
	return cheia;
}
void push(Fila* queue, unsigned char elemento){
	//se é vazia, cheia, updtade inicio e fim
	int next = ( queue -> fim + 1) %  MAXFILA;
	
	if(next != queue -> inicio){ // nao ta cheia
		if(queue -> inicio == sinal){ //pilha vazia
			queue -> inicio = next;
			queue -> fim = next;
		}else{
			queue -> fim = next;
		}
		queue -> item[queue -> fim] = elemento;
		
	}
}

unsigned char pop(Fila* queue){
	//nao pode ser vazia, se tiver apenas 1 elemento arrumar inciio e fim, else aumentar o inicio depois de fazer pop, 
	int next = (queue -> inicio + 1) % MAXFILA;
	unsigned char elemento = fantasma;
	
	if(queue -> inicio != sinal){
		if(queue -> inicio == queue -> fim){ // se tiver apenas 1 elemento
			elemento = queue -> item[queue -> inicio] ;
			queue -> inicio = sinal;
			queue -> fim = sinal;
		}else{
			elemento = queue -> item[queue -> inicio];
			queue -> inicio = next; // aumenta o inicio
		}
	}
	
	return elemento;
}
void esvaziarFila(Fila* queue){
	queue -> inicio = sinal;
	queue -> fim =  sinal;
}

void furaFila(Fila* queue, unsigned char elemento){ // adiciona um novo elento uma posicao antes do inicio 
	int next = (queue -> fim + 1) % MAXFILA;
	int novoInicio = (queue -> inicio - 1 + MAXFILA) % MAXFILA;
	
	if(next != queue -> inicio){ //caso nao estiver cheia
		if(queue -> inicio == sinal){ //se estiver vazia
			queue -> inicio = next;
			queue -> fim = next;
		}else{
			queue -> inicio = novoInicio;
		}	
		queue -> item[queue -> inicio] = elemento;
	}
	
}

//PODE CAIR NA PROVA 
void inverterFila(Fila* queue){ 
	unsigned int temp;
	int start = queue -> inicio;
	int end = queue -> fim;
	int i;
	int j;
	
	if(start != sinal && start != end){ //nao esta vazia e nem possui apenas 1 elemento
		if(start < end){ //array normal -> trocas normais
			j = end;
			i = start;
			while(i < j){
				temp = queue -> item[i];
				queue -> item[i] = queue -> item[j];
				queue -> item[j] = temp;
				j--;
				i++;
			}			
		}else{ //circular array
			i = start;
			j = end;
			while(i < MAXFILA ){
				temp = queue -> item[i];
				queue -> item[i] = queue -> item[j];
				queue -> item[j] = temp;
				j--;
				if(j == -1){ // quando j for -1 quer dizer que a partir daqui o array comeca a ser circular	entao j vai ser o ultimo da lista agora
					j = MAXFILA - 1; 
				}
				i++;
			}
		}
	}
	
}

void mostrarFila(Fila* queue){
	int start = queue -> inicio;
	int end = queue -> fim;
	int nextInicio = (start + 1) % MAXFILA;
	
	if(start != sinal){
		if(start <= end){ //o array nao e circular ou possui apenas um elemento
			for(int i = start; i <= end; i++){
				printf("%d ", queue -> item[i]);
			}
		}else{// fila circular 
			int i = start;
			while(i < MAXFILA){ // vai do inicio ao maxfila(array normal)
				printf("%d ", queue -> item[i]);
				i++;
			}
			for(i = 0; i <= end; i++){ // parte do array circular(index 0 ate o fim)
				printf("%d ", queue -> item[i]);
			}
		}
	}
	printf("\n");
}















