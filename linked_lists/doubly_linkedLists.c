//functions: Insert at head/tail, print normally and backwards
typedef struct Celula {
	int elemento;
	struct Celula *prev;
	struct Celula *next;
} Celula;
typedef struct {
	int tamanho;
	Celula * inicio;
	Celula * fim;
} Lista;

void insertAtHead(Lista *l,int x){
	Celula *nova = malloc(sizeof(Celula));
	nova -> elemento = x;
	nova -> prev = NULL;
	nova -> next = l -> inicio;
	
	if( l -> inicio == NULL){
		l -> fim = nova;
	}else{
		l -> inicio -> prev = nova;
	}
	l -> inicio = nova;
	l -> tamanho++;
}


void insertAtTail(Lista *l,int x){
	Celula *nova = malloc(sizeof(Celula));
	nova -> elemento = x;
	nova -> next = NULL;
	nova -> prev = l -> fim;
	
	if(l -> inicio == NULL){
		nova = l -> inicio;
	}else{
		l -> fim -> next = nova;	
	}
	l -> fim = nova;
	l -> tamanho++;	
}

void printList(Lista *l){
	if(l -> inicio != NULL){
		Celula *curr = l -> inicio;
		while(curr != NULL){
			printf("%d", curr -> elemento);
			curr = curr -> next;
		}
	}
	printf("\n");
}

void printListBackwards(Lista *l){
	if(l -> inicio != NULL){
		Celula *curr = l -> fim;
		while(curr != NULL){
			printf("%d", curr -> elemento);
			curr = curr -> prev;
		}
	}
	printf("\n");
}

Lista criarLista(){
	Lista l;
	l.inicio = NULL;
	l.tamanho = 0;
	l.fim = NULL;
	
	return l;
}












