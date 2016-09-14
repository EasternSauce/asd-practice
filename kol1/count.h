#include <iostream>
using namespace std;

void countSort(int A[], int n, int k){
	int B[n];
	int C[k];
	for(int i = 0; i < k; i++) C[i] = 0; //C is filled with zeros
	for(int i = 0; i < n; i++) C[A[i]]++; //C becomes an array with quantities of items
	for(int i = 1; i < k; i++) C[i] = C[i] + C[i-1]; //every element has sum of items in sorted list so far
	for(int i = n-1; i >= 0; i--){
		C[A[i]]--;
		B[C[A[i]]] = A[i];
	}
	for(int i = 0; i < n; i++) A[i] = B[i];
}
