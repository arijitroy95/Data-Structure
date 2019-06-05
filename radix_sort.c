#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void printArray(int *array, int size){
	int i;
	for (i=0; i<size; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int *createArray(int size){
	int *array;
	int i;
	srand(time(0));
	array = (int *) malloc (size * sizeof(int));
	for(i=0; i<size; i++){
		array[i] = rand() % 100 + 1;
	}
	return array;
}


int getMax(int *array, int size){
	int i, max;
	max = array[0];
	for(i=1; i<size; i++){
		if(max < array[i]){
			max = array[i];
		}
	}
	return max;
}


void countSort(int *array, int size, int exponent){
	int *output_array, *count;
	int i, count_idx;
	
	output_array = (int *) malloc (size * sizeof(int));
	count = (int *) malloc (10 * sizeof(int));
	
	for(i=0; i<10; i++){
		count[i] = 0;
	}
	
	for(i=0; i<size; i++){
		count_idx = (array[i] / exponent) % 10;
		count[count_idx] += 1;
	}
	
	for(i=0; i<10; i++){
		count[i] += count[i - 1];
	}
	
	for(i=size-1; i>=0; i--){
		count_idx = (array[i] / exponent) % 10;
		output_array[count[count_idx] - 1] = array[i];
		count[count_idx]--;
	}
	for(i=0; i<size; i++){
		array[i] = output_array[i];
	}
	free(output_array);
	free(count);
}


void radix_sort(int *array, int size){
	int max, exponent;
	max = getMax(array, size);
	for(exponent=1; max/exponent > 0; exponent *= 10){
		countSort(array, size, exponent);
	}
}


int main(){
	int *array;
	int n;
	
	printf("Enter size of array: ");
	scanf("%d", &n);
	printf("\t::::::::::::::: Input Array ::::::::::::\n");
	array = createArray(n);
	printArray(array, n);
	radix_sort(array, n);
	printf("\t::::::::::::::: Output Array ::::::::::::\n");
	printArray(array, n);
	return 0;
}
