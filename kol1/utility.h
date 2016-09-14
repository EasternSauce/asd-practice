#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
using namespace std;

void swap(int& a, int& b){
	int temp = b;
	b = a;
	a = temp;
}

int max(int a, int b){
	if(a >= b) return a;
	else return b;
}

#endif
