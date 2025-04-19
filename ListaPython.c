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
str acessarF(Lista*,Lista*,int, int);

int main() {
	Lista* l = construirLista(9);
	Lista * sublista = newLista();
	
	str item_retirado;
	
	printf("Lista:\n");
	mostrarLista(l);
	
	item_retirado = popLista(l,-4);
	
	if(item_retirado == ERRO1 || item_retirado == ERRO2){
		printf("%s\n",item_retirado);
	}else{	
		printf("%d\n",item_retirado);
	}

	mostrarLista(l);
	printf("\n");
	str retorno = acessarF(l,sublista,0,80);	
	mostrarLista(sublista);
	return 0;
}

str acessarF(Lista* original,Lista*sublista,int p, int q){
	int i;
	str mensagem = SUCESSO;
	
	if(p < 0 && q < 0){
		if(p < q ){
			p = original->tam + p;
			if(p < 0){
				p = 0;
			}
			q = original->tam + q;
			
			for(i = p; i < q; i++){
					sublista->vetor[sublista->tam] = original->vetor[i];
					sublista -> tam++;
			}
		}
	}else if(p >= 0 && q < 0){
		if(q*-1 < original->tam && p < original->tam){
			q = original->tam + q;
			for(i = p; i < q; i++){
				sublista->vetor[sublista->tam] = original->vetor[i];
			 	sublista -> tam++;
			}
		}
	}else if(p >= 0 && q > 0){
		if(p < q && p < original->tam){	
			if(q > original -> tam){
				q = original -> tam;
			}
			for(i = p; i < q; i++){
				sublista->vetor[sublista->tam] = original->vetor[i];
				sublista-> tam++;
			}
		}
	
	}
	if(sublista->tam == 0){
		mensagem = ERRO2;
	}
	return mensagem;
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


