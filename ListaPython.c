#include <stdio.h>
#include <stdlib.h>
#define ERRO1 "ACESSO INDEVIDO"
#define ERRO2 "LISTA VAZIA"
#define ERRO3 "ERRO SINTAXE"
#define SUCESSO "OK"
#define DP ';'
#define Max 101

typedef char* str;

typedef struct{
	int tam;
	unsigned int vetor[Max];
}Lista;

Lista* newLista();
Lista* construirLista(int);
void mostrarLista(Lista*);
str popLista(Lista*,int);

int main() {
	Lista* l = construirLista(5);
	printf("Lista:\n");
	mostrarLista(l);
	
	str item_retirado = popLista(l,-5);
	if(item_retirado == ERRO1 || item_retirado == ERRO2){
		printf("%s\n",item_retirado);
	}else{	
		printf("%d\n",item_retirado);
	}
	mostrarLista(l);
	return 0;
}
str popLista(Lista* l ,int pos) {
	str item;
	int i;
	
	if(l->tam == 0){
		item = ERRO2;
	}else if(pos >= l->tam || pos*-1 > l->tam){
		item = ERRO1;
	}else{
		if(pos < 0){
			item = l -> vetor[l->tam + pos];
			pos = l -> tam + pos;
		}else{
			item = l -> vetor[pos];
		}
		for(i = pos; i < l->tam-1;i++){
			l -> vetor[i] = l -> vetor[i+1];
		}
		l  -> tam--;
	}
	
	return item;
}

Lista* newLista() {
	Lista* end;
	end = malloc(sizeof(Lista));
		end->tam = 0;
	return end;
}

Lista* construirLista(int n) {
	Lista* end;
	end = malloc(sizeof(Lista));	
	end->tam = n;
	for (int i=0; i<n;i++){
		end->vetor[i]=i;
	}
	return end;
}

void mostrarLista(Lista* l){
	if (l==NULL||l->tam==0){
		printf("%s\n", ERRO2);
	} else if(l->tam>Max){
		printf("%s\n", ERRO1);
	}
	
	for (int i=0; i<l->tam; i++){
		printf("%u ", l->vetor[i]);
	}
	printf("\n");
}


