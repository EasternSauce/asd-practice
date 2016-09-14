#include <iostream>
using namespace std;

int pow(int x, int n){
	int r = 1;
	for(int i = 0; i < n; i++) r = r*x;
	return r;
}

int getDigit(int x, int k){
	return (x/pow(10,k))%10;
}

void countSort(int A[], int n, int radix, int k){
	int B[n];
	int C[k];
	for(int i = 0; i < k; i++) C[i] = 0; //C is filled with zeros
	for(int i = 0; i < n; i++) C[getDigit(A[i], radix)]++; //C becomes an array with quantities of items
	for(int i = 1; i < k; i++) C[i] = C[i] + C[i-1]; //every element has sum of items in sorted list so far
	for(int i = n-1; i >= 0; i--){
		C[getDigit(A[i], radix)]--;
		B[C[getDigit(A[i], radix)]] = A[i];
	}
	for(int i = 0; i < n; i++) A[i] = B[i];
}

void radixSort(int A[], int n, int k){
	for(int i = 0; i < k; i++){
		countSort(A, n, i, 10);
	}
}
