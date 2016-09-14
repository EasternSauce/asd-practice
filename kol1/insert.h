#include <iostream>
#include "node.h"
using namespace std;

void insert(node* guard, int value){ // insert a node into a sorted list by value
	node* inserted = new node;
	inserted->value = value;
	while(guard->next != NULL && !(guard->next->value > value)){ // get into position
		guard = guard->next;
	}
	if(guard->next != NULL){ // inserting not on the end
		inserted->next = guard->next;
		guard->next = inserted;
	}
	else{ // inserting on the end
		inserted->next = NULL;
		guard->next = inserted;
	}
}

node* insertionSort(node* guard){
	node* sorted = new node; // create sorted list
	sorted->next = NULL;

	while(guard->next != NULL){
		node* inserted = guard->next; // inserted = first node of unsorted list
		guard->next = guard->next->next; // unpin the first element 

		node* iterator = sorted; // we copy the pointer to iterate through list
		while(iterator->next != NULL && inserted->value >= iterator->next->value) // get into position
			iterator = iterator->next;
		if(iterator->next != NULL) inserted->next = iterator->next; // inserting not on the end
		else inserted->next = NULL; // inserting on the end
		iterator->next = inserted;
	}

	delete guard;
	return sorted;
}

