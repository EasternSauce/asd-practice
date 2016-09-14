#include <iostream>
using namespace std;

void merge(int tab[], int middle, int size);

void mergeSort(int tab[], int size){
	if(size <= 1) return;
	mergeSort(tab, size/2); // sort from beginning to middle
	mergeSort(&tab[size/2], size-size/2); // sort from middle to end
	merge(tab, size/2, size); // merge sorted arrays
}

void merge(int tab[], int middle, int size) // go through both arrays and merge them
{
	int copy[size]; // hold an unchanged copy of the array where we take the elements to merge from
	for(int i = 0; i < size; i++) copy[i] = tab[i];
	int left = 0;
	int right = middle;
	int iterator = 0;
	while(left < middle and right < size){ // while both parts to merge are not depleted
		if(copy[left] <= copy[right]){ // if first from left is lesser than first from right
			tab[iterator] = copy[left]; // put the element in
			left++;
		}
		else{ // if the right one is greater
			tab[iterator] = copy[right];
			right++;
		}
		iterator++;
	}
	while(left < middle){ // append rest of left part if it is not empty
		tab[iterator] = copy[left];
		left++;
		iterator++;
	}
	while(right < size){ // append rest of right part if it is not empty
		tab[iterator] = copy[right];
		right++;
		iterator++;
	}
}

