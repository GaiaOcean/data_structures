#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct No {
	int item;
	struct No *esq;
	struct No *dir;
} No;
typedef No *Arvore;

int count = 0;

//Escreva uma função recursiva para contar o número de nós de uma árvore.
Arvore criarArvore();
Arvore construirArvore(int,Arvore,Arvore);
Arvore construirArvore2(int,Arvore);
int contarNos(Arvore); //devolve a quantidade de nós da árvore
No* buscar(Arvore, int); //devolve a referencia para y ou NULL
int obterAltura( Arvore ); //devolve a altura da árvore
Arvore construirArvoreRam(int n); //constroi arvore perfeitamente balanceada a partir do numero de nos

Arvore criarArvore() { //Questions: why dont I need to use malloc and what if I return a No and declare an Arvore inside
	Arvore b = NULL;
	return b;
}

//Answers: I only need to use malloc if I'm gonna insert an element into that node, in the case of the criarArvore function
//I didnt use the node to store any elements, I just set it to NULL

Arvore construirArvore(int y,Arvore a,Arvore b) { //receives the node element, left subtree and right subtree
	Arvore c = malloc(sizeof(No));
	c -> item = y;
	c -> esq = a;
	c -> dir = b;

	return c;
}
Arvore criarNovoNo(int y) {
	Arvore a = malloc(sizeof(No));
	a -> item = y;
	a -> dir = NULL;
	a -> esq = NULL;
	return a;
}
Arvore construirArvore2(int y,Arvore a) {

	if(a == NULL) {
		a = criarNovoNo(y);
	} else {
		if(count % 2 == 0) {
			a -> esq  = construirArvore2(y, a -> esq);
		} else {
			a -> dir = construirArvore2(y, a -> dir);
		}
	}
	count += 1;

	return a;
}

int contarNos(Arvore b) {
	int quantidade;
	int esquerdo, direito;

	if(b == NULL) {
		quantidade = 0;
	} else {
		esquerdo = contarNos(b->esq);
		direito = contarNos(b->dir);
		quantidade = 1 + direito + esquerdo; //1 is used to count the current node itself
	}
	return quantidade;
}

int contarFolhas(Arvore a) {
	int quantidade;
	int esquerdo, direito;
	if(a == NULL) {
		quantidade = 0;
	} else {
		direito = contarFolhas(a -> dir);
		esquerdo = contarFolhas(a -> esq);
		if(a -> esq == NULL && a -> dir == NULL) {
			quantidade = 1;
		} else {
			quantidade = direito + esquerdo;
		}
	}
	return quantidade;
}
No* buscar(Arvore a, int y) {
	queue q;
	createEmptyQueue(&q);
	No* elemento = NULL;
	bool foundElement = false;

	if(a != NULL) {
		enqueue(&q, a);  // enqueue the root first

		do {
			No* helper = peek(&q);
			dequeue(&q);

			if(helper->item == y) {
				foundElement = true;
				elemento = helper;
			}

			if(helper->esq != NULL) {
				enqueue(&q, helper->esq);
			}
			if(helper->dir != NULL) {
				enqueue(&q, helper->dir);
			}

		} while(!isEmpty(&q) && !foundElement);
	}

	return elemento;
}

int obterAltura(Arvore b) { //devolve a altura da árvore
	int height,left_height, right_height;

	if(b == NULL) {
		height = -1;
	} else {
		left_height = obterAltura(b -> esq);
		right_height = obterAltura(b -> dir);

		if(left_height > right_height) {
			height = 1 + left_height;
		} else {
			height = 1 + right_height;
		}
	}
	return height;
}

Arvore construirArvoreRam(int n){
	Arvore b;
	int left_nodes, right_nodes;
	
	if(n == 0){
		b = NULL;
	}
	
	left_nodes = (n - 1) / 2;       
    right_nodes = n - 1 - left_nodes;
    
    b = criarNovoNo(n - 1);
    b -> esq = construirArvoreRam(left_nodes);
    b -> dir = construirArvoreRam(right_nodes);
	return b;
}
int main() {
	Arvore b = criarArvore();
	b = construirArvore2(50,b);
	b = construirArvore2(10,b);
	b = construirArvore2(2,b);
	b = construirArvore2(15,b);
	b = construirArvore2(8,b);
	int altura = obterAltura(b);
	int quantidade = contarNos(b);
	int leaves = contarFolhas(b);
	printf("quantidade de folhas =  %d\n ", leaves);
	printf("quantidade de nos =  %d\n", quantidade);
	printf("Altura da arvore =  %d\n", altura);
	return 0;
}







