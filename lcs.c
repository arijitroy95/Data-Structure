/*
	IN DIRECTION 	N --> NUTRAL, 
					D --> DIAGONAL, 
					U --> UP, 
					L --> LEFT
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STR_LEN 256


struct structure{
	int length;
	char direction;
};

typedef struct structure element;

element **defineMatrix(int rows, int cols){
	element **temp;
	int i, j;
	
	temp = (element **) malloc (rows * sizeof(element *));
	for(i=0; i<rows; i++)
		temp[i] = (element *) malloc (cols * sizeof(element));
	
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++){
			temp[i][j].length = 0;
			temp[i][j].direction = 'N';
		}
	}
	return temp;
}


void printMatrix(element **matrix, int rows, int cols){
	int i, j;
	for(i=0; i<rows; i++){
		for(j=0; j<cols; j++)
			printf("%d|%c\t", matrix[i][j].length, matrix[i][j].direction);
		printf("\n");
	}
}


void printLCS(element **lcsMatrix, char sequence1[], int i, int j){
	if((i==0) || (j==0))
		return;
	if(lcsMatrix[i][j].direction == 'D'){
		printLCS(lcsMatrix, sequence1, i-1, j-1);
		printf("%c", sequence1[i-1]);
	}
	else if(lcsMatrix[i][j].direction == 'U')
		printLCS(lcsMatrix, sequence1, i-1, j);
	else
		printLCS(lcsMatrix, sequence1, i, j-1);
}


void findLCS(char sequence1[], char sequence2[]){
	int lenOfSeq1, lenOfSeq2, i, j;
	element **lcsMatrix;
	lenOfSeq1 = strlen(sequence1) + 1;
	lenOfSeq2 = strlen(sequence2) + 1;
	
	lcsMatrix = defineMatrix(lenOfSeq1, lenOfSeq2);
	
	for(i=1; i<lenOfSeq1; i++){
		for(j=1; j<lenOfSeq2; j++){
			if(sequence1[i] == sequence2[j]){
				lcsMatrix[i][j].length = lcsMatrix[i-1][j-1].length + 1;
				lcsMatrix[i][j].direction = 'D';
			}
			else if(lcsMatrix[i-1][j].length >= lcsMatrix[i][j-1].length){
					lcsMatrix[i][j].length = lcsMatrix[i-1][j].length;
					lcsMatrix[i][j].direction = 'U';
				}
			else{
				lcsMatrix[i][j].length = lcsMatrix[i][j-1].length;
				lcsMatrix[i][j].direction = 'L';
			}
		}
	}
	//printMatrix(lcsMatrix, lenOfSeq1, lenOfSeq2);
	printLCS(lcsMatrix, sequence1, lenOfSeq1-1, lenOfSeq2-1);
	printf("\n");
}


int main(){
	char sequence1[MAX_STR_LEN], sequence2[MAX_STR_LEN];
	
	printf("Enter first sequence: ");
	scanf("%s", sequence1);
	
	printf("Enter second sequence: ");
	scanf("%s", sequence2);
	printf("\n");
	findLCS(sequence1, sequence2);
	return 0;
}
