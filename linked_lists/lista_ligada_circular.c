#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Celula{
	int elemento;
	struct Celula* next;
} Celula;
typedef Celula * Lista;

Lista criarLista(){
	Lista l = malloc(sizeof(Celula));
	l -> next = l;
	
	return l;
}

Lista inserir(Lista l, int item){
	Celula *newCell = malloc(sizeof(Celula));
	newCell -> elemento = item;
	
	if(l -> next == l){ //if the list is empty
		newCell -> next = l;
		l -> next = newCell;
	}else{
		newCell -> next = l -> next;
		l -> next = newCell;
	}
	
	return l;
}

bool verificarVazia(Lista l){// devolve TRUE se a lista é vazia, FALSE, caso contrário
	bool vazia = false;
	if(l -> next == l){
		vazia = true;
	}
	return vazia;
}
void mostrarLista(Lista l){
	if(l -> next != l){
		Celula *curr = l -> next;
		do{
			printf("%d -> ", curr -> elemento);
			curr = curr -> next;
		}while(curr != l);
	}else{
		printf("Lista Vazia");
	}
	printf("\n");
	
}

int obterTamanho(Lista l){
	int tamanho = 0;
	
	if(l -> next != l){
		Celula *temp = l -> next;
		
		do{
			tamanho++;
			temp = temp -> next;
		}while(temp != l);
	}
	
	return tamanho;
}

Lista inserirOrdenada(Lista l, int item){
	Celula *nova = malloc(sizeof(Celula));
	nova -> elemento = item;
	bool inseriu = false;
	
	if(l -> next != l){
		Celula *prev = l;
		Celula *curr = l -> next;
		
		do{
			if( curr -> elemento >= item){
				prev -> next = nova;
				nova -> next = curr;
				inseriu = true;
			}
			prev = curr;
			curr = curr -> next;
		}while( curr != l && !inseriu);
		if(!inseriu){
			nova -> next = l;
			prev -> next = nova;	
		}
	}else{
		nova -> next = l;
		l -> next = nova;
	}
	return l;
}
int main(){
	Lista l = criarLista();
	l = inserir(l,3);
	l = inserir(l,12);
	l = inserir(l,92);
	l = inserirOrdenada(l,4);
	l = inserirOrdenada(l,100);
	l = inserirOrdenada(l,99);
	mostrarLista(l);
	int size = obterTamanho(l);
	printf("%d\n", size);
	return 0;
}












