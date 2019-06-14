#include<stdio.h>
#include<stdlib.h>


struct BSTNode{
	int key;
	struct BSTNode *left;
	struct BSTNode *right;
};

typedef struct BSTNode *node;

node createNode(int element){
	node temp;
	temp = (node) malloc (1 * sizeof(struct BSTNode));
	temp->key = element;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


node insert(node root, int x){
	if(root == NULL){
		return createNode(x);
	}
	if(root->key > x){
		root->left =  insert(root->left, x);
	}
	else{
		root->right =  insert(root->right, x);
	}
	return root;
}


node search(node root, int x){
	if(root == NULL || root->key == x){
		return root;
	}
	if(x < root->key){
		return search(root->left, x);
	}
	return search(root->right, x);
}


node getSmallestBig(node root){
	node current = root;
	while(current && (current->left != NULL)){
		current = current->left;
	}
	return current;
}


node delete(node root, int x){
	if(root == NULL){
		return root;
	}
	else{
		if(x < root->key){
			root->left = delete(root->left, x);
		}
		else if(x > root->key){
			root->right = delete(root->right, x);
		}
		else{
			if(root->left == NULL){
				node temp = root->right;
				free(root);
				return temp;
			}
			else if(root->right == NULL){
				node temp = root->left;
				free(root);
				return temp;
			}
			else{
				node temp = getSmallestBig(root->right);
				root->key = temp->key;
				root->right = delete(root->right, temp->key);
			}
		}
		return root;
	}
}


int height(node root){
	int left_height, right_height;
	if(root == NULL){
		return 0;
	}
	else{
		left_height = height(root->left);
		right_height = height(root->right);
		if(left_height > right_height){
			return (left_height + 1);
		}
		else{
			return (right_height + 1);
		}
	}
}


void printGivenHeight(node root, int h){
	if(root != NULL){
		if(h == 1){
			printf("%d\t", root->key);
		}
		else if (h > 1){
			printGivenHeight(root->left, h - 1);
			printGivenHeight(root->right, h - 1);
		}
	}
}


void printLevelorder(node root){
	int i, h = height(root);
	for(i=1; i<=h; i++){
		printGivenHeight(root, i);
	}
}


void printInorder(node root){
	if(root != NULL){
		printInorder(root->left);
		printf("%d\t", root->key);
		printInorder(root->right);
	}
}


void printPreorder(node root){
	if(root != NULL){
		printf("%d\t", root->key);
		printPreorder(root->left);
		printPreorder(root->right);
	}
}


void printPostorder(node root){
	if(root != NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		printf("%d\t", root->key);
	}
}


int main(){
	node temp, root = NULL;
	int x, op;
	while(1){
		printf("Enter Operation code: (1 - Insert, 2 - Search, 3 - Delete, 4 - Print)");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Enter element to insert: ");
				scanf("%d", &x);
				root = insert(root, x);
				break;
			case 2: 
				printf("Enter element to search: ");
				scanf("%d", &x);
				temp = search(root, x);
				if(temp == NULL){
					printf("%d not found in tree\n", x);
				}
				else{
					printf("Element found in tree\n");
				}
				break;
			case 3:
				printf("Enter element to delete: ");
				scanf("%d", &x);
				temp = search(root, x);
				if(temp == NULL){
					printf("%d not found in tree\n", x);
				}
				else{
					root = delete(root, x);
				}
				break;
			case 4:
				printf("\t:::::::PREORDER:::::::::\n");
				printPreorder(root);
				printf("\n");
				printf("\t:::::::INORDER:::::::::\n");
				printInorder(root);
				printf("\n");
				printf("\t:::::::POSTORDER:::::::::\n");
				printPostorder(root);
				printf("\n");
				printf("\t:::::::LEVELORDER:::::::::\n");
				printLevelorder(root);
				printf("\n");
				break;
			default:
				exit(-1);
		}
	}
	return 0;
}
