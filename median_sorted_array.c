#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>


int min(int x, int y){
	if(x <= y){
		return x;
	}
	else{
		return y;
	}
}


int median(int A[], int B[], int n, int low, int high){
	if(low > high){
		return INT_MAX; 
	}
	else{
		int k;
		k = floor((low + high) / 2);
		if((k == (n - 1)) && (A[n - 1] < B[0])){
			return A[n - 1];
		}
		else if((k < n-1) && (B[n - k - 1] <= A[k]) && (A[k] <= B[n - k])){
			return A[k];
		}
		else if(A[k] > B[n - k +1]){
			return median(A, B, n, low, k - 1);
		}
		else{
			return median(A, B, n, k + 1, high);
		}
	}
}


int main(){
	int A[] = {11, 17, 20};
	int B[] = {10, 19, 21};
	int ans, n = 3;
	ans = median(A, B, n, 0, n - 1);
	if (ans == INT_MAX){
		ans = median(B, A, n, 0, n - 1);
	}
	printf("%d\n", ans);
	return 0;
}

