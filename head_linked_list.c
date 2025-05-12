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




