#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
	int item;
	struct Node* next;
}Node;

typedef struct{
	int tam;
	Node* head;
}Lista;

Lista criarLista( ){
		Lista l;
		l.tam = 0;
		l.head = NULL;
		
		return l;
}

void inserirLista(Lista * l, int y){
	Node *newItem;
	newItem = malloc(sizeof(Node));
	newItem -> item = y;
	newItem -> next = l -> head;
	l -> head = newItem;
	l -> tam++;
}
bool listaVazia(Lista* l){
	bool vazia = false;
	if(l -> head == NULL)
		vazia = true;
	return vazia;
}
void removerPrimeiro(Lista * l){
	if(l -> head != NULL){
		Node * temp;
		temp = l -> head;
		l -> head = l -> head -> next;
		l -> tam--;
		free(temp);
	}
}
int obterTamanho(Lista *l){
	int tamanho = l -> tam;
	
	return tamanho;
}
void removerUltimo (Lista *l){ //check if its empty, if there's only 1 items
	if(l -> head != NULL){
		if(l -> head -> next == NULL){
			free(l->head);
			l -> tam--;
		    l -> head = NULL;
		}else{
			Node * temp;
			temp = l -> head;
			
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			free(temp -> next);
			l -> tam--;
			temp -> next = NULL;
		}
	}
	
}
int obterElemento(Lista * l, int k){
	Node* temp;
	temp = l -> head;
	int i = 0;
	int elemento = -1 ;
	
	while(temp != NULL && i < k){
		i++;
		temp = temp -> next;
	}
	
	if(temp != NULL){
		elemento = temp -> item;
	}
	return elemento;
}

Node * buscarItem(Lista * l, int y){
	Node* temp;
	temp = l -> head;
	Node* hasY = NULL;
	
	while(temp != NULL && temp -> item != y){
		temp = temp -> next;
	}
	if(temp != NULL){
		hasY = temp;
	}
	
	return hasY;
}


void destruirLista(Lista* l){
	if(l -> head != NULL){
		Node* temp;
		
		while(l -> head != NULL){
			temp = l -> head;
			l -> head = l -> head -> next;
			free(temp); 
		}
		l -> tam = 0;
	}
}


void mostrarLista(Lista* l){
	Node* temp;
	int element;
	temp = l -> head;
	
	do{	
		element = temp -> item;
		printf("%d ", element);
		temp = temp -> next;
	}while(temp != NULL);
} 

//inverter lista ineficiente
void inverterLista(Lista *l){
	Lista nova = criarLista();
	Lista novaCopy = criarLista();
	Node* temp = l -> head;
	int elemento;
	
	while(temp != NULL){
		elemento = temp -> item;
		inserirLista(&nova,elemento);
		temp = temp -> next;
	}
	while(l -> head != NULL){
		temp = l -> head;
		l -> head = l -> head -> next;
		free(temp); 
	}
	
	temp = nova.head;
	
	while(temp != NULL){
		elemento = temp -> item;
		inserirLista(&novaCopy, elemento);
		temp = temp -> next;
	}
	
	temp = novaCopy.head;
	
	while(temp != NULL){
		elemento = temp -> item;
		inserirLista(l,elemento);
		temp = temp -> next;
	}	
	
}

//ordenar lista

// Insere no início uma célula com o valor y somente se
// esse valor não ocorre na lista.
void buscaInsere ( Lista * l, int y){
	Node* curr = l -> head;
	
	while(curr != NULL && curr -> item != y){
		curr = curr -> next;
	}
	if(curr == NULL){
		inserirLista(l,y);
	}
}


// Remove a primeira ocorrência da célula que contém y
void buscaRemove(Lista * l,int y){
	Node* curr = l -> head;
	Node* prev = NULL;
	
	while(curr != NULL && curr -> item != y){
		prev = curr;
		curr = curr -> next;
	}
	if(curr != NULL){
		if(prev == NULL){
			l -> head = curr -> next;
		}else{
	    	prev -> next = curr -> next;
		}
		free(curr);
	}
	
}
// Troca a posição das duas células. Suponha que as
// referências sejam válidas, diferentes de NULL
//void trocarCelulas ( Lista *, Celula *, Celula *){
//	
//}

// Verifica se a lista está em ordem crescente. Suponha
// que a lista não contenha duplicatas
bool verificarCrescente (Lista l){
	bool crescente = true;
	if(l.head -> item > l.head -> next -> item){
		crescente = false;
	}
	return crescente;
}




int main(){
    Lista l = criarLista();
    inserirLista(&l,10);
    inserirLista(&l,30);
    inserirLista(&l,15);
    inserirLista(&l,12);
    inserirLista(&l,90);
    inserirLista(&l,8);
    Lista nova = criarLista();
    printf("Lista Original\n");
    mostrarLista(&l);
    printf("\n");
    inverterLista(&l);
    printf("Lista Invertida\n");
	mostrarLista(&l);
	printf("\n");
	buscaRemove(&l,30);
	mostrarLista(&l);
	printf("\n");
	buscaInsere(&l,190);
	mostrarLista(&l);
	printf("\n");
	bool crescente = verificarCrescente(l);
	if(crescente){
		printf("Crescente");
	}else{
		printf("Descrescente");
	}
	return 0;
	
}
