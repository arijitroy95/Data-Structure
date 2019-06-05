#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


int *createArray(int size){
	int *array;
	int i;
	
	array = (int *) malloc (size * sizeof(int));
	srand(time(0));
	for(i=0; i<size; i++){
		array[i] = rand() % 100 + 1;
	}
	return array;
}


void printArray(int *array, int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}


int partition(int *array, int p, int r){
	int pivot, i, j, index;
	i = p - 1;
	j = p;
	pivot = array[r];
	
	for(j=p; j<r; j++){
		if(array[j] <= pivot){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[r]);
	
	return i + 1;
}


int randomizedPartition(int *array, int p, int r){
	int idx;
	srand(time(0));
	idx = rand() % (r - p + 1) + p;
	swap(&array[r], &array[idx]);
	return partition(array, p, r);
}


void randamizedQuickSort(int *array, int start, int end){
	if(start < end){
		int part_index = randomizedPartition(array, start, end);
		randamizedQuickSort(array, start, part_index - 1);
		randamizedQuickSort(array, part_index + 1, end);
	}	
}


int main(){
	int *array;
	int n;
	printf("Enter size of array: ");
	scanf("%d", &n);
	array = createArray(n);
	printf("\t::::::::: Input Array ::::::::::\n");
	printArray(array, n);
	randamizedQuickSort(array, 0, n - 1);
	printf("\t::::::::: Output Array ::::::::::\n");
	printArray(array, n);
	return 0;
}
