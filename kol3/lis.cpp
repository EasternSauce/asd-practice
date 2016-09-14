#include <iostream>
using namespace std;

int LIS(int A[], int n){
	int F[n];
	F[0] = 1;
	for(int i = 1; i < n; i++){
		F[i] = 1;
		for(int t = 0; t <= i-1; t++){
			if(A[t] < A[i] and F[t]+1 > F[i]){
				F[i] = F[t]+1;
			}
		}
	}
	int max = 0;
	for(int i = 0; i < n; i++) if(F[i] > max) max = F[i];
	return max;
}

int main(){
	const int N = 10;
	int A[N] = {1, 2, 3, 7, 6, 5, 4, 3, 2, 1};

	cout << LIS(A, N);

}
