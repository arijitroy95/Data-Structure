#include<stdio.h>
#include<stdlib.h>


struct LinkList{
	int key;
	struct LinkList *next;
	struct LinkList *prev;	
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
	printf("Enter element to insert: ");
	scanf("%d", &element);
	node temp = createNode(element);
	if(head != NULL){
		temp->next = head;
		head->prev = temp;
	}
	head = temp;
}


node delete(node head){
	node temp = head;
	int element;
	printf("Enter element to delete: ");
	scanf("%d", &element);
	
	while(temp != NULL && temp->key != element){
		temp = temp->next;
	}
	if(temp){
		if(temp->prev == NULL){
			if(temp->next){
				temp->next->prev = temp->prev;
			}	
			head = head->next;
			free(temp);
		}
		else if(temp->next == NULL){
			temp->prev->next = temp->next;
		}
		else{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
		}
	}
	else{
		printf("%d is not present in current list\n", element);
	}
	return head;
}


void printList(node head){
	node temp = head;
	if(temp){
		while(temp != NULL){
			printf("%d\t", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
	else{
		printf("List is empty..\n");
	}
}


int main(){
	node head = NULL;
	int op;
	while(1){
		printf("Enter operation code: (1 - Insert, 2 - Delete, 3 - Print)");
		scanf("%d", &op);
		switch(op){
			case 1:
				head = insert(head);
				break;
			case 2:
				head = delete(head);
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
