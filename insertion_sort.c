#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void swap(int *a, int*b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void printArray(int *arr, int size){
	int i;
	for(i=0; i<size; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}


int *createArray(int size){
	int i;
	int *array;
	array = (int *) malloc(size * sizeof(int));
	srand(time(0));
	for(i=0; i<size; i++){
		array[i] = rand() % 100 + 1;
	}
	return array;
}


void insertionSortArray(int *array, int size){
	int i, key, j, count = 0;
	for(i=1; i<size; i++){
		key = array[i];
		j = i - 1;
		while(j>=0 && array[j]>key){
			//array[j + 1] = array[j];
			swap(&array[j + 1], &array[j]);
			count++;
			j--;
		}
		array[j + 1] = key;
	}
	printf("Total number of swap happend: %d\n", count);
}


int main(){
	int i, n;
	int *array;
	printf("Enter size of the array: ");
	scanf("%d", &n);
	/*for(i=0; i<n; i++){
		printf("Enter %dth element of the array: ", i + 1);
		scanf("%d", &array[i]);
	}*/
	array = createArray(n);
	printf("\t:::::::Input array:::::::\n");
	printArray(array, n);
	insertionSortArray(array, n);
	printf("\t:::::::Output array:::::::\n");
	printArray(array, n);
	free(array);
	return 0;
}
