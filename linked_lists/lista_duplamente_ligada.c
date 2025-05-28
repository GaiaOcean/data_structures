#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ghost 0

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
			printf("%d <->", curr -> elemento);
			curr = curr -> suc;
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

//muito dificil fazer novamente
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
		if(temp == l->inicio  && temp -> elemento >= item){//insere no comeco caso temp seja igual ao inicio
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
void RemovePos(Lista *l, int k){// remove o item de ordem k
	int count = 0;
	if(k < l -> tamanho && k >= 0){
		Celula *curr = l -> inicio;
		while(curr != NULL && count != k){
			curr = curr -> suc;
			count++;
		}
		if(curr == l -> inicio){
			l -> inicio = curr -> suc;
			if(l -> inicio != NULL){
				l -> inicio -> pre = NULL;
			}else{
				l -> fim = NULL; //if  the list has become empty
			}
		}else if(curr == l -> fim){
			l -> fim = curr ->pre;
			if(l -> fim != NULL){ //if the list is not empty
				l -> fim -> suc = NULL;
			}else{
				l -> inicio = NULL;
			}
		}else{
			curr -> pre -> suc = curr -> suc;
			curr -> suc -> pre = curr -> pre;
			
		}
		free(curr);
		l -> tamanho--;
		}
}

int localizarMaior(Lista l){ // devolve a ordem do maior valor existente na lista ou zero
	int i = 1;
	int local = 0;
	
	if(l.inicio -> suc == NULL){ //theres only 1 element in the list
		local = 0;
	}else if(l.inicio != NULL){
		int maior = l.inicio -> elemento;
		Celula *curr = l.inicio -> suc;
		while(curr != NULL){
			if(curr -> elemento > maior){
				maior = curr -> elemento;
				local = i ;
			}
			curr = curr->suc;
			i++;
		}
	}
	return local;

}

int obterMaximo(Lista l){ // devolve o maior valor existente na lista ou ghost
	int maior = ghost;
	if(l.inicio != NULL){
		maior = l.inicio -> elemento;
		if(l.inicio -> suc != NULL){
			Celula *curr = l.inicio -> suc;
			while(curr != NULL){
				if(curr -> elemento > maior){
					maior = curr -> elemento;
				}
				curr = curr -> suc;
			}
		}
	}
	return maior;
}

int main(){
	Lista l = criarLista();
	inserirInicio(&l,93);
	inserirInicio(&l,10);
	inserirInicio(&l,1);
	inserirInicio(&l,132);
	inserirInicio(&l,7);
	inserirInicio(&l,5);
	int local = localizarMaior(l);
	printf("Position do maior elemento: %d\n", local);
	mostrarLista(l);
	int maior = obterMaximo(l);
	printf("maior elemento: %d\n", maior);
	return 0;
}

















