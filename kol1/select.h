#include <iostream>
#include "node.h"
using namespace std;

node* removeMax(node* guard){ // remove max from list
	node* prev = guard; // save previous
	node* max = guard->next; // max candidate
	while(guard->next != NULL){ // look for max
		if(guard->next->value > max->value){ // if found bigger, replace
			prev = guard;
			max = guard->next;
		}
		guard = guard->next; // iterate
	}
	if(max != NULL){ // if the list was not empty
		prev->next = max->next; // remove item
	}
	max->next = NULL; // just so the returned node has no relation to the list
	return max;
}

node* selectionSort(node* guard){
	node* sorted = new node; //new sorted list
	sorted->next = NULL;

	while(guard->next != NULL){
		node* inserted = removeMax(guard); //remove max
		inserted->next = sorted->next; //and put it in the sorted list
		sorted->next = inserted;
	}
	
	delete guard;
	return sorted;
}

