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


int left(int index){
	return 2 * index + 1;
}


int right(int index){
	return 2 * index + 2;
}


void maxHeapify(int *array, int index, int heap_size){
	int l, r, largest;
	l = left(index);
	r = right(index);
	
	if(l < heap_size && array[l] > array[index]){
		largest = l;
	}
	else{
		largest = index;
	}
	if(r < heap_size && array[r] > array[index]){
		largest = r;
	}
	
	if(largest != index){
		swap(&array[index], &array[largest]);
		maxHeapify(array, largest, heap_size);
	}
}


void buildMaxHeap(int *array, int size){
	int i;
	for(i=(size / 2) - 1; i>=0; i--){
		maxHeapify(array, i, size);
	}
}


void heapSort(int *array, int size){
	int heap_size;
	buildMaxHeap(array, size);
	for(heap_size=size - 1; heap_size>=0; heap_size--){
		swap(&array[0], &array[heap_size]);
		maxHeapify(array, 0, heap_size);
	}
}


int main(){
	int n, i;
	int *array;
	
	printf("Enter size of array: ");
	scanf("%d", &n);
	array = createArray(n);
	printf("\t:::::::::: Input Array ::::::::::\n");
	printArray(array, n);
	heapSort(array, n);
	printf("\t:::::::::: Output Array ::::::::::\n");
	printArray(array, n);
	return 0;
}
