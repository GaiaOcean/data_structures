#include "Pilha.h"
#include <stdbool.h>
#include <String.h>
#include <stdio.h>

PilhaCh criarPilha(){
	PilhaCh stack;
	stack.topo = 0;	
	return stack;
}

bool pilhaVazia(PilhaCh stack){
	bool isEmpty = false;
	
	if(stack.topo == sinal){
		isEmpty = true;
	}
	return isEmpty;
}

PilhaCh pushPilha(PilhaCh stack,unsigned char item){
	if(stack.topo != MaxPilha - 1){
		stack.Vetor[stack.topo] = item;
		stack.topo ++;
	}
	
	return stack;
}

PilhaCh popPilha(PilhaCh stack){
	if(stack.topo != sinal){
		stack.topo --;
	}
	
	return stack;	
}

PilhaCh esvaziarPilha(PilhaCh stack){
	stack.topo = 0;
}

PilhaCh inverterPilha(char str[]){
	PilhaCh invertedStr = criarPilha();
	int len = strlen(str);
	int i = 0;
	
	while(i < len){
		invertedStr = pushPilha(invertedStr,str[i]);
		i++;
	}
	
	return invertedStr;
}

void mostrarPilha(PilhaCh stack){
	for(int i = 0; i < stack.topo; i++){
		printf("%c", stack.Vetor[i]);
	}
	printf("\n");
}

