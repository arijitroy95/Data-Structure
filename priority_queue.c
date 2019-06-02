#include<stdio.h>
#include<stdlib.h>


int heap_size = 0;
int INF = 10000000;

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void printArray(int array[]){
	int i;
	for(i=0; i<heap_size; i++){
		printf("%d\t", array[i]);
	}
	printf("\n");
}


void maxHeapify(int array[], int index){
	int left, right, largest;
	
	left = 2 * index + 1;
	right = 2 * index + 2;
	
	if (left < heap_size && array[left] > array[index]){
		largest = left;
	}
	else{
		largest = index;
	}
	
	if (right < heap_size && array[right] > array[index]){
		largest = right;
	}
	
	if (largest != index){
		swap(&array[largest], &array[index]);
		maxHeapify(array, largest);
	}
}


int heapMaximum(int array[]){
	return array[0];
}


int heapExtractMax(int array[]){
	int max;
	if(heap_size < 0){
		printf("Heap Underflow\n");
	}
	max = array[0];
	array[0] = array[heap_size];
	heap_size--;
	maxHeapify(array, 0);
	return max;
}


void heapIncreaseKey(int array[], int index, int key){
	if(key < array[index]){
		printf("New key element is smaller than current key element\n");
	}
	array[index] = key;
	while(index>0 && array[(index - 1)/ 2] < array[index]){
		swap(&array[index], &array[(index - 1)/ 2]);
		index = (index - 1)/ 2; 
	}
}


void heapDecreaseKey(int array[], int index, int key){
	array[index] = key;
	maxHeapify(array, index);
}


void maxHeapInsert(int array[], int key){
	heap_size++;
	array[heap_size] = -1 * INF;
	heapIncreaseKey(array, heap_size, key);
}


int main(){
	int array[20];
	maxHeapInsert(array, 20);
	maxHeapInsert(array, 15);
	maxHeapInsert(array, 1);
	printArray(array);
	
	heapIncreaseKey(array, 1, 22);
	printArray(array);
	heapDecreaseKey(array, 0, 13);
	printArray(array);
	
	printf("%d\n", heapMaximum(array));
	
	printf("%d\n", heapExtractMax(array));
	
	return 0;
}

