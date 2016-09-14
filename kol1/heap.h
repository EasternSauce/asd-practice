#include "utility.h"

int parent(int i){
	return (i-1)/2;
}

int left(int i){
	return 2*i+1;
}

int right(int i){
	return 2*i+2;
}

int heapify(int A[], int n, int i){
	int ind_max = i;
	int l = left(i), r = right(i);
	if(l < n and A[l] > A[ind_max]) ind_max = l;
	if(r < n and A[r] > A[ind_max]) ind_max = r;
	if(ind_max != i){
		swap(A[i], A[ind_max]);
		heapify(A, n, ind_max);
	}
}

void buildHeap(int A[], int n){
	for(int i = parent(n-1); i >= 0; i--) heapify(A, n, i);
}

void heapSort(int A[], int n){
	buildHeap(A, n);
	for(int i = n-1; i >= 1; i--){
		swap(A[0], A[i]);
		heapify(A, i, 0);
	}
}
