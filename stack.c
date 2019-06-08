#include<stdio.h>
#include<stdlib.h>
#define n 10

int top = -1;

void push(int *stack, int x){
	if(top == n-1){
		printf("Stack is full!!!!!!!!!!!!!!! Invalid Operation... \n");
	}
	else{
		stack[++top] = x;
	}
}


void pop(int *stack){
	if(top == -1){
		printf("Empty Stack!!!!!!!!!! Invalid Operation... \n");
	}
	else{
		int num = stack[top];
		top--;
		printf("Number poped from stack is %d\n", num);
	}
}


void printStack(int *stack){
	int i;
	if(top == -1){
		printf("Empty Stack!!!!!!!!!! Invalid Operation... \n");
	}
	else{
		for(i=0; i<=top; i++){
			printf("%d\t", stack[i]);
		}
		printf("\n");
	}
}


int main(){
	int *stack;
	int op, x;
	stack = (int *) malloc (n * sizeof(int));
	while(1){
		printf("Enter operation code : (push - 1, pop - 2, print - 3)");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Enter number to push: ");
				scanf("%d", &x);
				push(stack, x);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				printStack(stack);
				break;
			default:
				exit(-1);
		}
	}
	return 0;
}
