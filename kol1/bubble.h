#include <iostream>
#include "utility.h"
using namespace std;

void bubbleSort(int tab[], int size){
	for(int i = size - 1; i >= 1; i--){ // limit sorting (because the last item is alread sorted)
		for(int j = 0; j < i; j++){ // sort that part of an array
			if(tab[j] > tab[j + 1]) swap(tab[j], tab[j + 1]); // swap
		}
	}
}
