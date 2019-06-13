#include<stdio.h>
#include<stdlib.h>


struct LinkList{
	int key;
	struct LinkList *next;
};

typedef struct LinkList *node;

node createNode(int element){
	node temp;
	temp = (node) malloc (1 * sizeof(struct LinkList));
	temp->key = element;
	temp->next = NULL;
}

node insert(node head){
	int x;
	node temp;
	printf("Enter element: ");
	scanf("%d", &x);
	temp = createNode(x);
	if(head != NULL){
		temp->next = head;
	}
	head = temp;
	return head;
}


node reverse(node head){
	node current_node = head;
	node next_node = NULL, prev_node = NULL;
	while(current_node != NULL){
		next_node = current_node->next;
		current_node->next = prev_node;
		prev_node = current_node;
		current_node = next_node;
	}
	head = prev_node;
	return head;
}


void printList(node head){
	node temp = head;
	if(temp){
		while(temp){
			printf("%d\t", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
	else{
		printf("Empty List\n");
	}
}
int main(){
	int op;
	node head = NULL;
	while(1){
		printf("Enter operation code: (1 - Insert, 2 - Reverse)");
		scanf("%d", &op);
		switch(op){
			case 1:
				head = insert(head);
				printf("Current list is:\n");
				printList(head);
				break;
			case 2:
				head = reverse(head);
				printf("Reversed list is:\n");
				printList(head);
				break;
			default:
				exit(-1);
				
		}
	}	
	return 0;
}
