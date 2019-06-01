//Works better than mergesort as runtime is o(nk), here k = 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define SORT_RANGE 10  

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


void insertionSort(double *array, int start, int end){
	int i, j;
	double key;
	
	for(i=start + 1; i<end + 1; i++){
		key = array[i];
		j = i - 1;
		while(j>=start && array[j] > key){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
	
}


void merge(double *array, int start, int mid, int end){
	int n1, n2, i, j, k;
	double HUGE = INFINITY;
	double *left, *right;
	
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
	for(k=start; k<end+1; k++){
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
	if(end - start > SORT_RANGE){
		int mid;
		mid = floor((start + end) / 2);
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, mid, end);
	}
	else{
		insertionSort(array, start, end);
	}
}


int main(){
	int n;
	double *array;
	printf("Enter size of array: ");
	scanf("%d", &n);
	array = createArray(n);
	printf("\t:::::::::: Input Array ::::::::::\n");
	printArray(array, n);
	mergeSort(array, 0, n-1);
	printf("\t:::::::::: Output Array ::::::::::\n");
	printArray(array, n);
	return 0;
}
