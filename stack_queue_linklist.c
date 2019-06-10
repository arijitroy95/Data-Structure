#include<stdio.h>
#include<stdlib.h>


struct LinkList{
	int key;
	struct LinkList *prev;
	struct LinkList *next;
};

typedef struct LinkList *node;


node createNode(int element){
	node temp;
	temp = (node) malloc (1 * sizeof(struct LinkList));
	temp->key = element;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}


node insert(node head){
	int element;
	printf("Enter element: ");
	scanf("%d", &element);
	node temp;
	temp = createNode(element);
	if (head != NULL){
		temp->next = head;
		head->prev = temp;
	}
	head = temp;
	//free(temp);
	return head;
}


node delete(node head, int op){
	if(head != NULL){
		int x;
		if(op == 1){
			x = head->key;
			printf("Poped element is: %d\n", x);
			head = head->next;
			head->prev = NULL;
		}
		if(op == 2){
			node temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			x = temp->key;
			temp->prev->next = NULL;
			printf("Dequeued element is: %d\n", x);
		}
	}
	else{
		printf("Operation performed at wrong time......\n");
	}
	return head;
}


void printList(node head){
	node temp = head;
	while(temp != NULL){
		printf("%d\t", temp->key);
		temp = temp->next;
	}
	printf("\n");
}


int main(){
	int op_name, op_code;
	node head = NULL;
	node head1;
	printf("%d\n", head1->key);
	exit(-1);
	printf("What you want to implement: (1 - Stack, 2 - Queue)");
	scanf("%d", &op_name);
	while(1){
		if(op_name == 1){
			printf("Enter Operation Code: (1 - Push, 2 - Pop, 3 - Print)");
			scanf("%d", &op_code);
		}
		else if(op_name == 2){
			printf("Enter Operation Code: (1 - Enqueue, 2 - Dequeue, 3 - Print)");
			scanf("%d", &op_code);
		}
		else{
			printf("Wrong Name passed....\n");
			break;
		}
		switch(op_code){
			case 1:
				head = insert(head);
				break;
			case 2:
				head = delete(head, op_name);
				break;
			case 3:
				printList(head);
				break;
			default:
				exit(-1);
		}
	}	
	return 0;
}
