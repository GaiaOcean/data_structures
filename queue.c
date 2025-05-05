#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 5
#define SINAL -1
 
typedef struct{
	int start;
	int end;
	int arr[MAX];
}queue;

void createEmptyQueue(queue*);
bool isEmpty(queue*);
bool isFull(queue*);
void enqueue(queue*,int);
void dequeue(queue*);
void showQueue(queue*);

int main(){
	
	queue q;
	createEmptyQueue(&q);
	enqueue(&q,9);
	enqueue(&q,3);
	enqueue(&q,2);
	dequeue(&q);
	showQueue(&q);
	bool empty = isEmpty(&q);
	
	if(empty){
		printf("EMPTY\n");
	}else{
		printf("NOT EMPTY\n");
	}
	bool full = isFull(&q);
	if(full){
		printf("FULL\n");
	}else{
		printf("NOT FULL\n");
	}
	return 0;
}

void createEmptyQueue(queue* q){
	q -> start = SINAL;
	q -> end  = SINAL;
}


bool isEmpty(queue* q){
	bool empty = false;
	
	if(q -> start == SINAL){
		empty = true;
	}
	
	return  empty;
}



bool isFull(queue* q){
	bool full = false;
	int seq = (q -> end + 1) % MAX;
	
	if(seq == q -> start){
		full = true;
	}
	return full;
}

void enqueue(queue* q, int item){
	int seq = (q -> end + 1) % MAX;
	
	if(!isFull(q)){
		if(isEmpty(q)){
			q -> start = 0;
			q -> end = 0;
		}else{
			q -> end = seq;
		}
		q -> arr[q -> end] = item; 
	}
	
}


void dequeue(queue* q){ //pops the first element out
	
	if(!isEmpty(q)){
		if(q -> start == q -> end){ // theres only one element in the queue
			q -> end = SINAL;
			q -> start = SINAL; 
		}else{
			q -> start = (q -> start + 1) % MAX; 
		}
	}
}

void showQueue(queue* q){
   

    printf("Queue: ");
    int i ;
    for(i = q->start; i <= q -> end; i++ ){
    	printf("%d ",q -> arr[i]);
	}
	printf("\n");
}
