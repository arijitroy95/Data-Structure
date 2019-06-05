#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_DIGIT 101


void printArray(int *array, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int *createArray(int size){
	srand(time(0));
	int *array;
	int i;
	array = (int *) malloc (size * sizeof(int));
	for(i=0; i<size; i++){
		array[i] = rand() % 100;
	}
	return array;
}


int *countingSort(int *array, int size){
	int *output_array, *count;
	int i;
	count = (int *) malloc (MAX_DIGIT * sizeof(int));
	
	for (i=0; i<MAX_DIGIT; i++){
		count[i] = 0;
	}
	for (i=0; i<size; i++){
		count[array[i]] += 1;
	}
	for (i=1; i<MAX_DIGIT; i++){
		count[i] += count[i - 1];
	}
	output_array = (int *) malloc (size * sizeof(int));
	for (i=size-1; i>=0; i--){
		output_array[count[array[i]] - 1] = array[i];
		count[array[i]] --;
	}
	free(count);
	return output_array;
}


int main(){
	int *array, *output_array;
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	printf("\t::::::::::::: Input Array :::::::::::::\n");
	array = createArray(n);
	printArray(array, n);
	printf("\t::::::::::::: Output Array :::::::::::::\n");
	output_array = countingSort(array, n);
	printArray(output_array, n);
	return 0;
}
