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
	int *array;
	int i;
	array = (int *) malloc (size * sizeof(int));
	srand(time(0));
	
	for(i=0; i<size; i++){
		array[i] = rand() % 100 + 1;
	}
	return array;
}


int partition(int *array, int start, int end){
	int pivot, i, j;
	pivot = array[end];
	i = start - 1;
	
	for(j=start; j<end; j++){
		if(pivot >= array[j]){
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[end], &array[i + 1]);
	return i + 1;
}


int randomizedPartion(int *array, int start, int end){
	int idx;
	idx = rand() % (end - start + 1) + start;
	swap(&array[idx], &array[end]);
	return partition(array, start, end);
}


int randomSelect(int *array, int start, int end, int i){
	if(start == end){
		return array[start];
	}
	else{
		int mid, pivot_idx;
		mid = randomizedPartion(array, start, end);
		pivot_idx = mid - start + 1;
		if(i == pivot_idx){
			return array[mid];
		}
		else if(i < pivot_idx){
			return randomSelect(array, start, mid - 1, i);
		}
		else{
			return randomSelect(array, mid + 1, end, i - pivot_idx);
		}
	}
}


int main(){
	int *array;
	int n, idx;
	
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	array = createArray(n);
	printf("\t::::::::::::: Input Array :::::::::::::::\n");
	printArray(array, n);
	
	printf("Enter the value of i for ith min number: ");
	scanf("%d", &idx);
	if (idx > n){
		printf("i must be larger than %d\n", n);
	}
	else if (idx == 0){
		printf("i must can not be 0\n");
	}
	else{
		int ans;
		ans = randomSelect(array, 0, n - 1, idx);
		printf("%d th smallest element is %d\n",idx, ans);
	}
	return 0;
}
