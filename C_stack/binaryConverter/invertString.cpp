#include "Pilha.h"
#include <stdbool.h>
#include <string.h>
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

PilhaCh pushPilha(PilhaCh stack,int item){
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
	return stack;
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
	PilhaCh temp = stack;
    int item;
	
	while(temp.topo > sinal){
		item = temp.Vetor[temp.topo-1];
		printf("%d",item);
		temp  = popPilha(temp);
	}
}

PilhaCh convertToBinary(int decNum){
	PilhaCh binNum = criarPilha();
	
	while(decNum > 0){
		int remainder = decNum % 2;
		binNum = pushPilha(binNum,remainder);
		decNum = decNum / 2;
	}
	
	return binNum;
}

int main(){
	int decNum = 88;
	PilhaCh binaryStack = convertToBinary(decNum);
	mostrarPilha(binaryStack);
	return 0;
}