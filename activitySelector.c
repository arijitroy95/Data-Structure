// Solves the activicty selector problem using greedy algorithm

#include<stdio.h>
#include<stdlib.h>

struct structure1{
	int idx;
	int start;
	int finish;
};
struct structure2{
	int value;
	struct structure2 *next;
};

typedef struct structure1 input;
typedef struct structure2* set;

set answerSet=NULL;

set createElement(int element){
	set temp;
	temp = (set) malloc (1 * sizeof(struct structure2));
	temp->value = element;
	temp->next = NULL;
	return temp; 
}


set addToSet(set head, int element){
	set temp = createElement(element);
	if(head == NULL)
		head = temp;
	else{
		set dummy = head;
		while(dummy->next != NULL){
			if(dummy->value == element)
				return head;
			dummy = dummy->next;
		}
		dummy->next = temp;
	}
	return head;
}


void printSet(set head){
	if(head){
		printf("%d\t", head->value);
		printSet(head->next);
	}
}


input *make_input(int size){
	input *allInputs;
	int i, s, f;
	allInputs = (input *) malloc (size * sizeof(input));
	allInputs[0].idx = 0;
	allInputs[0].start = 0;
	allInputs[0].finish = 0;
	for(i=1; i<size; i++){
		printf("Enter Start and End time of ativity %d: ", i);
		scanf("%d%d", &s,&f);
		allInputs[i].idx = i;
		allInputs[i].start = s;
		allInputs[i].finish = f;
	}
	return allInputs;
}


void swap(input *x, input *y){
	input temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


int partition(input *inputArr, int p, int r){
	int pivot, i, j, index;
	i = p - 1;
	pivot = inputArr[r].finish;
	for(j=p; j<r; j++){
		if(inputArr[j].finish < pivot){
			i++;
			swap(&inputArr[i], &inputArr[j]);
		}
	}
	swap(&inputArr[i+1], &inputArr[r]);
	return i+1;
}


void quickSort(input *inputArr, int start, int end){
	if(start < end){
		int pivot = partition(inputArr, start, end);
		quickSort(inputArr, start, pivot-1);
		quickSort(inputArr, pivot+1, end);
	}
}


input *sortInput(int size){
	input *inputArr;
	inputArr = make_input(size);
	quickSort(inputArr, 0, size-1);
	return inputArr;
}

void printArr(input *inputArr, int size){
	int i;
	for(i=0; i<size; i++)
		printf("%d|%d|%d\n", inputArr[i].idx, inputArr[i].start, inputArr[i].finish);
}


void activitySelector(input *inputArr, int subproblemIdx, int size){
	int m = subproblemIdx + 1;
	while((m < size) && (inputArr[m].start < inputArr[subproblemIdx].finish))
		m++;
	if(m<size){
		answerSet = addToSet(answerSet, inputArr[m].idx);
		activitySelector(inputArr, m, size);
	}
}


void activitySelectorIter(input *inputArr, int size){
	int m, subproblemIdx = 1;
	answerSet = addToSet(answerSet, inputArr[subproblemIdx].idx);
	for(m=1; m<size; m++){
		if(inputArr[m].start > inputArr[subproblemIdx].finish){
			answerSet = addToSet(answerSet, inputArr[m].idx);
			subproblemIdx = m;
		}
	}
}


int main(){
	input *inputArr;
	int n;
	printf("Number of activities: ");
	scanf("%d", &n);
	n++;
	inputArr = sortInput(n);
	activitySelectorIter(inputArr, n);
	printf("Optimal activity sequence is: ");
	printSet(answerSet);
	printf("\n");
	return 0;
}
