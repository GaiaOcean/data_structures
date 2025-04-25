#define MaxPilha 20
#define sinal 0
#define ghost 36
#include <stdbool.h>

typedef struct{
	int topo; //indicates how many items are there in the stack
	int Vetor[MaxPilha];
}PilhaCh;

PilhaCh criarPilha();
bool pilhaVazia(PilhaCh);
PilhaCh pushPilha(PilhaCh,int);
PilhaCh popPilha(PilhaCh);
PilhaCh esvaziarPilha(PilhaCh);
PilhaCh inverterPilha(char[]);
void mostrarPilha(PilhaCh);