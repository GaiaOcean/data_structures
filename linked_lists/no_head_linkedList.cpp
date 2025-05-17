#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Celula {
	char item;
	struct Celula * next;
} Celula;

typedef Celula * Lista;

#define fantasma '?' 

Lista newLista( ){
	Lista nova = malloc(sizeof(Celula));
	nova -> next = NULL;
	
	return nova;
}

bool ListaVazia(Lista l){
	bool vazia = false;
	
	if(l -> next == NULL){
		vazia = true;
	}
	
	return vazia;
}

int obterTamanho(Lista l){
	int tamanho = 0;
	
	if(l -> next != NULL){
		Celula* curr = l -> next;
		
		while(curr != NULL){
			tamanho++;
			curr = curr -> next;
		}
	}
	return tamanho;
}
char obterElemento(Lista l, int pos){ 
	int tamanho = obterTamanho(l);
	char elemento = fantasma;
	
	if(tamanho > 0){	
		if(pos >= 0 && pos < tamanho){
			Celula *curr = l -> next;
			int contador = 0;
			while(curr != NULL && contador != pos ){
				curr = curr -> next;
				contador++;
			}
			elemento = curr -> item;
		}
	}
	return elemento;
}

Lista inserirLista(Lista l, char elemento){
	Celula *novaCel = malloc(sizeof(Celula));
	novaCel -> item = elemento;
	novaCel -> next = l -> next;
	l -> next = novaCel;
	
	return l;
}

void mostrarLista(Lista l){
	if(l -> next != NULL){
		Celula *curr = l -> next;
		while(curr != NULL){
			printf("%c -> ", curr -> item);
			curr = curr -> next;
		}
		printf("\n");
	}
}

Celula* buscarItem(Lista l, char y){
	Celula *local = l -> next;
	
	while(local != NULL && local -> item != y){
		local = local -> next;
	}
	
	return local;
}
Lista removerPrimeiro(Lista l){
	if(l -> next != NULL){
		Celula *temp = l -> next;
		l -> next = l -> next -> next;
		free(temp);
	}
	return l;
}

Lista removerUltimo(Lista l){
	if(l -> next != NULL){ //se nao estiver vazia
		Celula *curr = l -> next;
		while(curr -> next -> next != NULL){
			curr = curr -> next;
		}
		free(curr -> next);
		curr -> next = NULL;
	}
	return l;
}

Lista esvaziarLista(Lista l){
	l -> next = NULL;
	return l;
}



int main(){
	Lista l = newLista();
	
	char elemento =  obterElemento(l, 9);
	printf("%c\n", elemento);
	
	l = inserirLista(l,'A');
	l = inserirLista(l,'B');
	l = inserirLista(l,'C');
	l = inserirLista(l,'D');
	l = inserirLista(l,'E');
	
	mostrarLista(l);
	elemento =  obterElemento(l, 3);
	printf("%c\n", elemento);
	Celula *item = buscarItem(l,'B');
	l = removerUltimo(l);
	mostrarLista(l);
	int tamanho = obterTamanho(l);
	printf("%d\n ",tamanho);
	l = esvaziarLista(l);
	mostrarLista(l);
	
	bool vazia = ListaVazia(l);
	if(vazia){
		printf("Lista Vazia\n");
	}else{
		printf("Lista Nao Vazia\n");
	}
	return 0;
}