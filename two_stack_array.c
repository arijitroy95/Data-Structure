#include<stdio.h>
#include<stdlib.h>


int top_stack1 = -1;
int top_stack2 = -1;


void pushStack1(int *stack1){
	int x;
	printf("Enter element to inert: ");
	scanf("%d", &x);
	stack1[++top_stack1] = x;
}


void popStack1(int *stack1){
	if(top_stack1 == -1){
		printf("No Element in the Array\n");
	}
	else{
		printf("Poped element: %d\n", stack1[top_stack1--]);
	}
}


void pushStack2(int *stack2, int n){
	if(top_stack1 + top_stack2 == n - 2){
		printf("Array Full Overflow...... \n");
	}
	else{
		int x;
		printf("Enter element to inert: ");
		scanf("%d", &x);
		stack2[++top_stack2] = x;
	}
}


void popStack2(int *stack2){
	printf("Poped element: %d\n", stack2[top_stack2--]);
}


void printArray(int *stack1, int *stack2){
	if(top_stack1 == -1){
		printf("No element to print");
	}
	else{
		int i;
		if(top_stack2 == -1){
			for(i=0; i<=top_stack1; i++){
				printf("%d\t", stack1[i]);
			}
			printf("\n");
		}
		else{
			for(i=0; i<=top_stack1; i++){
				printf("%d\t", stack1[i]);
			}
			for(i=0; i<=top_stack2; i++){
				printf("%d\t", stack2[i]);
			}
			printf("\n");
		}
	}
}


int main(){
	int n, stack1_sz, stack2_sz, op;
	int *stack1, *stack2;
	
	printf("Enter size of Array: ");
	scanf("%d", &n);
	
	stack1_sz = n / 2;
	stack2_sz = n - stack1_sz;
	stack1 = (int *) malloc (stack1_sz * sizeof(int));
	stack2 = (int *) malloc (stack2_sz * sizeof(int));
	while(1){
		printf("Enter Operation code (Insert - 1, Delete - 2, Print - 3)\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				if(top_stack1 != stack1_sz){
					pushStack1(stack1);	
				}
				else{
					pushStack2(stack2, n);
				}
				break;
			case 2:
				if(top_stack2 == -1){
					popStack1(stack1);	
				}
				else{
					popStack2(stack2);
				}
				break;
			case 3:
				printArray(stack1, stack2);
				break;
			default:
				exit(-1);
		}
	}
}
