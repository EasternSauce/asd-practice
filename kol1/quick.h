#include <iostream>
#include "utility.h"
#include "node.h"
using namespace std;

int partition(int tab[], int left, int right){ // we take the last element and put every lower element before it and every greater element in front of it in no particular order
	int x = tab[right]; // x is the value of the most right element
	int i = left - 1;
	for(int j = left; j < right; j++){ //from left to right
		if(tab[j] <= x){ //if elements less/equal x
			i++; //increment i
			swap(tab[i], tab[j]); //swap
		}
	}
	//swap the element at x with the i-th element
	i++;
	swap(tab[i], tab[right]);
	return i;
}

void quickSort(int tab[], int left, int right){ // sort the array from left index to right index
	if(right < left) return; // recursion stop
	int pivot = partition(tab, left, right); // patrition the array so on the left are elements below the pivot, and same thing for right
	quickSort(tab, left, pivot-1); // sort to pivot
	quickSort(tab, pivot+1, right); // sort from pivot
}

node* partition(node* &left, node* &right){
	node* pivot = right;
	node* prev = NULL;
	node* cur = left;
	while(cur != pivot){
		if(cur->value <= pivot->value){
			prev = cur;
			cur = cur->next;
		}
		else{
			node* future_cur = cur->next;
			if(prev != NULL) prev->next = cur->next;
			else left = cur->next;
			cur->next = right->next;
			right->next = cur;
			right = cur;
			cur = future_cur;
		}
	}
	return pivot;
}

void quickSort(node* &left, node* &right){
	if(left == NULL || left == right || right->next == left) return;

	node* pivot = partition(left, right);
	
	if(pivot != left){
		node* prev_pivot = left;
		while(prev_pivot->next != pivot){
			prev_pivot = prev_pivot->next;
		}
		quickSort(left, prev_pivot);
	}
	node* after_pivot = pivot->next;
	quickSort(after_pivot, right);
	pivot->next = after_pivot;
}

node* quickSort(node* head){
	node* tail = head;
	while(tail->next != NULL) tail = tail->next;
	quickSort(head, tail);
	return head;
}

int quickSelectMin(int A[], int n, int k){
	if(n < 1) return A[0];
	int q = partition(A, 0, n-1);
	if(k == q) return A[k];
	else if(k < q) return quickSelectMin(A, q, k);
	else return quickSelectMin(A+(q+1), n-(q+1), k-(q+1));
}

int quickSelectMax(int A[], int n, int k){
	return quickSelectMin(A, n, n-(k+1));
}


node* quickerSort(node* head){
	if(head == NULL) return head;

	//sentinels will be useful when reconnecting the lists
	node* less = new node;
	less->next = NULL;
	node* equal = new node;
	equal->next = NULL;
	node* more = new node;
	more->next = NULL;

	//unpin head and pin it to equal
	node* tmp = head;
	head = head->next;
	tmp->next = equal->next;
	equal->next = tmp;

	//iterator with a sentinel
	node* iter = head;
	node* iter_sentinel = new node;
	node* prev_iter = iter_sentinel;
	prev_iter->next = iter;

	//divide the main list into less, more, equal
	while(iter != NULL){
		if(iter->value == equal->next->value){
			tmp = iter->next;
			prev_iter->next = iter->next;
			iter->next = equal->next;
			equal->next = iter;
			iter = tmp;
		}
		else if(iter->value < equal->next->value){
			tmp = iter->next;
			prev_iter->next = iter->next;
			iter->next = less->next;
			less->next = iter;
			iter = tmp;
		}
		else{
			tmp = iter->next;
			prev_iter->next = iter->next;
			iter->next = more->next;
			more->next = iter;
			iter = tmp;
		}
	}
	delete iter_sentinel;

	//recursion
	less->next = quickerSort(less->next);
	more->next = quickerSort(more->next);

	//joining list together
	iter = less;
	while(iter->next != NULL){
		
		iter = iter->next;
	}
	iter->next = equal->next;
	iter = equal;
	while(iter->next != NULL){
		
		iter = iter->next;
	}
	iter->next = more->next;

	node* sorted = less->next;

	//delete sentinels
	delete less;
	delete equal;
	delete more;

	return sorted;
}
