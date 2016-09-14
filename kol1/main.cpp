#include <iostream>
#include "utility.h"
#include "node.h"
#include "quick.h"
#include "insert.h"

using namespace std;

const int ILE = 25;
int main(){
	int dane[] = {2, 2, 1, 2, 1, 3, 4, 3, 4, 2, 5, 1, 2, 2, 3, 5, 5, 5, 2, 1, 2, 3, 2, 4, 4};

	node* guard = tabToList(dane, ILE);

	node* head = guard->next;

	writeList(head);
	cout << endl;

	head = quickerSort(head);
	writeList(head);

	return 0;
}

