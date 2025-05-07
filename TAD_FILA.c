#define sinal -1
#include <stdbool.h>
#define fantasma 63
#define MAXFILA 10 /* a fila pode guardar até 10 elementos */
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
Fila inverterFila(Fila*); //devolve a pilha invertida

int main(){
	
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
	int next = (queue -> fim + 1) % MAXFILA;
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

void furaFila(Fila* queue, unsigned char elemento){ // adiciona um novo elento uma posicao antes ao inicio 
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












