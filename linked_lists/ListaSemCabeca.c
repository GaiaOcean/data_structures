#include <stdio.h>
#include <stdlib.h>
#include <stdBool.h>

typedef struct Celula {
	char item;
	struct Celula * next;
} Celula;
typedef Celula * Lista;

Lista newLista( ){
	Lista nova = NULL; //points to the first element
	return nova;
}

bool ListaVazia(Lista l){
	bool vazia = false;
	if(l == NULL){
		vazia = true;
	}
	return vazia;
}

int obterTamanho(Lista l){
	int tamanho = 0;
	if(l != NULL){
		Celula *curr= l;
		while(curr != NULL){
			tamanho++;
			curr = curr -> next;
		}
	}
	return tamanho;
}

char obterElemento(Lista l, int k){ //get the kth element from the list
	int count = 1;
	Celula *curr = l;
	char elemento = '@';
	if(k >= 1){
	while(curr != NULL && count <= k){
		if(count == k){
			elemento = curr -> item;
		}
		count++;
		curr = curr -> next;
	}
	}
	return elemento;
}

Celula* buscarItem(Lista l, char y){
	Celula *elemento = NULL;
	if(l != NULL){
		Celula *curr = l;
		while(curr != NULL && curr -> item != y){
			curr = curr -> next;
		}
		if(curr != NULL){
			elemento = curr;
		}
	}
	return elemento;
}

Lista inserirLista(Lista l, char y){
	Celula *nova = malloc(sizeof(Celula));
	nova -> item = y;
	nova -> next = l;	
	l = nova;
	
	return l;
 	
}
void mostrarLista(Lista l){
	if(l != NULL){
		Celula *curr = l;
		while(curr != NULL){
			printf("%c -> ",curr -> item);
			curr = curr -> next;
		}
	}
	printf("\n");
}
Lista removerPrimeiro(Lista l){
	if(l != NULL){
		Celula *temp = l;
		l = l -> next;
		free(temp);
	}
	return l;
}
Lista esvaziarLista(Lista l){
	while(l != NULL){
		Celula *temp = l;
		l = l -> next;
		free(temp);
	}
	
	return l;
}

Lista removerUltimo(Lista l){
	if(l != NULL){
		Celula *curr = l;
		Celula *prev = NULL;
		while(curr -> next != NULL){
			prev = curr;
			curr = curr -> next;
		}
		if(prev == NULL){
			l = NULL;
		}else{
			prev -> next = NULL;
		}
		free(curr);
	}
	return l;
}
int main(){
	Lista l = newLista();
	l = inserirLista(l,'A');
	l = inserirLista(l,'B');
	l = inserirLista(l,'C');
	l = inserirLista(l,'D');
	l  = removerUltimo(l);
    mostrarLista(l);
	return 0;
}








