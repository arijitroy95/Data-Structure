#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int head1 = 0, tail1 = 0;
int head2 = 0, tail2 = 0;
int n;


void enqueue(int *queue, int queue_num, int x){
	if(queue_num == 1){
		queue[tail1] = x;
		if(tail1 == n - 1){
			tail1 = 0;
		}
		else{
			tail1++;
		}
	}
	else if(queue_num == 2){
		queue[tail2] = x;
		if(tail2 == n - 1){
			tail2 = 0;
		}
		else{
			tail2++;
		}
	}
	else{
		printf("Worng Queue number entered...\n");
	}
}


int dequeue(int *queue, int queue_num){
	int x;
	if(queue_num == 1){
		x = queue[head1];
		if(head1 == n - 1){
			head1 = 0;
		}
		else{
			head1++;
		}
	}
	else if(queue_num == 2){
		x = queue[head2];
		if(head2 == n - 1){
			head2 = 0;
		}
		else{
			head2++;
		}
	}
	else{
		x = INT_MAX;
		printf("Wrong Queue number entered...\n");
	}
	return x;
}


void printQueue(int *queue){
	int i;
	if(head1 <= tail1){
		for(i=head1; i<tail1; i++){
			printf("%d\t", queue[i]);
		}
		printf("\n");
	}
	else{
		for(i=head1; i<n; i++){
			printf("%d\t", queue[i]);
		}
		for(i=0; i<=tail1; i++){
			printf("%d\t", queue[i]);
		}
		printf("\n");
	}
}


void push(int *queue1, int *queue2){
	if(head1 == (tail1 + 1) % n){
		printf("Stack Full!!!!!!! Invalid Operation... \n");
	}
	else{
		int x;
		printf("Enter element: ");
		scanf("%d", &x);

		if(head1 == 0 && tail1 == 0){
			enqueue(queue1, 1, x);
		}
		else{
			while(tail2 != head2){
				enqueue(queue1, 1, dequeue(queue2, 2));
			}
			enqueue(queue1, 1, x);
		}
	}
}


void pop(int *queue1, int *queue2){
	if(head1 == 0 && tail1 == 0 && head2 == 0 && tail2 == 0){
		printf("Stack Empty !!!!!!!! Invalid Operation... \n");
	}
	else{
		int x;
		while(head1 != tail1){
			enqueue(queue2, 2, dequeue(queue1, 1));
		}
		x = dequeue(queue2, 2);
		printf("Poped element is: %d\n", x);
	}
}


void printStack(int *queue1, int *queue2){
	if(head1 == 0 && tail1 == 0 && head2 == 0 && tail2 == 0){
		printf("Stack Empty !!!!!!!! Invalid Operation... \n");
	}
	else{
		while(head2 != tail2){
			enqueue(queue1, 1, dequeue(queue2, 2));
		}
		printQueue(queue1);
	}
}


int main(){
	int op;
	int *queue1, *queue2;
	
	printf("Enter size of the Stack: ");
	scanf("%d", &n);
	
	queue1 = (int *) malloc (n * sizeof(int));
	queue2 = (int *) malloc (n * sizeof(int));
	
	while(1){
		printf("Enter Operation Code: (1 - Push, 2 - Pop, 3 - Print)");
		scanf("%d", &op);
		switch(op){
			case 1:
				push(queue1, queue2);
				break;
			case 2:
				pop(queue1, queue2);
				break;
			case 3:
				printStack(queue1, queue2);
				break;
			default:
				exit(-1);
		}
	}
	return 0;
}
