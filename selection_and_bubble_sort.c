#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void printArray(int *array, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int *createArray(int size){
	int i;
	int *array;
	
	srand(time(0));
	array = (int *) malloc (size * sizeof(int));
	for(i=0; i<size; i++){
		array[i] = rand() % 100 + 1;
	}
	return array;
}


void selectionSort(int *array, int size){
	int i, j, min;
	for(i=0; i<(size - 1); i++){
		min = i;
		for(j=i+1; j<size; j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		swap(&array[i], &array[min]);
	}
}


void bubbleSort(int *array, int size){
	int i, j;
	for(i=0; i<size-1; i++){
		for(j=0; j<size-i-1; j++){
			if(array[j] > array[j+1]){
				swap(&array[j+1], &array[j]);
			}
		}
	}
}


int main(){
	int *array;
	int n;
	
	printf("Enter size of array: ");
	scanf("%d", &n);
	printf("\t:::::::: Input Array ::::::::::\n");
	array = createArray(n);
	printArray(array, n);
	//bubbleSort(array, n);
	selectionSort(array, n);
	printf("\t:::::::: Output Array ::::::::::\n");
	printArray(array, n);
	return 0;
}
