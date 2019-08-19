#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


int **defineMatrix(int n){
	int **temp;
	int i, j;
	temp = (int **) malloc (n * sizeof(int *));
	for(i=0; i<n; i++)
		temp[i] = (int *) malloc (n * sizeof(int));
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			temp[i][j] = -1;
	}
	return temp;
}


void printMatrix(int **matrix, int n){
	int i, j;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d\t", matrix[i][j]);
		printf("\n");
	}
}


void printChainOrder(int **breakpoints, int i, int j){
	if(i==j)
		printf("A%d", i);
	else{
		printf("(");
		printChainOrder(breakpoints, i, breakpoints[i][j]);
		printChainOrder(breakpoints, breakpoints[i][j] + 1, j);
		printf(")");
	}
}


void matrixChainOrder(int *matrixSizes, int n){
	int **multiplications, **breakpoints;
	int i, j, k, l, q;
	multiplications = defineMatrix(n);
	breakpoints = defineMatrix(n);
	
	for(i=1; i<n; i++)
		multiplications[i][i] = 0;
		
	for(l=2; l<n; l++){
		for(i=1; i<n-l+1; i++){
			j = i + l - 1;
			multiplications[i][j] = INT_MAX;
			for(k=i; k<j; k++){
				q = multiplications[i][k] + multiplications[k+1][j] + matrixSizes[i-1] * matrixSizes[k] * matrixSizes[j];
				if(q < multiplications[i][j]){
					multiplications[i][j] = q;
					breakpoints[i][j] = k;
				}
			}
		}
	}
	printf("Optimal Number of Multiplication is :: %d\n", multiplications[1][n-1]);
	/*
	printf("\t\t\tMUTLITABLE\n");
	printMatrix(multiplications, n);
	printf("\t\t\tBREAKPOINT\n");
	printMatrix(bearkpoints, n);
	*/
	printChainOrder(breakpoints, 1, n-1);
	printf("\n");
}




int main(){
	int n, i, tempnr, tempnc;
	int *matrixSizes;
	printf("Number of Matrixes: ");
	scanf("%d", &n);
	n++;
	int todo = 1;
	
	matrixSizes = (int *) malloc (n * sizeof(int));
	for(i=0; i<n-1; i++){
		printf("Enter Matrix Sizes (space seperated): ");
		scanf("%d%d", &tempnr, &tempnc);
		if(i==0){
			matrixSizes[0] = tempnr;
			matrixSizes[1] = tempnc;
		}
		else{
			if(matrixSizes[i] == tempnr)
				matrixSizes[i+1] = tempnc;
			else{
				printf("INCONSISTENT MATRIX SIZES\n");
				todo = 0;
				break;
			}
		}
	}
	if(todo == 1)
		matrixChainOrder(matrixSizes, n);
	return 0;
}




