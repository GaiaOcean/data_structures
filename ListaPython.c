#include <stdio.h>
#include <stdlib.h>
#define ERRO1 "ACESSO INDEVIDO  "
#define ERRO2 "LISTA VAZIA"
#define ERRO3 "ERRO SINTAXE"
#define SUCESSO "OK"
#define DP ';'
#define Max 101
#include <STRING.h>
 
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
str indexLista(Lista*,unsigned int, int*); 
str acessar(Lista*, int , unsigned int*);
Lista* copyLista(Lista*);


int main() {

	Lista* l = construirLista(9);

	Lista * sublista = newLista();

	str item_retirado;

	printf("Lista:\n");

	mostrarLista(l);

	item_retirado = popLista(l,5);

	if(item_retirado == ERRO1 || item_retirado == ERRO2){
		printf("%s\n",item_retirado);
	}else{
		printf("Lista depois do POP:\n");
		mostrarLista(l);	
	}

	printf("\n");

	str retorno = acessarF(l,sublista,0,-3);	

	mostrarLista(sublista);

	printf("\n");
	
	int pos = 0;
	
    retorno = indexLista(l,13,&pos);
    
	if (retorno == SUCESSO) {
	    printf("Item encontrado na posicao %d\n", pos);
	} else {
	    printf("%s\n", retorno);
	}
	int item = 0;
	
	retorno =  acessar(l, -3, &item);
	
	if (retorno == SUCESSO) {
	    printf("%d\n", item);
	} else {
	    printf("%s\n", retorno);
	}
	return 0;

}
 
str acessarF(Lista* original,Lista*sublista,int p, int q){

	int i;

	str mensagem;

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

	}else{

		mensagem = SUCESSO;

	}

	return mensagem;

}
 
str popLista(Lista* l ,int pos) {

	str msg;
	int i; 

	if(l->tam == 0){
		msg = ERRO2;
	}else if(pos >= l->tam || pos*-1 > l->tam){
		msg = ERRO1;
	}else{
		if(pos < 0){
			pos = l -> tam + pos;
		}
		for(i = pos; i < l->tam-1;i++){

			l -> vetor[i] = l -> vetor[i+1];
		}

		l  -> tam--;
	}

	return msg;
}

 
 
Lista* newLista() {

	Lista* l;

	l= (Lista *)malloc(sizeof(Lista));

    l -> tam = 0;

	return l;
}
 
Lista *construirLista(int n) {
	int i;
	Lista *l;
	l = (Lista*)malloc(sizeof(Lista));	

	l->tam = n;

	for (i=0;i < n;i++){
	    l->vetor[i] = i;
	}
	
	return l;
}
 
void mostrarLista(Lista* l){
	int i;
	
	if (l==NULL||l->tam==0){

		printf("%s\n", ERRO2);

	} else if(l->tam>Max){

		printf("%s\n", ERRO1);

	}

	for (i=0; i<l->tam; i++){

		printf("%u ", l->vetor[i]);

	}

	printf("\n");

}
 
str indexLista(Lista* l, unsigned int item, int* pos){
	str msg;
	int i = 0;
		
	if(l -> tam == 0){
		msg = ERRO2;
	}else{
		while(i < l -> tam && item != l -> vetor[i]){
			i++;
		}	
		if(i < l -> tam ){
		    *pos = i;
			msg = SUCESSO;
		}else{
			msg = ERRO1;
		}
	}
	
	return msg;
}

str acessar(Lista* l, int pos, unsigned int* item){
	str msg;
	
	if(l -> tam == 0){
		msg = ERRO2;
 	}else if(pos >= 0 && pos < l -> tam ){
 		*item = l -> vetor[pos];
 		msg = SUCESSO;
	}else if(pos < 0){
	 	pos = l -> tam + pos;
	 	*item = l -> vetor[pos];
	 	msg = SUCESSO;
	}else{
		msg = ERRO1;
	}
	
	return msg;	
}
Lista* copyLista(Lista* l){

	unsigned int i;

	Lista* copiaLista;

	copiaLista = malloc(sizeof(Lista));

	copiaLista->tam = l->tam;

	if(copiaLista->tam != 0){

		for(i = 0; i < copiaLista->tam; i++){

			copiaLista->vetor[i] = l->vetor[i];

		}

	} else {

		printf("%s",ERRO2);

	}

	return copiaLista;

}
 
