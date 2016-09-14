#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
	Tree::Node* root = NULL;

	Tree::insert(root, 30);
	Tree::insert(root, 3);
	Tree::insert(root, 23);
	Tree::insert(root, 24);
	Tree::insert(root, 15);
	Tree::insert(root, 1);

	Tree::Node* res = Tree::maximum(root);
	cout << res->value;
	res = Tree::predecessor(root);
	cout << endl << res->value;

	return 0;
}
