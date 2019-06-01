#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void printArray(double *array, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d\t", (int)array[i]);
	}
	printf("\n");
}


double *createArray(int size){
	srand(time(0));
	double *array;
	int i;
	array = (double *) malloc (size * sizeof(double));
	for(i=0; i<size; i++){
		array[i] = rand() % 100 + 1;
	}
	return array;
}


void merge(double *array, int start, int mid, int end){
	int i, j, k, n1, n2;
	double *left, *right;
	double HUGE = INFINITY;
	
	n1 = mid - start + 1;
	n2 = end - mid;
	
	left = (double *) malloc ((n1 + 1) * sizeof(double));
	right = (double *) malloc ((n2 + 1) * sizeof(double));
	for(i=0; i<n1; i++){
		left[i] = array[start + i];
	}
	for(j=0; j<n2; j++){
		right[j] = array[mid + 1 + j];
	}
	left[n1] = HUGE;
	right[n2] = HUGE;
	
	i = 0, j = 0;
	
	for(k=start; k<=end; k++){
		if(left[i] < right[j]){
			array[k] = left[i];
			i++;
		}
		else{
			array[k] = right[j];
			j++;
		}
	}
	free(left);
	free(right);
}


void mergeSort(double *array, int start, int end){
	if(start < end){
		int mid;
		mid = (start + end) / 2;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
}


int main(){
	int n;
	double *array;
	double temp[4];
	printf("Enter size of array: ");
	scanf("%d", &n);
	array = createArray(n);
	printf("\t:::::::::: Input Array ::::::::::\n");
	printArray(array, n);
	mergeSort(array, 0, n - 1);
	printf("\t:::::::::: Output Array ::::::::::\n");
	printArray(array, n);
	return 0;
}
