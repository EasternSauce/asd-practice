#include <cstddef>

namespace Tree{
	struct Node{
		int value;
		Node* parent;
		Node* left;
		Node* right;
	};

	Node* inorderWalk(){

	}

	Node* search(Node* x, int k){
		while(x != NULL && k !=  x->value){
			if(k < x->value) x = x->left;
			else x = x->right;
		}
		return x;
	}

	Node* minimum(Node* x){
		if(x == NULL) return x;
		while(x->left != NULL)
			x = x->left;
		return x;
	}

	Node* maximum(Node* x){
		if(x == NULL) return x;
		while(x->right != NULL){
			x = x->right;
		}
		return x;
	}

	Node* predecessor(Node* x){
		if(x->left != NULL) return maximum(x->left);
		Node* y = x->parent;
		while(y != NULL && x == y->left){
			x = y;
			y = y->parent;
		}
		return y;
	}

	Node* successor(Node* x){
		if(x->right != NULL) return minimum(x->right);
		Node* y = x->parent;
		while(y != NULL && x == y->right){
			x = y;
			y = y->parent;
		}
		return y;
	}

	Node* transplant(){

	}

	void insert(Node*& root, int v){
		Node* z = new Node;
		z->value = v;
		z->left = NULL;
		z->right = NULL;
		Node* y = NULL;
		Node* x = root;
		while(x != NULL){
			y = x;
			if(z->value < x->value) x = x->left;
			else x = x->right;
		}
		z->parent = y;
		if(y == NULL) root = z;
		else if(z->value < y->value) y->left = z;
		else y->right = z;
	}

	Node* remove(Node* root){

	}
};
