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
	unsigned char item;
	
	while(temp.topo > sinal){
		item = temp.Vetor[temp.topo-1];
		printf("%c",item);
		temp  = popPilha(temp);
	}
	
}

bool isBalanced(char str[]){
	int len = strlen(str);
	PilhaCh stack = criarPilha();
	int i = 0;
	bool balanced = true ;
	
	while(i < len && balanced != false ){
		if(str[i] == '('){
			stack = pushPilha(stack,str[i]);
		}else if(str[i] == ')'){
			if(pilhaVazia(stack)){
				balanced = false;
			}else{
				stack = popPilha(stack);
			}	
		}
		i++;
	}
	
	if(!pilhaVazia(stack)){
		balanced = false;
	}
	
	return balanced;
}

int main(){
	char str[] = "";
	if(!isBalanced(str)){
		printf("PARENTHESIS ERRADO");	
	}else{
		printf("PARENTHESIS CORRETO");	
	}
}






