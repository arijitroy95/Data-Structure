#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//#define size 5


int top_stack1 = -1;
int top_stack2 = -1;


void push(int *stack, int stack_num, int x){
	if(stack_num == 1){
		stack[++top_stack1] = x;
	}
	else if(stack_num == 2){
		stack[++top_stack2] = x;
	}
	else{
		printf("Wrong Stack number Passed......\n");
	}
}


int pop(int *stack, int stack_num){
	if(stack_num == 1){
		int x = stack[top_stack1--];
		return x;
	}
	else if(stack_num == 2){
		int x = stack[top_stack2--];
		return x;
	}
	else{
		printf("Worng Stack number passed......\n");
		return INT_MAX;
	}
}


void printStack(int *stack, int stack_num){
	int i;
	if(stack_num == 1){
			for(i=0; i<=top_stack1; i++){
				printf("%d\t", stack[i]);
			}
			printf("\n");
	}
	
	else if(stack_num == 2){
			for(i=top_stack2; i>=0; i--){
				printf("%d\t", stack[i]);
			}
			printf("\n");
	}
	else{
		printf("Wrong Stack number passed.......\n");
	}
}


void enqueue(int *stack1, int *stack2, int size){
	if (top_stack1 == size - 1){
		printf("Queue Full...\n");
	}
	else{
		int x;
		printf("Enter element: ");
		scanf("%d", &x);
		if(top_stack2 == -1){
			push(stack1, 1, x);
		}
		else{
			while(top_stack2!=-1){
				push(stack1, 1, pop(stack2, 2));
			}
			push(stack1, 1, x);
		}
	}
}


void dequeue(int *stack1, int *stack2){
	if(top_stack2 == -1 && top_stack1 == -1){
		printf("Queue Empty!!!!!!! Invalid Operation... \n");
	}
	else{
		if(top_stack1 == -1){
			printf("Popped Element is: %d\n", pop(stack2, 2));
		}
		else{
			while(top_stack1 != -1){
				push(stack2, 2, pop(stack1, 1));
			}
			printf("Popped Element is: %d\n", pop(stack2, 2));
		}
	}
}


void printQueue(int *stack1, int *stack2){
	if(top_stack1 == -1 && top_stack2 == -1){
		printf("No element present in Queue....\n");
	}
	else{
		if(top_stack1 == -1){
			printStack(stack2, 2);
		}
		else{
			printStack(stack1, 1);
		}
	}
}


int main(){
	int n, op;
	int *stack1, *stack2;
	
	printf("Enter size of the Queue: ");
	scanf("%d", &n);
	
	stack1 = (int *) malloc (n * sizeof(int));
	stack2 = (int *) malloc (n * sizeof(int));
	
	while(1){
		printf("Enter Operation Code: (1 - Enqueue, 2 - Dequeue, 3 - Print)");
		scanf("%d", &op);
		switch(op){
			case 1:
				enqueue(stack1, stack2, n);
				break;
			case 2:
				dequeue(stack1, stack2);
				break;
			case 3:
				printQueue(stack1, stack2);
				break;
			default:
				exit(-1);
		}
	}
	return 0;
}
