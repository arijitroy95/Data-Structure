#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


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
	return temp;
}


node insert(node head){
	node temp;
	int x;
	printf("Enter Element: ");
	scanf("%d", &x);
	temp = createNode(x);
	if(head != NULL){
		temp->next = head;
	}
	head = temp;
	return head;
}


bool findLoop(node head){
	node slow = head, fast = head;
	bool ans = false;
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			ans = true;
			break;
		}
	}
	return ans;
}


node createLoop(node head){
	node point = head, temp = head;
	int i, rPoint, count = 0;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	temp = head;
	if(count != 0){
		rPoint = rand() % count;
		for(i=0; i<rPoint; i++){
			point = point->next;
		}
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = point;
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
	node head = NULL;
	int op;
	bool detect;
	
	while(1){
		printf("(To insert press - 1)");
		scanf("%d", &op);
		if(op == 1){
			head = insert(head);
		}
		else{
			break;
		}
	}
	printf("Currently the list is \n");
	printList(head);
	detect = findLoop(head);
	if(detect == false){
		printf("There is no loop its a singly link list...\n");
	}
	printf("Making the link list loopy...\n");
	head = createLoop(head);
	detect = findLoop(head);
	if(detect == true){
		printf("There is a loop\n");
	}
	return 0;
}


