#include <stdio.h>
#include <stdBool.h>
#include <stdlib.h>

typedef struct Celula {
	int item;
	struct Celula * next;
} Celula;
typedef struct {
	int tamanho;
	Celula * inicio;
} Lista;

Lista criarLista(){
	Lista l;
	l.tamanho = 0;
	l.inicio = NULL;
	return l;
}

void inserirLista(Lista * ap, int y){ //insere no comeco
	Celula *nova = malloc(sizeof(Celula));
	nova -> item = y;
	
	if(ap -> inicio == NULL){
		nova -> next = NULL;
	}else{
		nova -> next = ap -> inicio;
	}
	ap -> inicio = nova;
	ap -> tamanho++;
}

void inserirOrdenada(Lista *l,int y){
	Celula *nova = malloc(sizeof(Celula));
	nova -> item = y;
	
	if(l -> inicio != NULL){
		Celula *curr = l -> inicio;
		Celula *prev = NULL;
		
		while(curr != NULL && curr -> item < y){
			prev = curr;
			curr = curr -> next;
		}
		nova -> next = curr;
		
		
		if(prev == NULL){ //insert at the beguinning
		   l -> inicio = nova;
		}else{
			prev -> next = nova;
		}
		
	}else{
		nova -> next = NULL;
		l -> inicio = nova;
	}
	l -> tamanho++;
}

void removerPrimeiro(Lista * ap){
	if(ap -> inicio != NULL){
		Celula *temp = ap -> inicio;
		if(temp -> next == NULL){
			ap -> inicio = NULL;
		}else{
			ap -> inicio = temp -> next;
		}	
		free(temp);
		ap -> tamanho--;
	}
}

void removerUltimo (Lista *l){
	if(l -> inicio != NULL){
		Celula *prev = NULL,*curr = l->inicio;
		while(curr -> next != NULL){
			prev = curr;
			curr = curr -> next;
		}
		if(prev == NULL){
			l -> inicio = NULL;
		}else{
			prev -> next = NULL;
		}
		free(curr);
		l -> tamanho--;
	}
}
int obterElemento(Lista *l, int k){// devolve o elemento de ordem k
	int count = 1;
	int elemento = -1;
	
	if(k <= l -> tamanho && k >= 0){
		Celula *curr = l -> inicio;
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

Celula* retornaPonteiro(Lista *l,int y){
	Celula *ponteiro = NULL;
	if(l -> inicio != NULL){
		Celula *curr = l-> inicio;
		
		while(curr != NULL && curr -> item != y){
			curr = curr -> next;
		}
		if(curr != NULL){
			ponteiro = curr;
		}
	}
	return ponteiro;
}
void buscaRemove (Lista *l, int y){// Remove a primeira ocorrência da célula que contém y
	if(l -> inicio != NULL){
		Celula *prev = NULL, *curr = l -> inicio;
		while(curr != NULL && curr -> item != y){
			prev = curr;
			curr = curr -> next;
		}
		if(curr != NULL){
		  	if(prev == NULL){
				l -> inicio = curr -> next;
			}else{
				prev -> next = curr -> next;
			}
			free(curr);
			l -> tamanho--;
		}
	}
}
// Verifica se as duas listas contêm os mesmos
// elementos, não importa a ordem. As listas não contêm
// duplicatas
// Troca a posição das duas células. Suponha que as
// referências sejam válidas, diferentes de NULL
bool verificarIgual (Lista l1, Lista l2){
	bool iguais = true;
	int compare = l1.tamanho;
	int y;
	if(l1.inicio != NULL && l2.inicio != NULL){
		if(l1.tamanho != l2.tamanho){
		iguais = false;
	}else{
		Celula *curr = NULL;
		Celula *temp = l2.inicio;
		int i = 1;
		while(i <= compare && iguais){
			curr = l1.inicio;
			y = temp -> item;
			while(curr != NULL && curr -> item != y){
				curr = curr -> next;
			}
			if(curr == NULL){
				iguais = false;
			}
			i++;
			temp = temp -> next;
		}
		
	}
	}
	
	return iguais;
}

void trocarCelulas (Lista *l, Celula *cel1, Celula *cel2){
	if(l -> inicio != NULL){
		int count = 0;
		Celula *prev1 = NULL, *prev2 = NULL,*prev = NULL, *curr = l -> inicio;
		while(curr != NULL){
			if(curr == cel1){
				prev1 = prev;
				count++;
			}else if(curr == cel2){
				prev2 = prev;
				count++;
			}
			prev = curr;
			curr = curr -> next;
		}

		if(cel1 == l -> inicio){
			l -> inicio = cel2;
		}else if(cel2 == l->inicio) {
			l -> inicio = cel1;
		}
		if(prev1 != NULL){
			prev1 -> next = cel2;
		}
		if (prev2 != NULL) {
            prev2 -> next = cel1;  // Update prev2 to point to cel1
        }
		Celula *temp = cel1->next;
        cel1->next = cel2->next;
        cel2->next = temp;	
	}
}


void mostrarLista(Lista *l){
	if(l -> inicio != NULL){
		Celula *curr = l->inicio;
		while(curr != NULL){
			printf("%d -> ", curr -> item);
			curr = curr -> next;
		}
	}
	printf("\n");
}

Lista inverterLista (Lista l ){// Inverte a ordem dos elementos de uma lista.
	if(l.inicio != NULL){
		Celula *prox = NULL, *prev = NULL, *curr = l.inicio;
		while(curr != NULL){
			prox = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = prox;
		}
		l.inicio = prev;
	}
	return l;
	
}

Lista concatenar2Listas ( Lista *l, Lista *l2){// Constrói uma nova lista com a concatenação das listas na ordem dos parâmetros
	Lista concatenada = criarLista();
	if(l -> inicio != NULL && l2 -> inicio != NULL){
		concatenada.inicio = l -> inicio;
		Celula *curr = l -> inicio;
		while(curr -> next != NULL){
			curr = curr -> next;
		}
		curr -> next = l2 -> inicio;
		concatenada.tamanho = l -> tamanho + l2 -> tamanho;
	}else if(l -> inicio == NULL || l2 -> inicio == NULL){
		if(l -> inicio == NULL){
			concatenada.inicio = l2 -> inicio;
			concatenada.tamanho = l2 -> tamanho;
		}else{
			concatenada.inicio = l -> inicio;
			concatenada.tamanho = l -> tamanho;
		}
	}
	return concatenada;
}
void concatenarListas ( Lista *l1, Lista *l2){// Concatena as duas listas na ordem dos parâmetros e// devolve a segunda lista vazia
	if(l1 -> inicio != NULL && l2->inicio != NULL){
		Celula *curr = l1 -> inicio;
		Celula *prev = NULL;
		while(curr != NULL){
			prev = curr;
			curr = curr -> next;
		}
		prev -> next = l2 -> inicio;
		l1 -> tamanho += l2 -> tamanho;
		l2 -> tamanho = 0;
		l2 -> inicio = NULL;
	}else if(l1->inicio  == NULL && l2 -> inicio != NULL){
		l1 -> inicio = l2 -> inicio;
		l1 -> tamanho = l2 -> tamanho;
		l2 -> tamanho = 0;
		l2 -> inicio = NULL;
	}		
}
// Divide a lista em duas listas, de modo que a segunda
// lista comece no primeiro elemento após a primeira
// ocorrência de y na lista original.
// A lista original deve conter y como último elemento
Lista separarLista ( Lista *l, int y){
	Lista nova = criarLista();
	if(l -> inicio != NULL){
		Celula *curr = l-> inicio;
		int tam = 0;
		while(curr != NULL && curr -> item != y){
			curr = curr -> next;
			tam++;
		}
		if(curr != NULL && curr-> item == y){
			nova.inicio = curr -> next;
			nova.tamanho = l -> tamanho - tam - 1;
			l -> tamanho = tam + 1;
			curr -> next = NULL;
		}
	}
	return nova;
}

int main(){
	Lista l = criarLista();
	Lista l2 = criarLista();
	inserirOrdenada(&l,9);
	inserirLista(&l2,90);
	inserirOrdenada(&l,9);
	inserirLista(&l2,13);
	inserirOrdenada(&l,0);
	inserirLista(&l2,123);
	inserirOrdenada(&l,10);
	inserirLista(&l2,17);
	inserirOrdenada(&l,-12);
	int elemento = obterElemento(&l,6);
	printf("Lista Original 1\n");
	mostrarLista(&l);
	printf("Lista Original 2\n");
	mostrarLista(&l2);
	printf("Lista1 depois de concatenar\n");
	concatenarListas(&l,&l2);
	mostrarLista(&l);
	mostrarLista(&l2);
	printf("Lista1 depois de inverter\n");
	 l = inverterLista(l);
	mostrarLista(&l);
	Lista nova = separarLista(&l, 10 );
	printf("Lista Nova\n");
	mostrarLista(&nova);
	printf("Lista velha\n");
	mostrarLista(&l);
	
//	if(iguais){
//		printf("Listas iguais");
//	}else{
//		printf("Listas diferentes");
//	}
//	printf("%d\n", elemento);
//	Celula *ponteiro = retornaPonteiro(&l,12);
//	Celula *p2 = retornaPonteiro(&l,92);
//	trocarCelulas (&l,ponteiro,p2);
//	mostrarLista(&l);
	return 0;
}















