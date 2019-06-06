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


int* createArray(int size){
	int* array;
	int i;
	srand(time(0));
	array = (int *) malloc (size * sizeof(int));
	for(i=0; i<size; i++){
		array[i] = rand() % 1000 + 1;
	}
	return array;
}


int partition(int *array, int start, int end, int pivot){
	int i, j, k;
	
	for(i=start; i<=end; i++){
		if(array[i] == pivot){
			swap(&array[i], &array[end]);
			break;
		}
	}
	
	pivot = array[end];
	i = start - 1;
	for(j=start; j<end; j++){
		if(array[j] <= pivot){
			i++;
			swap(&array[i], &array[j]);	
		}
	}
	swap(&array[end], &array[i + 1]);
	return i + 1;
}


void sort(int *temp_array, int size){
	int i, j, key;
	
	for(i=1; i<size; i++){
		key = temp_array[i];
		j = i - 1;
		while(j>=0 && temp_array[j] > key){
			swap(&temp_array[j], &temp_array[j + 1]);
			j--;
		}
		temp_array[j + 1] = key;
	}
}


int getMedian(int *array, int start, int end){
	int *temp;
	int i, n, j = 0;
	n = end - start + 1;
	temp = (int *) malloc (n * sizeof(int));
	for(i=start; i<=end; i++){
		temp[j++] = array[i];
	}
	sort(temp, n);
	return temp[n / 2];
}

int getMidofMid(int *array,int start,int end){
	int n, j, high, low;
	int *median;
	n = end - start + 1;
	low = start;
	if(n > 4)
		high = start + 4;
	else high = end;
	int nsize = (n+4)/5;
	median = (int *) malloc (nsize * sizeof(int));
	for(j=0; j < nsize; j++){
		median[j] = getMedian(array, low, high);
		low = high+1;
		if (high < (start+n-5))
			high += 5; 
			
		else high = start+n-1;
	}
	if(nsize == 1) return *median;
	return getMidofMid(median,0,nsize-1);
}

int Select(int *array, int start, int end, int i){
	int pivot = getMidofMid(array,start,end);
	int q = partition(array,start,end,pivot) - start +1;
	if(i==q)
		return array[start+q-1];
	else if(i<q)
		return Select(array,start,start + q-2,i);
	else return Select(array,start+q,end,i-q);
	
}


int main(){
	int n, i;
	int *array;
	
	printf("Enter size of Array: ");
	scanf("%d", &n);

	printf("\t:::::::::::::: Input Array :::::::::::\n");
	array = createArray(n);
	printArray(array, n);
	printf("Enter i: ");
	scanf("%d",&i);
	printf("Ans is ::: %d\n",Select(array,0,n-1,i));
	return 0;
}
