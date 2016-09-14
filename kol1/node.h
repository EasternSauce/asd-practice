#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct node{
	int value;
	node* next;
};

node* tabToList(int tab[], int size){
	node* guard = new node;
	guard->next = NULL;
	node* temp = guard;
	for(int i = size - 1; i >= 0; i--){
		node* temp = guard->next;
		guard->next = new node;
		guard->next->value = tab[i];
		guard->next->next = temp;
	}
	return guard;
}

void writeListGuard(node* guard){
	while(guard->next != NULL){
		guard = guard->next;
		cout << guard->value << " ";
	}
}

void writeList(node* head){
	while(head != NULL){
		cout << head->value << " ";
		head = head->next;
	}
}

void writeList(node* left, node* right){
	while(left != right){
		cout << left->value << " ";
		left = left->next;
	}
	cout << left->value;
}


#endif
