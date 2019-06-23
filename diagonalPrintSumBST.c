#include<stdio.h>
#include<stdlib.h>

int maxSlope = -1;

struct NODE {
	int data;
	int slope;
	struct NODE *left;
	struct NODE *right;
};


typedef struct NODE *node;

struct LinkList {
	node data;
	struct LinkList *next;
};

typedef struct LinkList *llnode;

//	Functions to maintain the linklists and map
llnode createLinkListNode(node x){
	llnode temp = (llnode) malloc (1 * sizeof(struct LinkList));
	temp->data = x;
	temp->next = NULL;
	return temp;
}

llnode insertLinkList(llnode head, node x){
	llnode temp = createLinkListNode(x);
	if(head)
		temp->next = head;
	head = temp;
	return head;
}


void printList(llnode head){
	if(head){
		printf("%d\t", head->data->data);
		printList(head->next);
	}
}


llnode *createEmptyTable(int sizeOfTable){
	int i;
	llnode *table;
	table = (llnode *) malloc (sizeOfTable * sizeof(llnode));
	for(i=0; i<sizeOfTable; i++)
		table[i] = NULL;
	return table;
}


llnode *insertInTable(llnode *table, node x){
	int idx = x->slope;
	llnode head = table[idx];
	table[idx] = insertLinkList(head, x);
	return table;
}


void printTable(llnode *table, int sizeOfTable){
	int i;
	for(i=0; i<sizeOfTable; i++){
		printList(table[i]);
		printf("\n");
	}
}

int sumOfList(llnode head){
	llnode temp = head;
	int ans = 0;
	while(temp){
		ans = ans + temp->data->data;
		temp = temp->next;
	}
	return ans;
}


int *getDiagonalSum(llnode *table, int sizeOfTable){
	int *result = (int *) malloc (sizeOfTable * sizeof(int));
	int i;
	for(i=0; i<sizeOfTable; i++){
		result[i] = sumOfList(table[i]);
	}
	return result;
}

void printArray(int *array, int size){
	int i;
	for(i=0; i<size; i++)
		printf("Sum of diagonal %d :  %d\n", i, array[i]);
}


//	Functions to maintain the BST
node createNode(int x, int s){
	node temp;
	temp = (node) malloc (1 * sizeof(struct NODE));
	temp->data = x;
	temp->slope = s;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


node insert(node root, int x, int s){
	if(root == NULL){
		if(s > maxSlope)
			maxSlope = s;
		return createNode(x, s);
	}
	else{
		if(root->data > x)
			root->left = insert(root->left, x, s + 1);
		else
			root->right = insert(root->right, x, s);
	}
	return root;
}


/*node addSlope(node current, node previous, node root){
	if(current == root)
		current->slope = 0;
	if(current->data < previous->data)
		current->slope = previous->slope + 1;
	else
		current->slope = previous->slope;
	if(current){
		root->left = addSlope(current->left, current, root);
		root->right = addSlope(current->right, current, root);
	}
	return root;
}
*/

void inOrder(node root){
	if(root){
		inOrder(root->left);
		printf("DATA: %d, SLOPE: %d\n", root->data, root->slope);
		inOrder(root->right);
	}
}


llnode *fillTable(llnode *table, node root){
	if(root){
		table = insertInTable(table, root);
		table = fillTable(table, root->left);
		table = fillTable(table, root->right);
	}
	return table;
}


int main(){
	node root = NULL;
	root = insert(root, 5, 0);
	root = insert(root, 3, 0);
	root = insert(root, 1, 0);
	root = insert(root, 4, 0);
	root = insert(root, 7, 0);
	root = insert(root, 6, 0);
	root = insert(root, 8, 0);
	//inOrder(root);
	//addSlope(root, root, root);
	llnode *table = createEmptyTable(maxSlope + 1);
	table = fillTable(table, root);
	printTable(table, maxSlope + 1);
	printf("\n\n");
	printArray(getDiagonalSum(table, maxSlope + 1), maxSlope + 1);
	return 0;
}

