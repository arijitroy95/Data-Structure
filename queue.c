#include<stdio.h>
#include<stdlib.h>
#define n 5

int head = 0;
int tail = 0;


void enqueue(int *queue){
	if(head == (tail + 1) % n){
		printf("Queue is full !!!!!!!!! Invalid Operation... \n");
	}
	else{
		printf("Enter element to enqueue: ");
		scanf("%d", &queue[tail]);
		if(tail == n - 1){
			tail = 0;
		}
		else{
			tail++;
		}
		printf("Head ---> %d\t Tail ---> %d\n", head, tail);
	}
}


void dequeue(int *queue){
	if(head == tail){
		printf("Queue is empty !!!!!!!! Invalid Operation... \n");
	}
	else{
		printf("Dequeued element is %d\n", queue[head]);
		if(head == n - 1){
			head = 0;
		}
		else{
			head++;
		}
	}
}


void printQueue(int *queue){
	if(head == tail){
		printf("Queue is empty !!!!!!!! Invalid Operation... \n");
	}
	else{
		int i;
		if(head <= tail){
			for(i=head; i<tail; i++){
				printf("%d\t", queue[i]);
			}
			printf("\n");
		}
		else{
			for(i=head; i<n; i++){
				printf("%d\t", queue[i]);
			}
			for(i=0; i<=tail; i++){
				printf("%d\t", queue[i]);
			}
			printf("\n");
		}
	}
}


int main(){
	int *queue;
	int op, x;
	queue = (int *) malloc (n * sizeof(n));
	while(1){
		printf("Enter Operation Code: (1 - Enqueue, 2 - Dequeue, 3 - print)");
		scanf("%d", &op);
		switch(op){
			case 1:
				enqueue(queue);
				break;
			case 2:
				dequeue(queue);
				break;
			case 3:
				printQueue(queue);
				break;
			default:
				exit(-1);
		}
	}
	return 0;
}


