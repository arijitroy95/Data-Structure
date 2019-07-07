#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct ansTuple{
	int *memoArr;
	int *rodLengths;
};


int max(int a, int b){
	if(a < b)
		return b;
	return a;
}


int cut_rod_simple(int *cutPrice, int n){
	if(n == 0)
		return 0;
	else{
		int q, i;
		q = INT_MIN;
		for(i=1; i<=n; i++)
			q = max(q, cutPrice[i] + cut_rod_simple(cutPrice, n - i));
		return q;
	}
}


int memoized_cut_rod_util(int *cutPrice, int n, int *memoArr){
	if(memoArr[n] >= 0)
		return memoArr[n];
	if(n == 0)
		return 0;
	else{
		int q, i;
		q = INT_MIN;
		for(i=1; i<=n; i++)
			q = max(q, cutPrice[i] + memoized_cut_rod_util(cutPrice, n - i, memoArr));
		return q;
	}
}


int memoized_cut_rod(int *cutPrice, int n){
	int *memoArr;
	int i;
	memoArr = (int *) malloc ((n + 1) * sizeof(int));
	for(i=0; i<=n; i++)
		memoArr[i] = INT_MIN;
	return memoized_cut_rod_util(cutPrice, n, memoArr);
}


int buttom_up_cut_rod(int *cutPrice, int n){
	int *memoArr;
	int i, j, q;
	memoArr = (int *) malloc ((n + 1) * sizeof(int));
	memoArr[0] = 0;
	for(j=1; j<=n; j++){
		q = INT_MIN;
		for(i=1; i<=j; i++)
			q = max(q, cutPrice[i] + memoArr[j - i]);
		memoArr[j] = q;
	}
	return memoArr[n];
}


struct ansTuple rod_cut_with_lengths(int *cutPrice, int n){
	struct ansTuple finalAns;
	int *memoArr, *rodLengths;
	int i, j, q;
	memoArr = (int *) malloc ((n + 1) * sizeof(int));
	rodLengths = (int *) malloc ((n + 1) * sizeof(int));
	memoArr[0] = 0;
	for(j=1; j<=n; j++){
		q = INT_MIN;
		for(i=1; i<=j; i++)
			if(q < cutPrice[i] + memoArr[j - i]){
				q = cutPrice[i] + memoArr[j - i];
				rodLengths[j] = i;
			}
		memoArr[j] = q;
	}
	finalAns.memoArr = memoArr;
	finalAns.rodLengths = rodLengths;
	return finalAns;
}


void print_solution(int *cutPrice, int n){
	struct ansTuple ans = rod_cut_with_lengths(cutPrice, n);
	int *memoArr, *rodLengths;
	memoArr = ans.memoArr;
	rodLengths = ans.rodLengths;

	printf("%d\n", memoArr[n]);
	while(n > 0){
		printf("%d ", rodLengths[n]);
		n = n - rodLengths[n];
	}
	printf("\n");
}


int main(){
	int ans, i, n;
	int *cutPrice;
	printf("Total length of rod: ");
	scanf("%d", &n);
	cutPrice = (int *) malloc ((n + 1) * sizeof(int));
	for(i=1; i<=n; i++)
		scanf("%d", &cutPrice[i]);
	
	ans = cut_rod_simple(cutPrice, n);
	printf("%d\n", ans);
	ans = memoized_cut_rod(cutPrice, n);
	printf("%d\n", ans);
	ans = buttom_up_cut_rod(cutPrice, n);
	printf("%d\n", ans);
	print_solution(cutPrice, n);
	return 0;
}
