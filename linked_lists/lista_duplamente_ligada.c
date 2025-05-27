#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Celula {
	int elemento;
	struct Celula *suc;
	struct Celula *pre;
} Celula;
typedef struct {
	int tamanho;
	Celula * inicio;
	Celula * fim;
} Lista;


Lista criarLista(){
	Lista l;
	l.inicio = NULL;
	l.fim = NULL;
	l.tamanho = 0;
	
	return l;
}

void inserirInicio(Lista *l, int item){
		Celula *nova = malloc(sizeof(Celula));
		nova -> elemento = item;
		nova -> suc = l -> inicio;
		nova -> pre = NULL;
		
		if(l -> inicio == NULL){
			l -> fim = nova;
		}else{
			l -> inicio -> pre = nova;
		}
		l -> inicio = nova;
		l -> tamanho++;	
}

bool listaVazia(Lista l){// devolve TRUE se a lista estiver vazia
	bool vazia = false;
	if(l.inicio == NULL){
		vazia = true;
	}
	return vazia;
}
void mostrarLista(Lista l){ // mostra o conteudo da lista a partir do inicio
	if(l.inicio != NULL){
		Celula *curr = l.inicio;
		while(curr != NULL){
			printf("%d", curr -> elemento);
		}
	}
	printf("\n");
}
void mostrarListaFim(Lista l){ // mostra o conteudo da lista a partir do fim
	if(l.inicio != NULL){
		Celula *curr = l.fim;
		while(curr != NULL){
			printf("%d",curr -> elemento);
		}
	}
	printf("\n");
}

//muito dificil fazer noavemnte
//insert at the beguinning, end and middle
void inserir(Lista *l, int item){ // acrescenta o item na posicao correta da Lista(em ordem crescente)
	Celula *nova = malloc(sizeof(Celula));
	nova -> elemento = item;
	
	if(l -> inicio == NULL){//insere no comeco caso a lista seja vazia
		nova ->pre = NULL;
		nova -> suc = NULL;
		l -> inicio = nova;
		l -> fim = nova;
	}else{
		Celula *temp = l -> inicio;
		while(temp != NULL && temp -> elemento < item){
			temp = temp -> suc;
		}
		if(temp == l->inicio  && temp ->inicio -> elemento >= item){//insere no comeco caso temp seja igual ao inicio
			nova -> pre = NULL;
			nova -> suc = l -> inicio;
			l -> inicio -> pre = nova;
			l -> inicio = nova;
		}else if(temp == NULL){//caso seja o ultimo elemento
			l -> fim -> suc = nova;
			nova -> pre = l -> fim;
			nova -> suc = NULL;
			l -> fim = nova;
		}else{ //insere no meio
			nova -> suc = temp;
			nova -> pre = temp -> pre;
			temp -> pre -> suc = nova;
			temp -> pre = nova;
		}
	
	}
	l -> tamanho++;	
}
void RemovePos(Lista *, int);























